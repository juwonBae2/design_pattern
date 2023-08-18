#include "strategy_pattern.hpp"
#include "strategy_pattern2.hpp"

void strategyPattern1()
{
    std::vector<int> data = {5, 2, 9, 1, 5, 6};

    QuickSort quickSort;
    MergeSort mergeSort;
    BubbleSort bubbleSort;

    SortContext context(&quickSort);
    context.executeSort(data);

    // 이후에 다른 정렬 전략을 사용하려면 context.setStrategy(&mergeSort); 등으로 변경 가능

    std::cout << "Sorted data:";
    for (int num : data)
    {
        std::cout << " " << num;
    }
    std::cout << "\n"
              << std::endl;
}

void strategyPattern2()
{
    Player player1("Basic Player", new DefaultHealthAlgorithm());
    player1.displayInfo();

    Player player2("Warrior", new WarriorHealthAlgorithm());
    player2.displayInfo();

    Player player3("Mage", new MageHealthAlgorithm());
    player3.displayInfo();

    // Changing algorithms dynamically
    player2.setHealthAlgorithm(new DefaultHealthAlgorithm());
    player2.displayInfo();
}

int main()
{
    strategyPattern1();

    strategyPattern2();

    return 0;
}
