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
        QDeckButton_Base** _inputs;
        
        void ResetCommon();
        //void ResetKeys(); // might be useless
        void ResetKeys(int);
    
    public:
        void Test();
        void Initialize();
        void KeyInterrupt(); // needs to be public so it can be called by the workaround function in respective .cpp

    QDeckKeyManager (QDeckButton_Base** arr, uint8_t in, uint8_t com)
    : _totalKeys(in), _commonPin(com)
    {
        _inputs = (QDeckButton_Base**)malloc(_totalKeys * sizeof(QDeckButton_Base*));
        for (size_t i = 0; i < _totalKeys; i++)
        {
            _inputs[i] = arr[i];
        }
    }
    /*
    don't know how this is going to work, somehow we need to pass the
    QDeckButton_Base array from the main program, which contains
    references to QDeckButton_KB and QDeckButton_MIDI objects
    to this class constructor so we keep working with pointers
    */ 
};

#endif