#include "QD_MidiSwitch.h"

QD_MidiSwitch::QD_MidiSwitch(uint8_t p, uint8_t k)
: QD_Switch { p }
, kNote { k }
{

}

void QD_MidiSwitch::interact()
{
    QD_MIDI::note_on(kNote, QD_MIDI::kMidiMax);
    MidiUSB.flush();
    QD_MIDI::note_off(kNote, QD_MIDI::kMidiMin);
    MidiUSB.flush();
}