#include "QD_MIDI.h"

void QD_MIDI::note_on(byte pitch, byte velocity)
{
    midiEventPacket_t event = {0x09, 0x90 | kChannel, pitch, velocity};
    MidiUSB.sendMIDI(event);
}

void QD_MIDI::note_off(byte pitch, byte velocity)
{
    midiEventPacket_t event = {0x08, 0x80 | kChannel, pitch, velocity};
    MidiUSB.sendMIDI(event);   
}

void QD_MIDI::control_change(uint8_t control, uint16_t value)
{
    byte mappedVal = map(value, kPotMin, kPotMax, kMidiMin, kMidiMax);
    midiEventPacket_t event = {0x0B, 0xB0 | kChannel, control, mappedVal};
    MidiUSB.sendMIDI(event);
}