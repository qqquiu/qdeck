# About
A repository for different QDeck libraries you can add to your custom deck.
## What is this?
The QDeck is a MIDI & Keyboard USB controller project, using an Arduino with ATmega32u4.

While it's been mainly designed to assist in live video production work (OBS & vMix), it can be used for many cases - as long as the software has proper support, such as MIDI and proper keyboard signals.

## Stuff you can make
- Switches that sends computer keyboard signals like `F1` to `F12` or even `F13` to `F24`, essentially giving you extra hotkeys that won't interfere with your main keyboard keys
- Switches that send MIDI `Note On` / `Note Off` signals
- Rotary and slide potentiometers (faders) that send MIDI `Control Change` signals

# Usage
Refer to the [example.ino](https://github.com/matheusmeloni/QDeck/blob/main/example.ino) file for a demo simulating a device with 1 Keyboard Switch, 1 MIDI Switch and 1 MIDI Potentiometer

# Dependencies
- [MIDIUSB](https://github.com/arduino-libraries/MIDIUSB)
- [Keyboard](https://github.com/arduino-libraries/Keyboard)

# Hardware requirements
For MIDI usage, you will need Arduino chips with native MIDI over USB support.
