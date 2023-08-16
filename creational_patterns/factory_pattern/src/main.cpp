#include "factory_pattern.hpp"

int main()
{
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

    return 0;
}
