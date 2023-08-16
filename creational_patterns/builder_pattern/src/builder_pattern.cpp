#include "builder_pattern.hpp"

void Computer::SetCPU(const std::string &cpu)
{
    cpu_ = cpu;
}

void Computer::SetGPU(const std::string &gpu)
{
    gpu_ = gpu;
}

void Computer::SetRAM(const std::string &ram)
{
    ram_ = ram;
}

void Computer::ShowSpecs()
{
    std::cout << "Computer Specs:" << std::endl;
    std::cout << "CPU: " << cpu_ << std::endl;
    std::cout << "GPU: " << gpu_ << std::endl;
    std::cout << "RAM: " << ram_ << std::endl;
}
