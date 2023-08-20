#pragma once

#include <string>
#include <iostream>
#include <mutex>

class ConfigurationManager
{
public:
    ConfigurationManager(ConfigurationManager &other) = delete;
    void operator=(const ConfigurationManager &) = delete;

    static ConfigurationManager *GetInstance(const std::string &value);

    void PerformAction(const std::string &action)
    {
        std::cout << "Performing " << action << " using the ConfigurationManager with value: " << value_ << std::endl;
    }

    std::string GetValue() const
    {
        return value_;
    }

private:
    ConfigurationManager(const std::string value) : value_(value) {}

    static ConfigurationManager *instance_;
    static std::mutex mutex_;

    std::string value_;
};
