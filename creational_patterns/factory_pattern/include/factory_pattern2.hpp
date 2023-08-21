#include <iostream>
#include <memory>
#include <unordered_map>
#include <string>

// 1.Product
class Beverage
{
public:
    virtual ~Beverage() {}
    virtual void Prepare() = 0;
};

// 2.Concrete product
class Coffee : public Beverage
{
public:
    void Prepare() override
    {
        std::cout << "Preparing Coffee" << std::endl;
    }
};

// 2.Concrete product
class Tea : public Beverage
{
public:
    void Prepare() override
    {
        std::cout << "Preparing Tea" << std::endl;
    }
};

// 3.Creator (Beverage Factory)
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

// 4.Concrete creator
class Store
{
public:
    Store()
    {
        beverage_factories_["Coffee"] = std::make_unique<CoffeeFactory>();
        beverage_factories_["Tea"] = std::make_unique<TeaFactory>();
    }

    std::unique_ptr<Beverage> GetDrink(const std::string &kind)
    {
        return beverage_factories_[kind]->Make();
    }

private:
    std::unordered_map<std::string, std::unique_ptr<BeverageFactory>> beverage_factories_;
};
