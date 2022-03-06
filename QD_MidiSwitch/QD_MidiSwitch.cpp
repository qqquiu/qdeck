#include "QD_MidiSwitch.h"

void QD_MidiSwitch::interact()
{
    QD_MIDI::note_on(kNote, QD_MIDI::kMidiMax);
    MidiUSB.flush();
    QD_MIDI::note_off(kNote, QD_MIDI::kMidiMin);
    MidiUSB.flush();
}