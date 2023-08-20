#pragma once

#include <iostream>
#include <string>

// 1.Component
class Coffee
{
public:
    virtual ~Coffee() {}
    virtual double cost() const = 0;
    virtual std::string getDescription() const = 0;
};

// 2.Concrete Component
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

// 3.Base Decorator
class CoffeeDecorator : public Coffee
{
protected:
    Coffee *coffee;

public:
    CoffeeDecorator(Coffee *coffee) : coffee(coffee) {}
    double cost() const override = 0;
    std::string getDescription() const override = 0;
};

// 4.Concrete Decorators
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

// 4.Concrete Decorators
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
