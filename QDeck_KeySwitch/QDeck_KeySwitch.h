#ifndef QDECK_KEYSWITCH
#define QDECK_KEYSWITCH

#include "../QDeck_Switch/QDeck_Switch.h"

namespace QDeck
{
    class KeySwitch : public Switch
    {
    public: 
        KeySwitch() = delete;
        KeySwitch(uint8_t pin, uint8_t key);

        virtual void Interact() override;

    private:
        const uint8_t m_Key;
    }
}

#endif // QDECK_KEYSWITCH