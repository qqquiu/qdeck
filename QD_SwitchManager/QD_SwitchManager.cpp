#include "QD_SwitchManager.h"

// Workaround code so attachInterrupt() can call a function inside the SwitchManager class

QD_SwitchManager* auxPtr;

static void workaround_interrupt()
{
    auxPtr->interrupt_handler();
}

// QD_SwitchManager member functions from now on

QD_SwitchManager::QD_SwitchManager(QD_Switch* arr[], size_t total, uint8_t interrupt)
: kInputs(arr), kTotalKeys(total), kInterruptPin(interrupt)
{
    auxPtr = this;
    uint8_t common = digitalPinToInterrupt(kInterruptPin);
    set_interrupt_default();
    attachInterrupt(common, workaround_interrupt, FALLING);
}

void QD_SwitchManager::interrupt_handler()
{
    if ( kDebounceTime < (millis() - lastPressed) )
    {
        lastPressed = millis();
        set_interrupt_read();
        for (size_t i = 0; i < kTotalKeys; i++)
        {
            if (kInputs[i]->is_pressed()) break;
        }
        set_interrupt_default();
    }
}

void QD_SwitchManager::set_interrupt_default()
{
    pinMode(kInterruptPin, INPUT_PULLUP);
}

void QD_SwitchManager::set_interrupt_read()
{
    pinMode(kInterruptPin, OUTPUT);
    digitalWrite(kInterruptPin, LOW);
}