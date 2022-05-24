#ifndef QDECK_MIDISWITCH
#define QDECK_MIDISWITCH

#include "../QDeck_Switch/QDeck_Switch.h"

namespace QDeck
{
    class MidiSwitch : public Switch
    {
    public:
        MidiSwitch() = delete;
        MidiSwitch(uint8_t pin, uint8_t note);

        virtual void Interact() override;

    private:
        const uint8_t m_Note;
    };
}

#endif // QDECK_MIDISWITCH