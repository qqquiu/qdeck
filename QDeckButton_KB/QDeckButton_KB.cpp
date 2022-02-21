#include "QDeckButton_KB.h"

virtual void QDeckButton_KB::Interact()
{
    Keyboard.press(_key);
    Keyboard.release(_key);
}