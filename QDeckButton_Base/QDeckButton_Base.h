#ifndef QDECKBUTTONBASE_H
#define QDECKBUTTONBASE_H

#include <Arduino.h>

class QDeckButton_Base
{
    private:
        const uint8_t _pin;

    public:
        virtual void Interact();
        uint8_t GetPin();

        QDeckButton_Base (uint8_t p) : _pin(p) {}
};

#endif