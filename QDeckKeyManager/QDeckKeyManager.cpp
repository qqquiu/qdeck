#include "QDeckKeyManager.h"

void QDeckKeyManager::Initialize()
// Set pins to their default values and attach an interrupt to _commonPin
{
    ResetKeys(_totalKeys);
    attachInterrupt(digitalPinToInterrupt(_commonPin), KeyInterrupt, FALLING);
}

void QDeckKeyManager::ResetCommon()
{
    pinMode(_commonPin, INPUT_PULLUP);
}

void QDeckKeyManager::ResetKeys()
// This is probably useless and might be deleted soon
{
    ResetCommon();

    for (int i = 0; i < _totalKeys, i++)
    {
        pinMode(_inputs[i].GetPin(), OUTPUT);
        digitalWrite(_inputs[i].GetPin(), LOW);
    }
}

void QDeckKeyManager::ResetKeys(int i)
// Loop through inputs and set their pints to OUTPUT, 0
{
    ResetCommon();

    while (i => 0)
    {
        pinMode(_inputs[i].GetPin(), OUTPUT);
        digitalWrite(_inputs[i].GetPin(), LOW);
        i--;
    }
}

void QDeckKeyManager::KeyInterrupt()
/*
If a short is detected between any input with _commonPin,
loop through inputs and set pins to INPUT_PULLUP, to detect which
input has caused the interrupt, then call Interact() on that input.
*/
{
    if ( millis() - _lastPressed < _debounceTime) return;
    _lastPressed = millis();

    pinMode(_commonPin, OUTPUT);
    digitalWrite(_commonPin, LOW);

    for (int i = 0; i < _totalKeys; i++)
    {
        pinMode(_inputs[i].GetPin(), INPUT_PULLUP);

        if (!digitalRead(_inputs[i].GetPin()))
        {
            _inputs[i].Interact();
            ResetKeys(i);
        }
    }
}