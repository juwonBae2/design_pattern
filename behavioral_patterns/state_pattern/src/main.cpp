#include "state_patten.hpp"

void ClientCode()
{
    Context *context = new Context(new ConcreteStateA);
    context->Request1();
    context->Request2();
    delete context;
}

int main()
{
    ClientCode();
    return 0;
}