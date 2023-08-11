#include "memento_pattern.hpp"

std::string ConcreteMemento::state() const
{
    return this->state_;
}

std::string ConcreteMemento::getName() const
{
    return this->date_ + " / (" + this->state_.substr(0, 9) + "...)";
}

std::string ConcreteMemento::date() const
{
    return this->date_;
}

std::string Originator::generateRandomString(int length)
{
    length = 10;

    char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    int stringLength = sizeof(alphanum) - 1;

    std::string random_string;
    for (int i = 0; i < length; i++)

    {
        random_string += alphanum[std::rand() % stringLength];
    }
    return random_string;
}

void Originator::doSomething()
{
    fmt::print("Originator: I'm doing something important.\n");
    this->state_ = this->generateRandomString(30);
    fmt::print("Originator: and my state has changed to: {}\n", this->state_);
}
