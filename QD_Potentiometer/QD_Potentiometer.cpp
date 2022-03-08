#include "QD_Potentiometer.h"

QD_Potentiometer::QD_Potentiometer(uint8_t pin, uint8_t note)
: kPin(pin), kNote(note)
{
    
}

void QD_Potentiometer::read()
{
    uint16_t current_read = analogRead(kPin);
    uint16_t read_diff = abs(pot_read - current_read);
    if (read_diff > kThres)
    {
        pot_read = current_read;
        send_midi(pot_read);
    }
}

void QD_Potentiometer::send_midi(uint16_t val)
{
    QD_MIDI::control_change(kNote, val);
    MidiUSB.flush();
    return;
}