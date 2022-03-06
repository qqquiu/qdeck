#ifndef __QD_SWITCH_H_
#define __QD_SWITCH_H_

#include <Arduino.h>

class QD_Switch
{
    public:
        QD_Switch (uint8_t);
        bool is_pressed();

    private:
        const uint8_t kPin;

        void set_switch_default();
        void set_switch_read();
        virtual void interact();
};

#endif