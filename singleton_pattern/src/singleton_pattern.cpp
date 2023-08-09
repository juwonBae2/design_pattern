#include "singleton_pattern.hpp"

Singleton *Singleton::instance = nullptr;

Singleton *Singleton::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Singleton();
    }
    return instance;
}

void Singleton::showMessage()
{
    std::cout << "Hello, I am the Singleton!" << std::endl;
}
