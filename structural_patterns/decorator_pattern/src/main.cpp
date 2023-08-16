#include "decorator_pattern.hpp"

int main()
{
    Coffee *basicCoffee = new BasicCoffee();
    Coffee *coffeeWithMilk = new MilkDecorator(basicCoffee);
    Coffee *coffeeWithMilkAndSugar = new SugarDecorator(coffeeWithMilk);

    std::cout << "Order: " << coffeeWithMilkAndSugar->getDescription() << std::endl;
    std::cout << "Cost: $" << coffeeWithMilkAndSugar->cost() << std::endl;

    delete coffeeWithMilkAndSugar;
    delete coffeeWithMilk;
    delete basicCoffee;

    return 0;
}
