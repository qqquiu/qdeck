#ifndef __QD_POTENTIOMETER_H_
#define __QD_POTENTIOMETER_H_

#include <Arduino.h>

#include "../QD_MIDI/QD_MIDI.h"

#define GET_TOTAL_POTS(pot_arr) sizeof(pot_arr) / sizeof(QD_Potentiometer*)

class QD_Potentiometer
{
    public:
        QD_Potentiometer (uint8_t p, uint8_t n) : kPin(p), kNote(n) {}

        void read();

    private:
        const uint8_t kPin;
        const uint8_t kNote;
        const uint16_t kThres = 10;
        
        uint16_t pot_read = 0;
        
        void send_midi(uint16_t);
};

typedef QD_Potentiometer QD_Pot;
typedef QD_Potentiometer QD_Fader;

#endif