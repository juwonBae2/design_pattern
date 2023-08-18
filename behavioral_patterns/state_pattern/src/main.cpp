#include "state_pattern.hpp"
#include "state_pattern2.hpp"

void clientCodePattern1()
{
    Context *context = new Context(new ConcreteStateA);
    context->Request1();
    context->Request2();

    delete context;
}

void clientCodePattern2()
{
    Lamp lamp;
    lamp.turnOn();
    lamp.turnOff();
    lamp.turnOff(); //  램프 끄기 (이미 꺼져있음)
}

int main()
{
    clientCodePattern1();

    std::cout << "\n";

    clientCodePattern2();

    return 0;
}