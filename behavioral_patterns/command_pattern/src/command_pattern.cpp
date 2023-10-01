#include "command_pattern.hpp"

void SimpleCommand::execute() const
{
    std::cout << "SimpleCommand: See, I can do simple things like printing ({})\n"
              << this->pay_load_ << std::endl;
}

void Receiver::doSometing(const std::string &a)
{
    std::cout << "Receiver: Working on ({}.)\n"
              << a << std::endl;
}

void Receiver::doSomtingElse(const std::string &b)
{
    std::cout << "Receiver: Also working on ({}).\n"
              << b << std::endl;
}

void ComplexCommand::execute() const
{
    std::cout << "ComplexCommand: Complex stuff should be done by a reciver object. \n"
              << std::endl;
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
    std::cout << "Invoker: Dose anybody want someting done before I begin? \n"
              << std::endl;
    if (this->on_start_)
    {
        this->on_start_->execute();
    }

    std::cout << "Invoker: ...doing something really important...\n"
              << std::endl;
    std::cout << "Invoker: Does anybody want something done after I finish?\n\n"
              << std::endl;

    if (this->on_finish_)
    {
        this->on_finish_->execute();
    }
}