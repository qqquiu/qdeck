#include "QDeckFaderInput.h"

void QDeckFaderInput::_SendMIDI(int read)
{
    QDeckMIDI::controlChange(_bus, read);
    MidiUSB.flush();
    return;
}

void QDeckFaderInput::ReadFader()
{
    int currentRead = analogRead(_pin);
    int readDiff = abs(_faderRead - currentRead);
    if (readDiff > _threshold)
    {
        _faderRead = currentRead;
        _SendMIDI(_faderRead);
    }
}