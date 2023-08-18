#pragma once

#include <iostream>
#include <typeinfo>

class Context;

class State
{
protected:
    Context *context_;

public:
    virtual ~State()
    {
    }

    void set_context(Context *context)
    {
        this->context_ = context;
    }

    virtual void Handle1() = 0;
    virtual void Handle2() = 0;
};

class Context
{
private:
    State *state_;

public:
    Context(State *state) : state_(nullptr)
    {
        this->TransitionTo(state);
    }
    ~Context()
    {
        delete state_;
    }

    void TransitionTo(State *state)
    {
        std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
        if (this->state_ != nullptr)
            delete this->state_;
        this->state_ = state;
        this->state_->set_context(this);
    }

    void Request1()
    {
        this->state_->Handle1();
    }

    void Request2()
    {
        this->state_->Handle2();
    }
};

class ConcreteStateA : public State
{
public:
    void Handle1() override;

    void Handle2() override
    {
        std::cout << "ConcreteStateA handles request2.\n";
    }
};

class ConcreteStateB : public State
{
public:
    void Handle1() override
    {
        std::cout << "ConcreteStateB handles request1.\n";
    }
    void Handle2() override
    {
        std::cout << "ConcreteStateB handles request2.\n";
        std::cout << "ConcreteStateB wants to change the state of the context.\n";
        this->context_->TransitionTo(new ConcreteStateA);
    }
};

void ConcreteStateA::Handle1()
{
    {
        std::cout << "ConcreteStateA handles request1.\n";
        std::cout << "ConcreteStateA wants to change the state of the context.\n";

        this->context_->TransitionTo(new ConcreteStateB);
    }
}
