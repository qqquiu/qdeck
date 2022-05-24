#include "QDeck_Pot.h"
#include <MIDIUSB.h>
#include "../QDeck_Midi/QDeck_Midi.h"

namespace QDeck
{
    Pot::Pot(uint8_t pin, uint8_t note)
    : m_Pin(pin), m_Note(note)
    {

    }

    void Pot::Read()
    {
        uint16_t current_read = analogRead(m_Pin);
        uint16_t read_diff = abs(m_Read - current_read);
        if (read_diff > Threshold)
        {
            m_Read = current_read;
            SendMidi(m_Read);
        }
    }

    void Pot::SendMidi(uint16_t value)
    {
        QDeck_MIDI::ControlChange(m_Note, value);
        MidiUSB.flush();
    }
}