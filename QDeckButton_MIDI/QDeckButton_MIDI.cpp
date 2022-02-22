#include "QDeckButton_MIDI.h"

void QDeckButton_MIDI::Interact()
{
    QDeckMIDI::noteOn(_note, QDeckMIDI::MIDI_MAX);
    MidiUSB.flush();
    QDeckMIDI::noteOff(_note, QDeckMIDI::MIDI_MAX);
    MidiUSB.flush();
}