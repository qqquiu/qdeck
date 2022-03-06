#ifndef __QD_MIDI_H_
#define __QD_MIDI_H_

#include <Arduino.h>
#include <MIDIUSB.h>

namespace QD_MIDI
{
    const byte kChannel = 0;
    const byte kMidiMin = 0;
    const byte kMidiMax = 127;
    const uint16_t kPotMin  = 0;
    const uint16_t kPotMax  = 1023;

    void note_on(byte, byte);
    void note_off(byte, byte);
    void control_change(uint8_t, uint16_t);
}

#endif