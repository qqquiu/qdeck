#ifndef __QD_KBSWITCH_H_
#define __QD_KBSWITCH_H_

#include <Arduino.h>
#include <Keyboard.h>
#include "../QD_Switch/QD_Switch.h"

class QD_KbSwitch : public QD_Switch
{
    public:
        QD_KbSwitch (uint8_t p, uint8_t k)
        : QD_Switch { p }
        , kKey { k } {}

        void interact();
    
    private:
        const uint8_t kKey;
};

#endif