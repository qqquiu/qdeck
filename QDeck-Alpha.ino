#include <Arduino.h>
#include <Keyboard.h>
#include <MIDIUSB.h>

#include <QDeckButton_Base.h>
#include <QDeckMIDI.h>
#include <QDeckButton_KB.h>
#include <QDeckButton_MIDI.h>
#include <QDeckFader.h>
#include <QDeckKeyManager.h>

// KEYBOARD BUTTON SETTINGS
const uint8_t 
  PIN_KEY_1 = 4, SIG_KEY_1 = KEY_F13;

QDeckButton_KB
  Key1 = {PIN_KEY_1, SIG_KEY_1};

// MIDI BUTTON SETTINGS
const uint8_t
  PIN_MIDI_1 = 5, NOTE_MIDI_1 = 0;

QDeckButton_MIDI
  Midi1 = {PIN_MIDI_1, NOTE_MIDI_1};

// KEY MANAGER SETTINGS
QDeckButton_Base* DeckButtons[] = {&Key1, &Midi1};

const uint8_t kCommonPin = 2;
const uint8_t kTotalKeys = sizeof(DeckButtons) / sizeof(QDeckButton_Base*);

QDeckKeyManager KeyManager = {DeckButtons, kTotalKeys, kCommonPin};

// AUDIO & FADER SETTINGS
const uint8_t
  PIN_BUS_A = A0, ID_BUS_A = 10;

QDeckFader 
  FaderA = {PIN_BUS_A, ID_BUS_A};

QDeckFader *AudioBusses[] = {&FaderA};

const uint8_t BUS_COUNT = sizeof(AudioBusses) / sizeof(QDeckFader*);

void testfunc()
{
  //Serial.println("INTERRUPT IN TEST FUNC");
}

void setup() {
  KeyManager.Initialize();
  Serial.begin(9600);
  //attachInterrupt(digitalPinToInterrupt(kCommonPin), testfunc, FALLING);
}

void loop()
{
  for (int i = 0; i < BUS_COUNT; i++)
  {
    AudioBusses[i]->ReadFader();
  }
}
