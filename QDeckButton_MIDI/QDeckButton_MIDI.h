#ifndef QDECKBUTTONMIDI_H
#define QDECKBUTTONMIDI_H

#include "../QDeckButton_Base/QDeckButton_Base.h"
#include "../QDeckMIDI/QDeckMIDI.h"

class QDeckButton_MIDI : public QDeckButton_Base
{
    private:
        const uint8_t _note;
    
    public:
        virtual void Interact();

    QDeckButton_MIDI (uint8_t p, uint8_t n)
    : QDeckButton_Base { p }
    , _note { n } {}

};

#endif