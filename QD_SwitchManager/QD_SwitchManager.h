#ifndef __QD_SWITCHMANAGER_H_
#define __QD_SWITCHMANAGER_H_

#include <Arduino.h>

#include "../QD_Switch/QD_Switch.h"

class QD_SwitchManager
{
    public:
        QD_SwitchManager(QD_Switch*[], size_t, uint8_t);

        void interrupt_handler();

    private:
        QD_Switch** kInputs;
        const uint8_t kTotalKeys;
        const uint8_t kInterruptPin;

        void set_interrupt_default();
        void set_interrupt_triggered();
};

#endif