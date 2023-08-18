#include <iostream>
#include <memory>
#include <unordered_map>
#include <string>

class Beverage
{
public:
    virtual ~Beverage() {}
    virtual void Prepare() = 0;
};

class Coffee : public Beverage
{
public:
    void Prepare() override
    {
        std::cout << "Preparing Coffee" << std::endl;
    }
};

class Tea : public Beverage
{
public:
    void Prepare() override
    {
        std::cout << "Preparing Tea" << std::endl;
    }
};

class BeverageFactory
{
public:
    virtual ~BeverageFactory() {}
    virtual std::unique_ptr<Beverage> Make() = 0;
};

class CoffeeFactory : public BeverageFactory
{
public:
    std::unique_ptr<Beverage> Make() override
    {
        return std::make_unique<Coffee>();
    }
};

class TeaFactory : public BeverageFactory
{
public:
    std::unique_ptr<Beverage> Make() override
    {
        return std::make_unique<Tea>();
    }
};

class Store
{
    std::unordered_map<std::string, std::unique_ptr<BeverageFactory>> beverageFactories;

public:
    Store()
    {
        beverageFactories["Coffee"] = std::make_unique<CoffeeFactory>();
        beverageFactories["Tea"] = std::make_unique<TeaFactory>();
    }

    std::unique_ptr<Beverage> GetDrink(const std::string &kind)
    {
        return beverageFactories[kind]->Make();
    }
};
