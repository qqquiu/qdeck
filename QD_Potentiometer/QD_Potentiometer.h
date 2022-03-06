#ifndef __QD_POTENTIOMETER_H_
#define __QD_POTENTIOMETER_H_

#include <Arduino.h>
#include "../QD_MIDI/QD_MIDI.h"

class QD_Potentiometer
{
    public:
        QD_Potentiometer (uint8_t p, uint8_t n) : kPin(p), kNote(n) {}

        void read();

    private:
        const uint8_t kPin;
        const uint8_t kNote;
        const uint8_t kThres = 10;
        uint16_t potRead = 0;
        
        void send_midi(uint16_t);
};

typedef QD_Potentiometer QD_Pot;
typedef QD_Potentiometer QD_Fader;

#endif