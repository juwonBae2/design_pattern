#include <iostream>

// ConcreteState
enum class LampState
{
    Off,
    On
};

// Context
class Lamp
{
public:
    Lamp() : currentState(LampState::Off) {}

    void setState(LampState newState)
    {
        currentState = newState;
    }

    // ConcreteState state
    void turnOn()
    {
        if (currentState == LampState::Off)
        {
            std::cout << "Turn on the lamp." << std::endl;
            setState(LampState::On);
        }
        else
        {
            std::cout << "It's already on." << std::endl;
        }
    }

    // ConcreteState state
    void turnOff()
    {
        if (currentState == LampState::On)
        {
            std::cout << "Turn off the lamp." << std::endl;
            setState(LampState::Off);
        }
        else
        {
            std::cout << "It's already turned off." << std::endl;
        }
    }

private:
    LampState currentState;
};