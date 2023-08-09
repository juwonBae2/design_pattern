#include "singleton_pattern.hpp"

int main()
{
    Singleton *singletonInstance = Singleton::getInstance();
    singletonInstance->showMessage();

    Singleton *anotherInstance = Singleton::getInstance();
    anotherInstance->showMessage();

    if (singletonInstance == anotherInstance)
    {
        std::cout << "Both pointers point to the same instance." << std::endl;
    }
    else
    {
        std::cout << "Pointers point to different instances (this should not happen in a Singleton)." << std::endl;
    }

    return 0;
}
