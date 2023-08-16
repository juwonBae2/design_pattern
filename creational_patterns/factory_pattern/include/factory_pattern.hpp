#pragma once
#include <iostream>

class Shape
{
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape
{
public:
    void draw() override;
};

class Rectangle : public Shape
{
public:
    void draw() override;
};

// ShapeFactory
class ShapeFactory
{
public:
    virtual Shape *createShape() = 0;
    virtual ~ShapeFactory(){};
};

class CircleFactory : public ShapeFactory
{
public:
    Shape *createShape() override;
};

class RectangleFactory : public ShapeFactory
{
public:
    Shape *createShape() override;
};
