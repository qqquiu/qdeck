#include "QDeckFader.h"

void QDeckFader::_SendMIDI(int read)
{
    QDeckMIDI::controlChange(_bus, read);
    MidiUSB.flush();
    return;
}

void QDeckFader::ReadFader()
{
    int currentRead = analogRead(_pin);
    int readDiff = abs(_faderRead - currentRead);
    if (readDiff > _threshold)
    {
        _faderRead = currentRead;
        _SendMIDI(_faderRead);
    }
}