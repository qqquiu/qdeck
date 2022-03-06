#include "QD_Potentiometer.h"

void QD_Potentiometer::read()
{
    uint16_t currentRead = analogRead(kPin);
    uint16_t readDiff = abs(potRead - currentRead);
    if (readDiff > kThres)
    {
        potRead = currentRead;
        send_midi(potRead);
    }
}

void QD_Potentiometer::send_midi(uint16_t val)
{
    QD_MIDI::control_change(kNote, val);
    MidiUSB.flush();
    return;
}