#include "QD_Switch.h"

QD_Switch::QD_Switch(uint8_t pin)
: kPin(pin)
{
    set_switch_default();
}

bool QD_Switch::is_pressed()
{
    set_switch_interrupt();
    
    bool pressed = !digitalRead(kPin);

    if (pressed)
    {
        const unsigned long current_time = millis();
        if (kDebounceTime < (current_time - last_pressed))
        {
            last_pressed = current_time;
            interact();
        }
    }

    set_switch_default();

    return pressed;
}

void QD_Switch::set_switch_default()
{
    pinMode(kPin, OUTPUT);
    digitalWrite(kPin, LOW);
}

void QD_Switch::set_switch_interrupt()
{
    pinMode(kPin, INPUT_PULLUP);
}