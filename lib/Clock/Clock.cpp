/*!
 *  @file       Clock.cpp
 *  Project     Arduino BPM based Clock Generator Library
 *  @brief      A Library to implement BPM clock tick calls using hardware interruption for Arduino 168, 328, 16u4 and 32u4
 *              Derived work from mididuino MidiClock class. (c) 2008 - 2011 - Manuel Odendahl - wesen@ruinwesen.com
 *  @version    1.0
 *  @author     Romulo Silva
 *  @date       01/06/15
 *  @license    GPL v3.0 - (c) 2015 - Romulo Silva - contact@midilab.co
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Clock.h"

ClockClass::ClockClass()
{
    init();
    mode = INTERNAL_CLOCK;
    setTempo(120);
    
    onClock96PPQNCallback = NULL;
    onClock32PPQNCallback = NULL;
    onClock16PPQNCallback = NULL;
    onClockStartCallback = NULL;
    onClockStopCallback = NULL;
}

void ClockClass::init() 
{
    state = PAUSED;
    counter = 0;
    last_clock = 0;
    div96th_counter = 0;
    div32th_counter = 0;
    div16th_counter = 0;
    mod6_counter = 0;
    indiv96th_counter = 0;
    inmod6_counter = 0;
    pll_x = 220;

    //
    // Configure timers and prescale
    // ATMega128, ATMega328, AtMega16U4 and AtMega32U4
    cli();
    TCCR1A = _BV(WGM10);
    TCCR1B = _BV(CS10) | _BV(WGM12); // every cycle
    TIMSK1 |= _BV(TOIE1);
    sei();
}

uint16_t clock_diff(uint16_t old_clock, uint16_t new_clock) 
{

    if (new_clock >= old_clock)
        return new_clock - old_clock;
    else
        return new_clock + (65535 - old_clock);

}

void ClockClass::handleClock() 
{

    uint16_t cur_clock = clock;
    uint16_t diff;

    if (cur_clock > last_clock)
        diff = cur_clock - last_clock;
    else
        diff = cur_clock + (65535 - last_clock);

    last_interval = diff;
    last_clock = cur_clock;
    indiv96th_counter++;
    inmod6_counter++;

    if (inmod6_counter == 6)
        inmod6_counter = 0;

    switch (state) {

        case PAUSED:
            break;

        case STARTING:
            state = STARTED;
            break;

        case STARTED:
            if (indiv96th_counter == 2) {
                interval = diff;
            } else {
                interval = (((uint32_t)interval * (uint32_t)pll_x) + (uint32_t)(256 - pll_x) * (uint32_t)diff) >> 8;
            }
            break;

    }

}

void ClockClass::handleStart() 
{

    if (mode == EXTERNAL_CLOCK) {

        init();
        state = STARTING;
        mod6_counter = 0;
        div96th_counter = 0;
        div32th_counter = 0;
        div16th_counter = 0;
        counter = 0;

    }

}

void ClockClass::handleStop() 
{

    if (mode == EXTERNAL_CLOCK) {
        state = PAUSED;
    }

}

#define PHASE_FACTOR 16
static uint32_t phase_mult(uint32_t val) {
    return (val * PHASE_FACTOR) >> 8;
}

void ClockClass::start() 
{

    if (mode == INTERNAL_CLOCK) {

        state = STARTED;

        mod6_counter = 0;
        div96th_counter = 0;
        div32th_counter = 0;
        div16th_counter = 0;

        if (onClockStartCallback)
            onClockStartCallback();

    }

}

void ClockClass::stop()
{

    if (mode == INTERNAL_CLOCK) {

        state = PAUSED;

        if (onClockStopCallback)
            onClockStopCallback();

    }

}

void ClockClass::pause() 
{

    if (mode == INTERNAL_CLOCK) {

        if (state == PAUSED) {
            start();
        } else {
            stop();
        }

    }

}

void ClockClass::setTempo(uint16_t _tempo) 
{
    uint8_t tmp = SREG;
    cli();
    tempo = _tempo;
    interval = (uint32_t)((uint32_t)156250 / tempo) - 16;
    SREG = tmp;
    sei();
}

void ClockClass::clockMe() 
{
    if (Clock.mode == Clock.EXTERNAL_CLOCK) {
      Clock.handleClock();
    }
}

// TODO: Tap stuff
void ClockClass::tap() 
{

}

void ClockClass::handleTimerInt()  
{

    if (counter == 0) {

        counter = interval;

        if (mod6_counter == 0) {

            if (onClock16PPQNCallback)
                onClock16PPQNCallback(&div16th_counter);

            if (onClock32PPQNCallback)
                onClock32PPQNCallback(&div32th_counter);

            div16th_counter++;
            div32th_counter++;

        }

        if (mod6_counter == 3) {

            if (onClock32PPQNCallback)
                onClock32PPQNCallback(&div32th_counter);

            div32th_counter++;

        }

        div96th_counter++;
        mod6_counter++;
    
        if (mode == EXTERNAL_CLOCK) {

            uint16_t cur_clock = clock;
            uint16_t diff = clock_diff(last_clock, cur_clock);

            if ((div96th_counter < indiv96th_counter) || (div96th_counter > (indiv96th_counter + 1))) {
                div96th_counter = indiv96th_counter;
                mod6_counter = inmod6_counter;
            }
          
            if (div96th_counter <= indiv96th_counter) {

                counter -= phase_mult(diff);

            } else {

                if (counter > diff) {
                    counter += phase_mult(counter - diff);
                }

            }

        }
    
        if (onClock96PPQNCallback)
            onClock96PPQNCallback(&div96th_counter);

        if (mod6_counter == 6) {
            mod6_counter = 0;
        }

    } else {
        counter--;
    }

}
    
ClockClass Clock;

volatile uint16_t clock = 0;

//
// TIMER HANDLER INTERRUPT
//
ISR(TIMER1_OVF_vect) {

    if (Clock.state == Clock.STARTED) {
        clock++;
        Clock.handleTimerInt();
    }

}
