// 참고 사이트 https: // grayt.tistory.com/70

#pragma once

#include <string>

class HealthAlgorithm
{
public:
    virtual ~HealthAlgorithm() = default;
    virtual int calculateHealth() const = 0;
};

class DefaultHealthAlgorithm : public HealthAlgorithm
{
public:
    int calculateHealth() const override;
};

class WarriorHealthAlgorithm : public HealthAlgorithm
{
public:
    int calculateHealth() const override;
};

class MageHealthAlgorithm : public HealthAlgorithm
{
public:
    int calculateHealth() const override;
};

class Player
{
public:
    Player(const std::string &playerName, HealthAlgorithm *health_algorithm);
    ~Player();

    void setHealthAlgorithm(HealthAlgorithm *health_algorithm);
    int getHealth() const;
    void displayInfo() const;

private:
    std::string name_;
    HealthAlgorithm *health_algorithm_;
};