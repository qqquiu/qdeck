// This is an example file to walk through the creation of your main .ino file

#include <Arduino.h>                            // Always include this
#include <Keyboard.h>                           // Required for QD_KbSwitch
#include <MIDIUSB.h>                            // Required for QD_MIDI, QD_MidiSwitch and QD_Potentiometer

#include <QD_Switch.h>                          // Include if using switches (keyboard or midi)
#include <QD_MIDI.h>                            // Include if using MIDI signals
#include <QD_KbSwitch.h>                        // Include if using buttons for computer keyboard signals
#include <QD_MidiSwitch.h>                      // Include if using buttons for MIDI signals
#include <QD_Potentiometer.h>                   // Include if using potentiometers/faders for MIDI signals
#include <QD_SwitchManager.h>                   // Include if using switches/buttons

// KEYBOARD/MIDI SWITCHES
const uint8_t kCommon_pin = 0;

const uint8_t k1_pin = 7;
const uint8_t k1_sig = KEY_F13; // Check Keyboard.h documentation

const uint8_t m1_pin = 8;
const uint8_t m1_sig = 10; // Note 10 in MIDI

QD_Switch* switches = {
  new QD_KbSwitch   {k1_pin, k1_sig},
  new QD_MidiSwitch {m1_pin, m1_sig}
};

const size_t kTotal_switches = GET_TOTAL_SWITCHES(switches);
QD_SwitchManager manager = {switches, kTotal_switches, kCommon_pin};

// MIDI POTENTIOMETERS/FADERS
const uint8_t p1_pin = A0;
const uint8_t p1_sig = 11; // Note 11 in MIDI

QD_Potentiometer* pots = { // You can also use typedefs QD_Pot and QD_Fader
  new QD_Potentiometer {p1_pin, p1_sig}
};

const size_t kTotal_pots = GET_TOTAL_POTS(pots);

void setup()
{

}

void loop()
{
  for (int i = 0; i < kTotal_pots; i++)
  {
    pots[i]->read();
  }
}
