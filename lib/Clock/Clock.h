/*!
 *  @file       Clock.h
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

#ifndef CLOCK_H__
#define CLOCK_H__

#include <Arduino.h>
#include <inttypes.h>

class ClockClass {

    public:

        void (*onClock96PPQNCallback)(uint32_t * tick);
        void (*onClock32PPQNCallback)(uint32_t * tick);
        void (*onClock16PPQNCallback)(uint32_t * tick);
        void (*onClockStartCallback)();
        void (*onClockStopCallback)();

        uint32_t div96th_counter;
        uint32_t div32th_counter;
        uint32_t div16th_counter;
        uint8_t mod6_counter;
        uint8_t inmod6_counter;
        uint16_t interval;
        uint16_t counter;
        uint16_t last_clock;
        uint16_t last_interval;
        uint32_t indiv96th_counter;
        uint16_t pll_x;
        uint16_t tempo;

        enum {
            PAUSED = 0,
            STARTING,
            STARTED
        } state;

        enum {
            OFF = 0,
            INTERNAL_CLOCK,
            EXTERNAL_CLOCK
        } mode;

        ClockClass();

        void setClock96PPQNOutput(void (*callback)(uint32_t * tick)) {
            onClock96PPQNCallback = callback;
        }

        void setClock32PPQNOutput(void (*callback)(uint32_t * tick)) {
            onClock32PPQNCallback = callback;
        }

        void setClock16PPQNOutput(void (*callback)(uint32_t * tick)) {
            onClock16PPQNCallback = callback;
        }

        void setOnClockStartOutput(void (*callback)()) {
            onClockStartCallback = callback;
        }

        void setOnClockStopOutput(void (*callback)()) {
            onClockStopCallback = callback;
        }

        void init();
        void handleClock();
        void handleStart();
        void handleStop();
        void handleTimerInt();
        void start();
        void stop();
        void pause();
        void setTempo(uint16_t tempo);
        uint16_t getTempo();

        // External timming control
        void clockMe();
        void tap();
};

extern ClockClass Clock;

extern "C" {
extern volatile uint16_t clock;
}

#endif /* CLOCK_H__ */

