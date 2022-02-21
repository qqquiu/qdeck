#ifndef QDECKMIDI_H
#define QDECKMIDI_H

#include <Arduino.h>
#include <MIDIUSB.h>

namespace QDeckMIDI
{
    const byte CHANNEL = 0;
    const byte MIDI_MIN  = 0;
    const byte MIDI_MAX  = 127;
    const int  POT_MIN = 10;
    const int  POT_MAX = 1000;

    void noteOn(byte pitch, byte velocity);
    void noteOff(byte pitch, byte velocity);
    void controlChange(uint8_t control, int value);
}

#endif