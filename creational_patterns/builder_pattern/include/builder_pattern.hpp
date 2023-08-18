#pragma once
#include <iostream>
#include <string>

// Product
class Computer
{
public:
    void SetCPU(const std::string &cpu);
    void SetGPU(const std::string &gpu);
    void SetRAM(const std::string &ram);
    void ShowSpecs();

private:
    std::string cpu_;
    std::string gpu_;
    std::string ram_;
};

// Builder
class ComputerBuilder
{
public:
    virtual void BuildCPU() = 0;
    virtual void BuildGPU() = 0;
    virtual void BuildRAM() = 0;
    virtual Computer *GetComputer() = 0;

    virtual ~ComputerBuilder() {}
};

// Concrete Builder
class GamingComputerBuilder : public ComputerBuilder
{
public:
    GamingComputerBuilder()
    {
        computer_ = new Computer();
    }

    void BuildCPU() override
    {
        computer_->SetCPU("Intel Core i7");
    }

    void BuildGPU() override
    {
        computer_->SetGPU("NVIDIA GeForce RTX 3080");
    }

    void BuildRAM() override
    {
        computer_->SetRAM("32GB DDR4");
    }

    Computer *GetComputer() override
    {
        return computer_;
    }

private:
    Computer *computer_;
};
