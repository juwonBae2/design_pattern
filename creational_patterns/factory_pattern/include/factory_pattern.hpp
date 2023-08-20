#pragma once
#include <iostream>

// Product
class Shape
{
public:
    virtual ~Shape() {}
    virtual void draw() = 0;
};

// Concrete product
class Circle : public Shape
{
public:
    void draw() override
    {
        std::cout << "Drawing a circle" << std::endl;
    }
};

class Rectangle : public Shape
{
public:
    void draw() override
    {
        std::cout << "Drawing a rectangle" << std::endl;
    }
};

// Creator (Shape Factory)
class ShapeFactory
{
public:
    virtual ~ShapeFactory() {}
    virtual Shape *createShape() = 0;
};

// Concrete creator
class CircleFactory : public ShapeFactory
{
public:
    Shape *createShape() override
    {
        return new Circle();
    }
};

class RectangleFactory : public ShapeFactory
{
public:
    Shape *createShape() override
    {
        return new Rectangle();
    }
};
