#include "commponent_pattern.hpp"

int main()
{
    Directory *dir_engineering = new Directory("Engineering");
    Directory *dir_computer_science = new Directory("Computer Science");
    Directory *dir_algorithm = new Directory("Algorithm");
    Directory *dir_AI = new Directory("AI");

    dir_algorithm->add(new File("Binary Search"));
    dir_algorithm->add(new File("BFS"));
    dir_algorithm->add(new File("Dinic Algorithm"));
    dir_computer_science->add(dir_algorithm);

    dir_AI->add(new File("Reinforcement Learning"));
    dir_AI->add(new File("CNN"));
    dir_computer_science->add(dir_AI);

    dir_engineering->add(dir_computer_science);
    dir_engineering->print();

    delete dir_engineering;

    return 0;
}
