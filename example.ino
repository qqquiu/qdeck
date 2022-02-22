// This is an example file to walk through the creation of your main .ino file

#include <Arduino.h>                            // Always include this
#include <Keyboard.h>                           // Required to send computer keyboard signals
#include <MIDIUSB.h>                            // Required to send MIDI over USB

#include <QDeckButton_Base.h>                   // Include if using switches/buttons
#include <QDeckMIDI.h>                          // Include if using MIDI signals
#include <QDeckButton_KB.h>                     // Include if using buttons for computer keyboard signals
#include <QDeckButton_MIDI.h>                   // Include if using buttons for MIDI signals
#include <QDeckFader.h>                         // Include if using potentiometers for MIDI signals
#include <QDeckKeyManager.h>                    // Include if using switches/buttons

// WHEN USING ANY TYPE OF BUTTON FOR KEYBOARD AND/OR MIDI
// First wire all switches to a common pin, instead of Arduino's ground
// Then wire the other pin of your switch to a digital pin on your Arduino
const uint8_t common_pin = 0;                       // Set this to your common pin

// DECLARING A COMPUTER KEYBOARD BUTTON
const uint8_t kb1_pin = 4;                  
const uint8_t kb1_sig = KEY_F13;                    // Refer to Keyboard.h's documentation for the exact code you'll need

QDeckButton_KB kb1 = {kb1_pin, kb1_sig};            // Create a Keyboard button object with pin and signal parameters

// DECLARING A MIDI BUTTON
const uint8_t midi1_pin = 5;                
const uint8_t midi1_sig = 0;                        // This will send Note 0

QDeckButton_MIDI midi1 = {midi1_pin, midi1_sig};    // Create a MIDI button object with pin and signal parameters

// DECLARING A KEY MANAGER - REQUIRED FOR KEYBOARD AND/OR MIDI BUTTONS
QDeckButton_Base* but_arr[] = {&kb1, &midi1};                                 // Create a QDeckButton_Base array of pointers with the address of all button inputs
const uint8_t total_buttons = sizeof(but_arr) / sizeof(QDeckButton_Base*);   // Calculate the amount of buttons at runtime so you don't need a magic number

QDeckKeyManager key_manager = {but_arr, total_buttons, common_pin};         // Create a KeyManager object and pass the button array, total buttons and common pin.

// DECLARING A POTENTIOMETER INPUT
// The pots will NOT be wired to the common_pin of the buttons
// Instead they will be wired as usual, receiving 5V and GND from Arduino
// And sending to an analog pin for reading
const uint8_t pot1_pin = A0;                
const uint8_t pot1_sig = 10;                                // This will send Control Change on Note 10 (with velocity 0..127)

QDeckFader pot1 = {pot1_pin, pot1_sig};                     // Create a Fader object with pin and signal parameters
QDeckFader* pot_arr[] = {&pot1};                            // Then an array of pointers with the address of all pot objects

const uint8_t pots = sizeof(pot_arr) / sizeof(QDeckFader*); // Calculate the amount of pots at runtime so you don't need a magic number

void setup() {
  key_manager.Initialize();  // Needs to be called here
}

void loop()
{
  for (int i = 0; i < pots; i++)
  {
    pot_arr[i]->ReadFader();
  }
}
