#include "singleton_pattern.hpp"
#include <thread>

void ThreadFunction(const std::string &threadName)
{
    ConfigurationManager *configManager = ConfigurationManager::GetInstance(threadName);
    configManager->PerformAction("action in thread " + threadName);
}

int main()
{
    std::thread t1(ThreadFunction, "Thread X");
    std::thread t2(ThreadFunction, "Thread Y");
    t1.join();
    t2.join();

    return 0;
}
