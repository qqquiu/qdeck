# About
The QDeck is a Keyboard & MIDI USB controller project. You can use these libraries to build a custom deck with the desired type and number of inputs. Switches can send keyboard signals or MIDI notes. Potentiometers only send MIDI control change signals. For MIDI usage, you will need a microcontroller with MIDI over USB support such as ATmega32u4.

While it's been mainly designed to assist with software related to live streamind and broadcasting (OBS & vMix), it can be technically used for any kind of software as long as it properly reads your desired input types.

## Stuff you can make
- Switches that sends computer keyboard signals like `F1` to `F12` or even `F13` to `F24`, essentially giving you extra hotkeys that won't interfere with your main keyboard keys
- Switches that send MIDI `Note On` / `Note Off` signals
- Rotary and slide potentiometers (faders) that send MIDI `Control Change` signals

# Usage
Refer to the [example.ino](https://github.com/matheusmeloni/QDeck/blob/main/example.ino) file for a demo simulating a device with 1 Keyboard Switch, 1 MIDI Switch and 1 MIDI Potentiometer

# Dependencies
- [MIDIUSB](https://github.com/arduino-libraries/MIDIUSB)
- [Keyboard](https://github.com/arduino-libraries/Keyboard)

# Requirements
Again, for MIDI usage, you will need a microcontroller with support for MIDI over USB. You can find this out by looking up DIY MIDI controllers online, many results list the possible chips you can use.
