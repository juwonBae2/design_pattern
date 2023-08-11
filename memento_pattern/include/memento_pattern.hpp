#pragma once

#include <iostream>
#include "spdlog/fmt/fmt.h"

class Memento
{
public:
    virtual ~Memento() {}
    virtual std::string state() const = 0;
    virtual std::string getName() const = 0;
    virtual std::string date() const = 0;
};

class ConcreteMemento : public Memento
{
public:
    ConcreteMemento(std::string state) : state_(state)
    {
        this->state_ = state;
        std::time_t now = std::time(0);
        this->date_ = std::ctime(&now);
    };

    std::string state() const override{};
    std::string getName() const override{};
    std::string date() const override{};

private:
    std::string state_;
    std::string date_;
};

class Originator
{
public:
    Originator(std::string state) : state_(state)
    {
        fmt::print("Originator: My initial state is: {}\n", this->state_);
    }

    void doSomething();

    Memento *save()
    {
        return new ConcreteMemento(this->state_);
    }

private:
    std::string state_;
    std::string generateRandomString(int length){};
};