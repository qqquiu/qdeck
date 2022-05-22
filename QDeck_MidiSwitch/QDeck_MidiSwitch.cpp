#include "QDeck_MidiSwitch.h"
#include "../QDeck_Midi/QDeck_Midi.h"
#include <MIDIUSB.h>

namespace QDeck
{
    MidiSwitch::MidiSwitch(uint8_t pin, uint8_t note)
    : Switch(pin), m_Note(note)
    {

    }

    void MidiSwitch::Interact()
    {
        QDeck_MIDI::NoteOn(m_Note, QDeck_MIDI::k_MidiMax);
        MidiUSB.flush();
        QDeck_MIDI::NoteOff(m_Note, QDeck_MIDI::k_MidiMin);
        MidiUSB.flush();
    }
}