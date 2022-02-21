#ifndef QDECKKEYMIDI_H
#define QDECKKEYMIDI_H

#include "../QDeckKeyInput_Base/QDeckKeyInput_Base.h"
#include "../QDeckMIDI/QDeckMIDI.h"

class QDeckKeyMIDI : public QDeckKeyInput_Base
{
    private:
        const uint8_t _note;

    QDeckKeyMIDI (uint8_t p, uint8_t n)
    : QDeckKeyInput_Base { p }
    , _note { n } {}

};

#endif