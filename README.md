# uMODULAR

A collection of **hardware schematics**, **PCBs**, and **libraries** for **real-time embedded applications** in the field of music and video.
  
![Image of umodular-v2 series](https://midilab.co/data/uploads/2018/06/umodular-v02.jpeg)
  
**Hardware:** Modules effortlessly combine to enhance and extend the capabilities of your device.  
**Firmware:** All the challenging and intricate aspects of real-time and concurrency in music or video applications are encapsulated within a safe and intuitive API via libraries.  

The framework provides multi-architecture support, allowing for seamless compilation across various microcontrollers without the need for manual adjustments or modifications. This ensures a streamlined development process and simplifies the programming and debugging tasks associated with real-time and concurrent operations.  

## Hardware

The physical modules are released under the CC-BY-SA 4.0 license and are available in Kicad format, providing electronic schematics and PCB designs for creating your own audio/video/sensorial device controller or signal processing box.  

## Protocol interfaces

The uMODULAR framework is meticulously designed to ensure seamless interoperability with a wide range of audio and video devices available on the market. Its compatibility extends to various protocols and standards, allowing integration with different devices.  
  
Avaliable Interfaces:  
  
**MIDI**  
OSC: **On roadmap**  
CV/GATE: **On roadmap**  
DMX: **On roadmap**  

## Libraries

The firmware libraries are built for the Arduino platform, with support for PlatformIO, and are compatible with various microcontroller architectures and boards, including classic AVRs and modern ARMs.  
  
**AVRs:** ATmega168, ATmega328, ATmega16u4, ATmega32u4 and ATmega2560.  
**ARMs:** ESP32, SAMD21 and All Teensy ARM microcontrollers.  
  
**Boards:** All AVR Arduino boards, All Teensy AVRs and ARMs, ESP32 based boards and Seedstudio XIAO M0.  
  
#### uCtrl

[uCtrl](https://github.com/midilab/uCtrl) is a comprehensive codebase library for the uMODULAR hardware project. It offers a driver layer for all uMODULAR modules and a user interface layer that simplifies the creation, extension, and sharing of advanced Arduino/PlatformIO applications.  
  
With uCtrl, you can achieve realtime-like functionality within the Arduino/PlatformIO ecosystem by leveraging hardware timer interruptions for precise task management. The library provides a resource-safe access through its API, ensuring efficient and reliable operation.  
  
Choose uCtrl for developing robust, portable, and high-performance musical instruments, sequencers, audio/video controllers, and other related machines on the Arduino/PlatformIO platform.  
  
#### uClock

[uClock](https://github.com/midilab/uClock) is a BPM-based Clock Generator Library provides a way to implement BPM clock tick calls using hardware interruption, ensuring the tightest and most accurate clock signal possible.  

## Applications

Real world applications using the uMODULAR framework:  

#### Aciduino V2

The project features a versatile step sequencer clone of Roland’s TB303/TR808, offering up to 16 tracks. It includes a comprehensive automation grid system for step, pattern, and mute control. The sequencer functions as a MIDI controller and incorporates an OLED display for visual feedback. Furthermore, the design is modular and allows for easy expansion with additional potentiometers, buttons, MIDI, or CV/Gate interfaces.  
  
You can download the app at [aciduino v2 repository](https://github.com/midilab/aciduino/tree/master/v2)  

## Oficial Website

You can find more informations about uMODULAR at http://midilab.co/umodular.
