#ifndef QDECKMIDI_H
#define QDECKMIDI_H

#include <Arduino.h>
#include <MIDIUSB.h>

namespace QDeckMIDI
{
    const byte CHANNEL  = 0;
    const byte MIDI_MIN = 0b00000000;
    const byte MIDI_MAX = 0b10000000; // 127
    const int  POT_MIN  = 0b0000000000;
    const int  POT_MAX  = 0b1111111111; // 1023

    void noteOn(byte pitch, byte velocity);
    void noteOff(byte pitch, byte velocity);
    void controlChange(uint8_t control, int value);
}

#endif