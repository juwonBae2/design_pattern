#include "adapter_pattern.hpp"

int main()
{
    RectangleInterface *rectangle = new RectangleAdapter(10, 20, 30, 40);
    rectangle->Draw();

    delete rectangle;
    return 0;
}
