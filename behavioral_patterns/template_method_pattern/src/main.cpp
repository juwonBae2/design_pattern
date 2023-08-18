#include "template_method_pattern.hpp"

int main()
{
    // 게임 시나리오: 각 종족의 행동 실행
    BaseAI *orcAI = new OrcAI;
    BaseAI *humanAI = new HumanAI;
    BaseAI *monsterAI = new MonsterAI;

    std::cout << "Orc AI behavior:" << std::endl;
    orcAI->ExecuteAI();
    delete orcAI;

    std::cout << "\nHuman AI behavior:" << std::endl;
    humanAI->ExecuteAI();
    delete humanAI;

    std::cout << "\nMonster AI behavior:" << std::endl;
    monsterAI->ExecuteAI();
    delete monsterAI;

    return 0;
}
