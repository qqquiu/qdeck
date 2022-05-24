#ifndef QDECK_SWITCHMANAGER
#define QDECK_SWITCHMANAGER

#include <Arduino.h>
#include "../QDeck_Switch/QDeck_Switch.h"

namespace QDeck
{
    class SwitchManager
    {
    public:
        SwitchManager() = delete;
        SwitchManager(Switch* switches[], size_t switch_count, uint8_t interrupt_pin);

        void InterruptHandler();

    private:
        Switch** m_Switches;
        const uint8_t m_SwitchCount;
        const uint8_t m_InterruptPin;

        void SetInterruptDefault();
        void SetInterruptTriggered();
    };
}

#endif // QDECK_SWITCHMANAGER