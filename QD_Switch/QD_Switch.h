#ifndef __QD_SWITCH_H_
#define __QD_SWITCH_H_

#include <Arduino.h>

#define GET_TOTAL_SWITCHES(sw_arr) sizeof(sw_arr) / sizeof(QD_Switch*)

class QD_Switch
{
    public:
        QD_Switch (uint8_t);
        bool is_pressed();

    private:
        const uint8_t kPin;
        const uint8_t kDebounceTime = 100; //ms
        unsigned long last_pressed = 0;

        void set_switch_default();
        void set_switch_interrupt();

        virtual void interact() = 0;
};

#endif