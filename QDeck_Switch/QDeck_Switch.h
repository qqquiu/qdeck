#ifndef QDECK_SWITCH
#define QDECK_SWITCH

#define GET_TOTAL_SWITCHES(arr) sizeof(arr) / sizeof(QDeck::Switch*)

namespace QDeck
{
    class Switch
    {
    public:
        Switch() = delete;
        Switch (uint8_t pin);
        bool Pressed();

    private:
        const uint8_t m_Pin;
        const uint8_t m_DebounceTime = 100; //ms
        unsigned long m_LastPressed = 0;

        void SetDefaultState();
        void SetInterruptState();

        virtual void Interact() = 0;
    };
}

#endif // QDECK_SWITCH