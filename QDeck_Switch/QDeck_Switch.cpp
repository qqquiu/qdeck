#include "QDeck_Switch.h"
#include <Arduino.h>

namespace QDeck
{
    Switch::Switch(uint8_t pin)
    : m_Pin(pin)
    {
        SetDefaultState();
    }

    bool Switch::Pressed()
    {
        SetInterruptState();

        bool pressed = !digitalRead(m_Pin);
        if (pressed)
        {
            const unsigned long current_time = millis();
            if (m_DebounceTime < (current_time - m_LastPressed))
            {
                m_LastPressed = current_time;
                Interact();
            }
        }

        SetDefaultState();
        return pressed;
    }

    void Switch::SetDefaultState()
    {
        pinMode(m_Pin, OUTPUT);
        digitalWrite(m_Pin, LOW);
    }

    void Switch::SetInterruptState()
    {
        pinMode(m_Pin, INPUT_PULLUP);
    }
}