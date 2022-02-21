#include <Arduino.h>
#include <MIDIUSB.h>

#include <QDeckMIDI.h>
#include <QDeckFader.h>

// AUDIO & FADER SETTINGS
const uint8_t
  PIN_BUS_A = A0, ID_BUS_A = 10,
  PIN_BUS_B = A1, ID_BUS_B = 11,
  PIN_BUS_C = A2, ID_BUS_C = 12,
  PIN_BUS_D = A3, ID_BUS_D = 13,
  PIN_BUS_M = A4, ID_BUS_M = 19;

QDeckFader 
  FaderA = {PIN_BUS_A, ID_BUS_A},
  FaderB = {PIN_BUS_B, ID_BUS_B},
  FaderC = {PIN_BUS_C, ID_BUS_C},
  FaderD = {PIN_BUS_D, ID_BUS_D},
  FaderM = {PIN_BUS_M, ID_BUS_M};

QDeckFader *AudioBusses[] = {&FaderA, &FaderB, &FaderC, &FaderD, &FaderM};

const uint8_t BUS_COUNT = sizeof(AudioBusses) / sizeof(QDeckFader*);

void setup() {
  Serial.begin(9600);
}

void loop()
{
  for (int i = 0; i < BUS_COUNT; i++)
  {
    AudioBusses[i]->ReadFader();
  }
}
