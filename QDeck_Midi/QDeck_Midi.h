#ifndef QDECK_MIDI
#define QDECK_MIDI

namespace QDeck_MIDI
{
    const byte k_Channel    = 0;
    const byte k_MidiMin    = 0;
    const byte k_MidiMax    = 127;
    const uint16_t k_PotMin = 0;
    const uint16_t k_PotMax = 1023;

    void NoteOn(uint8_t note, uint8_t velocity);
    void NoteOff(uint8_t note, uint8_t velocity);
    void ControlChange(uint8_t note, uint16_t value);
}

#endif // QDECK_MIDI