#ifndef QDECKBUTTONKB_H
#define QDECKBUTTONKB_H

#include "../QDeckButton_Base/QDeckButton_Base.h"
#include <Keyboard.h>

class QDeckButton_KB : public QDeckButton_Base
{
    private:
        const uint8_t _key;

    QDeckButton_KB (uint8_t p, uint8_t k)
    : QDeckButton_Base { p }
    , _key { k } {}
};

#endif