#include "builder_pattern.hpp"

int main()
{
    ComputerBuilder *builder = new GamingComputerBuilder();

    builder->BuildCPU();
    builder->BuildGPU();
    builder->BuildRAM();

    Computer *computer = builder->GetComputer();
    computer->ShowSpecs();

    delete computer;
    delete builder;

    return 0;
}
