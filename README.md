# uMODULAR

uMODULAR is a **hardware** and **software** collection of usefull and **reusable DIY modules** focused on **audio and visual** technology usage.

The modular architecture make it easier to **create and build** your own **controller** and/or **signal processing box** for the control and/or integration of **different audio and video protocols** setups.

All the hardware and software modules are designed with interoperability in mind, so you can possibly write your self a sequencer that controls events for MIDI, OSC, CV, DMX and a mechanical device - like a robot - all together in the painless possible way.

On the roadmap, only the bold modules are avaliable for now. Keep in touch for the release of new modules and hardware schematics.

## Hardware

Physical modules released under CC-BY-SA 4.0 avaliable as Single Sided PCB to be etched at home to make your own audio/video/sensorial device controller or signal processing box.

### Shileds
The first shiled relased is for the Arduino Micro and Mini series, the project have plans to support other boards also.

**Arduino Micro and Mini 5v Compatible**

![Image of Arduino Micro and Mini uMODULAR Shiled](https://raw.githubusercontent.com/midilab/uMODULAR/master/hardware/shiled/arduino_micro_mini/umodular_shiled_amm-topview.png)

### IO Interfaces 
Input and Output interfaces to interact with the world

**FADER8**
![Image of uMODULAR Fader8](https://raw.githubusercontent.com/midilab/uMODULAR/master/hardware/fader8/umodular_fader8-topview.png)
*8 x 60mm faders module - designed for Bourns PTA6043-2015DPB103 part.*

**POT8**
![Image of uMODULAR Pot8](https://raw.githubusercontent.com/midilab/uMODULAR/master/hardware/pot8/umodular_pot8-topview.png)
*8 x potentiometers module - designed for Bourns PTV09A-4015F-B103 part. But it fits for almost all 10KB through hole potentiometer models.*

Buttons/Leds.

### Midi Interface

**Midi4**
![Image of uMODULAR Midi4](https://raw.githubusercontent.com/midilab/uMODULAR/master/hardware/midi4/umodular_midi4-topview.png)
*Common MIDI interface with support for 2 MIDI Inputs and 2 MIDI Outputs.*

### OSC Interface 
Either Ethernet or Wifi modules.

### CV Interface
8 Channels general purprose CV/GATE with 10bit DAC

### DMX Interface
On the roadmap.


## Protocol Interfaces
uMODULAR modules are made to interface with all major common protocols for audio and video on the market:

1. **MIDI**
2. OSC
3. CV
4. DMX


## Libraries
The collection of libraries make it possible to construct synthesizers, sequencers, effect box, message routers or integrate and sync your performance music setup with video, ligths, motors, sensors or whatever you feel good about using the protocolar layer of uMODULAR:

1. **Clock**: BPM based Clock Generator Library to implement BPM clock tick calls using **hardware interruption** for Arduinos based on 168, 328, 16u4 and 32u4 microcontrollers.
2. Multitrack Step Sequencer
3. Remote
4. DSPs (Harmonizer, Arppregio, Euclidian, LFO)


## Applications
Real world applications using the uMODULAR framework:

1. Event Looper
2. Harmonizer
3. Event Router

