#include "singleton_pattern.hpp"

ConfigurationManager *ConfigurationManager::instance_ = nullptr;
std::mutex ConfigurationManager::mutex_;

ConfigurationManager *ConfigurationManager::GetInstance(const std::string &value)
{
    if (instance_ == nullptr)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        if (instance_ == nullptr)
        {
            instance_ = new ConfigurationManager(value);
        }
    }
    return instance_;
}
