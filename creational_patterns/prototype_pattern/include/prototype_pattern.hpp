#include <iostream>
#include <string>

class EnemyPrototype
{
public:
    virtual EnemyPrototype *clone() = 0;
    virtual void display() = 0;
    virtual ~EnemyPrototype(){};
};

class Goblin : public EnemyPrototype
{
private:
    std::string type;
    int health;

public:
    Goblin() : type("Goblin"), health(100) {}

    EnemyPrototype *clone() override
    {
        return new Goblin(*this);
    }

    void display() override
    {
        std::cout << "Goblin - Type: " << type << ", Health: " << health << std::endl;
    }
};

class Orc : public EnemyPrototype
{
private:
    std::string type;
    int health;

public:
    Orc() : type("Orc"), health(150) {}

    EnemyPrototype *clone() override
    {
        return new Orc(*this);
    }

    void display() override
    {
        std::cout << "Orc - Type: " << type << ", Health: " << health << std::endl;
    }
};