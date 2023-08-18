#include "strategy_pattern2.hpp"
#include <iostream>

Player::Player(const std::string &playerName, HealthAlgorithm *health_algorithm) : name_(playerName), health_algorithm_(health_algorithm) {}

Player::~Player()
{
    delete health_algorithm_;
}

void Player::setHealthAlgorithm(HealthAlgorithm *health_algorithm)
{
    if (health_algorithm_ != health_algorithm)
    {
        delete health_algorithm_;
        health_algorithm_ = health_algorithm;
    }
}

int Player::getHealth() const
{
    return health_algorithm_->calculateHealth();
}

void Player::displayInfo() const
{
    std::cout << "Player: " << name_ << ", Health: " << getHealth() << std::endl;
}

int DefaultHealthAlgorithm::calculateHealth() const
{
    return 100;
}

int WarriorHealthAlgorithm::calculateHealth() const
{
    return 150;
}

int MageHealthAlgorithm::calculateHealth() const
{
    return 70;
}