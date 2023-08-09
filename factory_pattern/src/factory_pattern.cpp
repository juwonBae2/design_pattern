#include "factory_pattern.hpp"

int main()
{
    ApplicationConfigurator configurator;
    configurator.main("Windows"); // 윈도우 버전 실행
    configurator.main("Mac");     // 맥 버전 실행

    return 0;
}
