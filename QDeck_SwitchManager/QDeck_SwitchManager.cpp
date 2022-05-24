#include "QDeck_SwitchManager.h"

namespace QDeck
{
    // Workaround code so attachInterrupt() can call function inside SwitchManager class

    SwitchManager* aux_ptr;

    static void WorkaroundInterrupt()
    {
        aux_ptr->InterruptHandler();
    }

    SwitchManager::SwitchManager(Switch* switches[], size_t switch_count, uint8_t interrupt_pin)
    : m_Switches(switches), m_SwitchCount(switch_count), m_InterruptPin(interrupt_pin)
    {
        aux_ptr = this;
        SetInterruptDefault();
        attachInterrupt(digitalPinToInterrupt(m_InterruptPin), WorkaroundInterrupt, FALLING);
    }

    void SwitchManager::InterruptHandler()
    {
        SetInterruptTriggered();
        for (size_t i = 0; i < m_SwitchCount; i++)
        {
            if (m_Switches[i]->Pressed())
                break;
        }
        SetInterruptDefault();
    }

    void SwitchManager::SetInterruptDefault()
    {
        pinMode(m_InterruptPin, INPUT_PULLUP);
    }

    void SwitchManager::SetInterruptTriggered()
    {
        pinMode(m_InterruptPin, OUTPUT);
        digitalWrite(m_InterruptPin, LOW);
    }
}
