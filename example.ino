// This is an example file to walk through the creation of your main .ino file

#include <Arduino.h>                            // Always include this
#include <Keyboard.h>                           // Required to send computer keyboard signals
#include <MIDIUSB.h>                            // Required to send MIDI over USB

#include <QD_Switch.h>                          // Include if using switches (keyboard or midi)
#include <QD_MIDI.h>                            // Include if using MIDI signals
#include <QD_KbSwitch.h>                        // Include if using buttons for computer keyboard signals
#include <QD_MidiSwitch.h>                      // Include if using buttons for MIDI signals
#include <QD_Potentiometer.h>                   // Include if using potentiometers/faders for MIDI signals
#include <QD_SwitchManager.h>                   // Include if using switches/buttons

// WHEN USING ANY TYPE OF SWITCH FOR KEYBOARD AND/OR MIDI
const uint8_t common_pin = 0;

const uint8_t k1_pin = 7;
const uint8_t k1_sig = KEY_F13; // Read Keyboard.h documentation

const uint8_t m1_pin = 8;
const uint8_t m1_sig = 10; // Note 10 in MIDI

QD_Switch* switches = {
  new QD_KbSwitch   {k1_pin, k1_sig},
  new QD_MidiSwitch {m1_pin, m1_sig}
};

const uint8_t total_switches = sizeof(switches) / sizeof(QD_Switch*);

QD_SwitchManager Manager = {switches, total_switches, common_pin};

// WHEN USING POTENTIOMETERS OR FADERS
const uint8_t p1_pin = A0;
const uint8_t p1_sig = 11; // Note 11 in MIDI

// You can alternatively use the typedefs QD_Pot or QD_Fader for better readability
QD_Potentiometer* pots = {
  new QD_Potentiometer {p1_pin, p1_sig}
};

const uint8_t total_pots = sizeof(pots) / sizeof(QD_Potentiometer*);

void setup()
{

}

void loop()
{
  for (int i = 0; i < total_pots; i++)
  {
    pots[i]->read();
  }
}