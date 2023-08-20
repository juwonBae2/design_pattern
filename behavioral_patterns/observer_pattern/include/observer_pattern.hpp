#pragma once

#include <iostream>
#include <vector>

class Subject;

// 3.Subscriber
class Observer
{
public:
    virtual ~Observer() = default;
    virtual void Update(Subject &) = 0;
};

// 1.Publisher
class Subject
{
public:
    virtual ~Subject() = default;
    void Attach(Observer &o) { observers.push_back(&o); }
    void Detach(Observer &o)
    {
        observers.erase(std::remove(observers.begin(), observers.end(), &o));
    }
    void Notify()
    {
        for (auto *o : observers)
        {
            o->Update(*this);
        }
    }

private:
    std::vector<Observer *> observers;
};

class ClockTimer : public Subject
{
public:
    // 2.A new event has occurred
    void SetTime(int hour, int minute, int second)
    {
        this->hour = hour;
        this->minute = minute;
        this->second = second;

        Notify();
    }

    int GetHour() const { return hour; }
    int GetMinute() const { return minute; }
    int GetSecond() const { return second; }

private:
    int hour;
    int minute;
    int second;
};

// 4.Concrete Subscribers
class DigitalClock : public Observer
{
public:
    explicit DigitalClock(ClockTimer &s) : subject(s) { subject.Attach(*this); }
    ~DigitalClock() { subject.Detach(*this); }
    void Update(Subject &theChangedSubject) override
    {
        if (&theChangedSubject == &subject)
        {
            Draw();
        }
    }

    void Draw()
    {
        int hour = subject.GetHour();
        int minute = subject.GetMinute();
        int second = subject.GetSecond();

        std::cout << "Digital time is " << hour << ":"
                  << minute << ":"
                  << second << std::endl;
    }

private:
    ClockTimer &subject;
};

// 4.Concrete Subscribers
class AnalogClock : public Observer
{
public:
    explicit AnalogClock(ClockTimer &s) : subject(s) { subject.Attach(*this); }
    ~AnalogClock() { subject.Detach(*this); }
    void Update(Subject &theChangedSubject) override
    {
        if (&theChangedSubject == &subject)
        {
            Draw();
        }
    }
    void Draw()
    {
        int hour = subject.GetHour();
        int minute = subject.GetMinute();
        int second = subject.GetSecond();

        std::cout << "Analog time is " << hour << ":"
                  << minute << ":"
                  << second << std::endl;
    }

private:
    ClockTimer &subject;
};
