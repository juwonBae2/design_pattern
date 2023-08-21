#pragma once

#include <string>
#include <iostream>
#include <mutex>

class ConfigurationManager
{
public:
    ConfigurationManager(ConfigurationManager &other) = delete;
    void operator=(const ConfigurationManager &) = delete;

    // 싱글톤 객체의 인스턴스를 반환하는 정적 멤버 함수
    static ConfigurationManager *GetInstance(const std::string &value);

    void PerformAction(const std::string &action)
    {
        std::cout << "Performing " << action << " using the ConfigurationManager with value: " << value_ << std::endl;
    }

private:
    ConfigurationManager(const std::string value) : value_(value) {}

    static ConfigurationManager *instance_;
    static std::mutex mutex_;

    std::string value_;
};
