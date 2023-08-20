#include "factory_pattern.hpp"
#include "factory_pattern2.hpp"

int main()
{
    // factory_pattern1
    ShapeFactory *circleFactory = new CircleFactory();
    Shape *circle = circleFactory->createShape();
    circle->draw();

    ShapeFactory *rectangleFactory = new RectangleFactory();
    Shape *rectangle = rectangleFactory->createShape();
    rectangle->draw();

    delete circleFactory;
    delete circle;
    delete rectangleFactory;
    delete rectangle;

    std::cout << "\n"
              << std::endl;

    // main
    // factory_pattern2
    Store store;

    std::unique_ptr<Beverage> coffee = store.GetDrink("Coffee");
    std::unique_ptr<Beverage> tea = store.GetDrink("Tea");

    coffee->Prepare();
    tea->Prepare();

    return 0;
}
