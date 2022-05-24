#include <Arduino.h>

#include <QDeck_Midi.h>
#include <QDeck_Pot.h>

const uint8_t pot_pin = 0;
const uint8_t pot_sig = 11; // note 11 in midi

// We use this to ignore readings if they are below this threshold
const uint16_t QDeck::Pot::Threshold = 10;

// There are typedefs for QDeck::Fader and QDeck::Potentiometer as well
QDeck::Pot* pots[] =
{
  new QDeck::Pot {pot_pin, pot_sig}
};

// This is defined in QDeck_Pot.h so we don't have to keep track of pots[] length
const size_t total_pots = GET_TOTAL_POTS(pots);

void setup()
{

}

void loop()
{
  for (int i = 0; i < total_pots; i++)
  {
    pots[i]->Read();
  }
}