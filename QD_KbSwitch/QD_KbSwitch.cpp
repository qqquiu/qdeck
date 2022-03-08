#include "QD_KbSwitch.h"

QD_KbSwitch::QD_KbSwitch(uint8_t p, uint8_t k)
: QD_Switch { p }
, kKey { k }
{

}

void QD_KbSwitch::interact()
{
    Keyboard.press(kKey);
    //Serial.print(kKey, HEX);
    //Serial.println(" signal.");
    Keyboard.release(kKey);
}