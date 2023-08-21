#include <iostream>

// 2.Client Interface
class RectangleInterface
{
public:
    virtual void Draw() = 0;
    virtual ~RectangleInterface() {}
};

// 1.Client
class Client
{
public:
    Client() {}

    void Run(RectangleInterface *rectangle)
    {
        rectangle->Draw();
    }
};

// 3.Service
class LegacyRectangle : public RectangleInterface
{
public:
    LegacyRectangle(int x1, int y1, int x2, int y2)
        : x1_(x1), y1_(y1), x2_(x2), y2_(y2) {}

    void Draw() override
    {
        std::cout << "LegacyRectangle Draw: "
                  << x1_ << "," << y1_ << "," << x2_ << "," << y2_ << std::endl;
    }

private:
    int x1_, y1_, x2_, y2_;
};

// 4.Adapter
class RectangleAdapter : public RectangleInterface
{
public:
    RectangleAdapter(int x, int y, int width, int height)
        : legacy_rectangle_(x, y, x + width, y + height) {}

    void Draw() override
    {
        std::cout << "RectangleAdapter Draw: ";
        legacy_rectangle_.Draw();
    }

private:
    LegacyRectangle legacy_rectangle_;
};