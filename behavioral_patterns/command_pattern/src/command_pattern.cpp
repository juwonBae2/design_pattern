#include "command_pattern.hpp"

void SimpleCommand::execute() const
{
    fmt::print("SimpleCommand: See, I can do simple things like printing ({})\n", this->pay_load_);
}

void Receiver::doSometing(const std::string &a)
{
    fmt::print("Receiver: Working on ({}.)\n", a);
}

void Receiver::doSomtingElse(const std::string &b)
{
    fmt::print("Receiver: Also working on ({}).\n", b);
}

void ComplexCommand::execute() const
{
    fmt::print("ComplexCommand: Complex stuff should be done by a reciver object. \n");
    this->receiver_->doSometing(this->a_);
    this->receiver_->doSomtingElse(this->b_);
}

Invoker::~Invoker()
{
    delete on_start_;
    delete on_finish_;
}

void Invoker::setOnStart(Command *command)
{
    this->on_start_ = command;
}

void Invoker::setOnFinish(Command *command)
{
    this->on_finish_ = command;
}

void Invoker::doSomethingImportand()
{
    fmt::print("Invoker: Dose anybody want someting done before I begin? \n");
    if (this->on_start_)
    {
        this->on_start_->execute();
    }

    fmt::print("Invoker: ...doing something really important...\n");
    fmt::print("Invoker: Does anybody want something done after I finish?\n\n");

    if (this->on_finish_)
    {
        this->on_finish_->execute();
    }
}