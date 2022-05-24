#include <Arduino.h>
#include <Keyboard.h>
#include <MIDIUSB.h>

#include <QDeck_Switch.h>
#include <QDeck_KeySwitch.h>
#include <QDeck_Midi.h>
#include <QDeck_MidiSwitch.h>
#include <QDeck_SwitchManager.h>

// We need to have a common pin to wire all switches together. It has to be interrupt compatible
const uint8_t interrupt_pin = 0;

// Define pins and key signals for keyboard switches
const uint8_t key_pin = 7;
const uint8_t key_sig = KEY_F13; // these constants are defined in Keyboard.h

// Define pins and notes for midi switches
const uint8_t midi_pin = 8;
const uint8_t midi_sig = 10; // note 10 in midi

QDeck::Switch* switches[] = 
{
    new QDeck::KeySwitch  {key_pin, key_sig},
    new QDeck::MidiSwitch {midi_pin, midi_sig}
    // Add more switches here as desired. Because it's using the base Switch class,
    // you can mix MIDI and Keyboard switches as the manager class will call a virtual function
    // which will result in the proper subroutines being called

    // Depending on the amount of switches and the rest of your code, be wary of dynamic memory usage
};

// This is defined in QDeck_Switch.h so we don't have to keep track of switches[] length
const size_t total_switches = GET_TOTAL_SWITCHES(switches);

// Button presses will register as interrupts and will be handled by the manager class.
// No additional code is required.
QDeck::SwitchManager manager = {switches, total_switches, interrupt_pin};

void setup()
{
    
}

void loop()
{
    
}