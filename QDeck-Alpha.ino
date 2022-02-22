#include <Arduino.h>
#include <Keyboard.h>
#include <MIDIUSB.h>

#include <QDeckButton_Base.h>
#include <QDeckMIDI.h>
#include <QDeckButton_KB.h>
#include <QDeckButton_MIDI.h>
#include <QDeckFader.h>
#include <QDeckKeyManager.h>

// PINS & SIGNALS
const uint8_t PIN_KEY_1 = 4;
const uint8_t SIG_KEY_1 = KEY_F13;

const uint8_t PIN_MIDI_1 = 5;
const uint8_t SIG_MIDI_1 = 0;

const uint8_t PIN_BUS_A = A0;
const uint8_t SIG_BUS_A = 10;

// KEYBOARD & MIDI BUTTONS
QDeckButton_KB Key_1 = {PIN_KEY_1, SIG_KEY_1};
QDeckButton_MIDI Midi_1 = {PIN_MIDI_1, SIG_MIDI_1};

QDeckButton_Base* KeyInputs[] = {&Key_1, &Midi_1};

const uint8_t kCommonPin = 2;
const uint8_t kTotalKeys = sizeof(KeyInputs) / sizeof(QDeckButton_Base*);

QDeckKeyManager KeyManager = {KeyInputs, kTotalKeys, kCommonPin};

// MIDI POTS/FADERS
QDeckFader FaderA = {PIN_BUS_A, ID_BUS_A};
QDeckFader* AudioFaders[] = {&FaderA};

const uint8_t kFaderCount = sizeof(AudioBusses) / sizeof(QDeckFader*);

// SETUP & LOOP
void setup() {
  KeyManager.Initialize();
  Serial.begin(9600);
}

void loop()
{
  for (int i = 0; i < kFaderCount; i++)
  {
    AudioBusses[i]->ReadFader();
  }
}
