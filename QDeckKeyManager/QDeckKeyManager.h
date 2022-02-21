#ifndef QDECKKEYMANAGER_H
#define QDECKKEYMANAGER_H

#include <Arduino.h>
#include "../QDeckButton_Base/QDeckButton_Base.h"
#include "../QDeckButton_KB/QDeckButton_KB.h"
#include "../QDeckButton_MIDI/QDeckButton_MIDI.h"

class QDeckKeyManager
{
    private:
        const uint8_t _commonPin;
        const uint8_t _totalKeys;
        const uint8_t _debounceTime = 25;
        unsigned long _lastPressed = 0;
        QDeckButton_Base * _inputs;
        
        void ResetCommon();
        void ResetKeys(); // might be useless
        void ResetKeys(int);
        void KeyInterrupt(); // might need to be public depending on how Arduino's attachInterrupt() works
    
    public:
        void Initialize();

    QDeckKeyManager (QDeckKeyInput_Base * arr, uint8_t, i, uint8_t c)
    : _inputs(arr), _totalKeys(i), _commonPin(c) {}
    /*
    don't know how this is going to work, somehow we need to pass the
    QDeckButton_Base array from the main program, which contains
    references to QDeckButton_KB and QDeckButton_MIDI objects
    to this class constructor so we keep working with pointers
    */ 
};

#endif