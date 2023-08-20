#include "observer_pattern.hpp"

int main()
{
    ClockTimer timer;

    DigitalClock digitalClock(timer);
    AnalogClock analogClock(timer);

    timer.SetTime(14, 41, 36);

    timer.SetTime(14, 41, 45);
}