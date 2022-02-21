#include "QDeckKeyMIDI.h"

virtual void QDeckKeyMIDI::Interact()
{
    QDeckMIDI::noteOn(_note, QDeckMIDI::MIDI_MAX);
    MidiUSB.flush();
    QDeckMIDI::noteOff(_note, QDeckMIDI::MIDI_MAX);
}