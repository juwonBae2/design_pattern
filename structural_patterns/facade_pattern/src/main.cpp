#include "facade_pattern.hpp"
#include <iostream>

// client test
int main()
{
    ArmorBuilderFacade abf;

    std::cout << abf.GetHeavyArmor() << '\n';
    std::cout << abf.GetMediumArmor() << '\n';
    std::cout << abf.GetLightArmor() << '\n';
}
