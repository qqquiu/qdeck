#include "QDeckMIDI.h"

void QDeckMIDI::noteOn(byte pitch, byte velocity)
{
    midiEventPacket_t event = {0x09, 0x90 | CHANNEL, pitch, velocity};
    MidiUSB.sendMIDI(event);
}

void QDeckMIDI::noteOff(byte pitch, byte velocity)
{
    midiEventPacket_t event = {0x08, 0x80 | CHANNEL, pitch, velocity};
    MidiUSB.sendMIDI(event);   
}

void QDeckMIDI::controlChange(uint8_t control, int value)
{
    byte mappedVal = map(value, POT_MIN, POT_MAX, MIDI_MIN, MIDI_MAX);
    midiEventPacket_t event = {0x0B, 0xB0 | CHANNEL, control, mappedVal};
    MidiUSB.sendMIDI(event);
}