#include "adapter_pattern.hpp"

int main()
{
    Client client;

    LegacyRectangle legacyRectangle(10, 20, 30, 40);

    RectangleAdapter adapter(10, 20, 20, 30);

    client.Run(&adapter);
    client.Run(&legacyRectangle);

    return 0;
}
