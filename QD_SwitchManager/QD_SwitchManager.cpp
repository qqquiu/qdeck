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
    set_interrupt_default();
    attachInterrupt(digitalPinToInterrupt(kInterruptPin), workaround_interrupt, FALLING);
}

void QD_SwitchManager::interrupt_handler()
{
    set_interrupt_triggered();
    for (size_t i = 0; i < kTotalKeys; i++)
    {
        if (kInputs[i]->is_pressed()) break;
    }
    set_interrupt_default();
}

void QD_SwitchManager::set_interrupt_default()
{
    pinMode(kInterruptPin, INPUT_PULLUP);
}

void QD_SwitchManager::set_interrupt_triggered()
{
    pinMode(kInterruptPin, OUTPUT);
    digitalWrite(kInterruptPin, LOW);
}
