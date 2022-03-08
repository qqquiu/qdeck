#ifndef __QD_KBSWITCH_H_
#define __QD_KBSWITCH_H_

#include <Arduino.h>
#include <Keyboard.h>

#include "../QD_Switch/QD_Switch.h"

class QD_KbSwitch : public QD_Switch
{
    public:
        QD_KbSwitch (uint8_t, uint8_t);

        virtual void interact() override;
    
    private:
        const uint8_t kKey;
};

#endif