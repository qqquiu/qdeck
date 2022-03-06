#include "QD_KbSwitch.h"

void QD_KbSwitch::interact()
{
    Keyboard.press(kKey);
    Serial.print(kKey, HEX);
    Serial.println(" signal.");
    Keyboard.release(kKey);
}