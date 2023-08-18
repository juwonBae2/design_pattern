#pragma once

#include <iostream>

#include <iostream>

// Subject interface
class Subject
{
public:
    virtual void request() const = 0;
};

// RealSubject class
class RealSubject : public Subject
{
public:
    void request() const override
    {
        std::cout << "RealSubject: Handling request.\n";
    }
};

// Proxy class
class Proxy : public Subject
{
private:
    RealSubject *real_subject_;

    bool checkAccess() const
    {
        std::cout << "Proxy: Checking access prior to firing a real request.\n";
        return true;
    }

    void logAccess() const
    {
        std::cout << "Proxy: Logging the time of request.\n";
    }

public:
    Proxy(RealSubject *real_subject) : real_subject_(real_subject) {}

    void request() const override
    {
        if (this->checkAccess())
        {
            this->real_subject_->request();
            this->logAccess();
        }
    }
};