#include "QD_Switch.h"

QD_Switch::QD_Switch(uint8_t pin)
: kPin(pin)
{
    set_switch_default();
}

bool QD_Switch::is_pressed()
{
    set_switch_read();
    
    bool pressed = !digitalRead(kPin);
    if (pressed) interact();

    set_switch_default();

    return pressed;
}

void QD_Switch::interact() {}

void QD_Switch::set_switch_default()
{
    pinMode(kPin, OUTPUT);
    digitalWrite(kPin, LOW);
}

void QD_Switch::set_switch_read()
{
    pinMode(kPin, INPUT_PULLUP);
}