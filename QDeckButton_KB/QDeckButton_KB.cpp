#include "QDeckButton_KB.h"

void QDeckButton_KB::Interact()
{
    Keyboard.press(_key);   
    Keyboard.release(_key);
}