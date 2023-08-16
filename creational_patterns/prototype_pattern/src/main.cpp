#include "prototype_pattern.hpp"

int main()
{
    Goblin goblinPrototype;
    Orc orcPrototype;

    EnemyPrototype *goblinClone = goblinPrototype.clone();
    EnemyPrototype *orcClone = orcPrototype.clone();

    goblinPrototype.display();
    goblinClone->display();

    orcPrototype.display();
    orcClone->display();

    delete goblinClone;
    delete orcClone;

    return 0;
}
