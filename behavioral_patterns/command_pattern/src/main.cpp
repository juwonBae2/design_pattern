#include "command_pattern.hpp"

int main()
{
    Invoker *invoker = new Invoker;
    invoker->setOnStart(new SimpleCommand("Hello!"));

    Receiver *receiver = new Receiver;
    invoker->setOnFinish(new ComplexCommand(receiver, "Send email", "Save report"));
    invoker->doSomethingImportand();

    delete invoker;
    delete receiver;

    return 0;
}