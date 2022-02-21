#ifndef QDECKFADERINPUT_H
#define QDECKFADERINPUT_H

#include <Arduino.h>
#include "../QDeckMIDI/QDeckMIDI.h"

class QDeckFaderInput
{
    private:
        const uint8_t _pin;
        const uint8_t _bus;
        const int _threshold = 10;
        int _faderRead = 0;
        
        void _SendMIDI(int read);
    public:
        void ReadFader();

        QDeckFaderInput (uint8_t p, uint8_t bus) : _pin(p), _bus(bus)
        {}
};

#endif