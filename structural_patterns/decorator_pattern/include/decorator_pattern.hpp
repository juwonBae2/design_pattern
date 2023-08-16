#pragma once

#include <iostream>
#include <string>

// 컴포넌트
class Coffee
{
public:
    virtual ~Coffee() {}
    virtual double cost() const = 0;
    virtual std::string getDescription() const = 0;
};

// 구상 컴포넌트
class BasicCoffee : public Coffee
{
public:
    double cost() const override
    {
        return 2.0;
    }

    std::string getDescription() const override
    {
        return "Basic Coffee";
    }
};

// 기초 데코레이터
class CoffeeDecorator : public Coffee
{
protected:
    Coffee *coffee;

public:
    CoffeeDecorator(Coffee *coffee) : coffee(coffee) {}
    double cost() const override = 0;
    std::string getDescription() const override = 0;
};

// 구상 데코레이터
class MilkDecorator : public CoffeeDecorator
{
public:
    MilkDecorator(Coffee *coffee) : CoffeeDecorator(coffee) {}

    double cost() const override
    {
        return coffee->cost() + 0.5;
    }

    std::string getDescription() const override
    {
        return coffee->getDescription() + ", Milk";
    }
};

class SugarDecorator : public CoffeeDecorator
{
public:
    SugarDecorator(Coffee *coffee) : CoffeeDecorator(coffee) {}

    double cost() const override
    {
        return coffee->cost() + 0.3;
    }

    std::string getDescription() const override
    {
        return coffee->getDescription() + ", Sugar";
    }
};
