#pragma once

#include <iostream>
#include "spdlog/fmt/fmt.h"

class Command
{
public:
    virtual ~Command() {}
    virtual void execute() const = 0;
};

class SimpleCommand : public Command
{
public:
    explicit SimpleCommand(std::string pay_load) : pay_load_(pay_load) {}

    void execute() const override;

private:
    std::string pay_load_;
};

class Receiver
{
public:
    void doSometing(const std::string &a);
    void doSomtingElse(const std::string &b);
};

class ComplexCommand : public Command
{
public:
    ComplexCommand(Receiver *receiver, std::string a, std::string b) : receiver_(receiver), a_(a), b_(b) {}

    void execute() const override;

private:
    Receiver *receiver_;

    std::string a_;
    std::string b_;
};

class Invoker
{
public:
    ~Invoker();

    void setOnStart(Command *command);
    void setOnFinish(Command *command);
    void doSomethingImportand();

private:
    Command *on_start_;
    Command *on_finish_;
};
