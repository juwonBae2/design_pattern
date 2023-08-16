#include "abstract_factory_pattern.hpp"

int main()
{
    ApplicationConfigurator configurator;
    // Windows
    configurator.main("Windows");

    // mac
    configurator.main("Mac");

    return 0;
}
