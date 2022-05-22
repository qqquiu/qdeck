#ifndef QDECK_POT
#define QDECK_POT

#include <Arduino.h>

#define GET_TOTAL_POTS(arr) sizeof(arr) / sizeof(QDeck::Pot*)

namespace QDeck
{
    class Pot
    {
    public:
        Pot() = delete;
        Pot(uint8_t pin, uint8_t note);

        void Read();

    private:
        const uint8_t m_Pin;
        const uint8_t m_Note;
        const uint16_t m_Threshold;

        uint16_t m_Read;

        void SendMidi(uint16_t value);
    }

    typedef Pot Potentiometer;
    typedef Pot Fader;
}

#endif // QDECK_POT