#include "adapter_pattern.hpp"

int main()
{
    Client client;

    LegacyRectangle legacyRectangle(10, 20, 30, 40);
    RectangleAdapter adapter(10, 20, 20, 30);

    client.Run(&legacyRectangle);
    client.Run(&adapter);

    return 0;
}
