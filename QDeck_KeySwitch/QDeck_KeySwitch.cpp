#include "QDeck_KeySwitch.h"
#include <Keyboard.h>

namespace QDeck
{
    KeySwitch::KeySwitch(uint8_t pin, uint8_t key)
    : Switch(pin), m_Key(key)
    {

    }

    void KeySwitch::Interact()
    {
        Keyboard.press(m_Key);
        Keyboard.release(m_Key);
    }
}