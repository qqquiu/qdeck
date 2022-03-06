#ifndef __QD_MIDISWITCH_H_
#define __QD_MIDISWITCH_H_

#include <Arduino.h>
#include "../QD_Switch/QD_Switch.h"
#include "../QD_MIDI/QD_MIDI.h"

class QD_MidiSwitch : public QD_Switch
{
    public:
        QD_MidiSwitch (uint8_t p, uint8_t n)
        : QD_Switch { p }
        , kNote { n } {}

        void interact();

    private:
        const uint8_t kNote;
};

#endif