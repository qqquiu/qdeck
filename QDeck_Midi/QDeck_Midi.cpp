#include "QDeck_Midi.h"
#include <MIDIUSB.h>

namespace QDeck_MIDI
{
    void NoteOn(uint8_t note, uint8_t velocity)
    {
        midiEventPacket_t event = {0x09, 0x90 | k_Channel, note, velocity};
        MidiUSB.sendMIDI(event);
    }

    void NoteOff(uint8_t note, uint8_t velocity)
    {
        midiEventPacket_t event = {0x08, 0x80 | k_Channel, note, velocity};
        MidiUSB.sendMIDI(event);
    }

    void ControlChange(uint8_t note, uint16_t value)
    {
        uint8_t mapped_val = map(value, k_PotMin, k_PotMax, k_MidiMin, k_MidiMax);
        midiEventPacket_t event = {0x0B, 0xB0 | k_Channel, note, mapped_val};
        MidiUSB.sendMIDI(event);
    }
}