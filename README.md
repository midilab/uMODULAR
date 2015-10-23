# uMODULAR

uMODULAR is a **hardware** and **software** modular environment for **audio and visual** controller projects.
A collection of usefull and **reusable modules** to be combined for a **fast development** of your audio/video controller project.

On the roadmap, only the bold modules are avaliable for now. Keep in touch for the release of new modules and hardware schematics.

## Hardware
Physical modules released under CC-BY-SA avaliable as Single Sided PCB to be etched at home to make your own audio/video/sensorial device controller:

### Shileds
The first shiled relased is for the Arduino Micro and Mini series, the project have plans to support other boards also.

**Arduino Micro and Mini 5v Compatible**

![Image of Arduino Micro and Mini uMODULAR Shiled](https://raw.githubusercontent.com/midilab/uMODULAR/master/hardware/shiled/arduino_micro_mini/umodular_shiled_amm-topview.png)

### IO Interfaces 
Input and Output interfaces to interact with the world

**Fader8** 8 x 60mm faders module - designed for Bourns PTA6043-2015DPB103 part.
![Image of uMODULAR Fader8](https://raw.githubusercontent.com/midilab/uMODULAR/master/hardware/fader8/umodular_fader8-topview.png)

**Pot8** 8 x potentiometers module - designed for best fit on Bourns PTV09A-4015F-B103 part. But it fits for almost all 10KB potentiometer models.
![Image of uMODULAR Pot8](https://raw.githubusercontent.com/midilab/uMODULAR/master/hardware/pot8/umodular_pot8-topview.png)

Buttons/Leds.

### Midi Interface
Common MIDI interface with support for 2 MIDI Inputs and 2 MIDI Outputs.

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

