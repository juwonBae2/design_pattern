#include <iostream>
#include <string>
#include <vector>

class Mediator;

class Colleague
{
public:
    Colleague(Mediator *mediator) : mediator(mediator) {}
    virtual void Send(std::string message) = 0;
    virtual void Receive(std::string message) = 0;

protected:
    Mediator *mediator;
};

class Player : public Colleague
{
public:
    Player(Mediator *mediator, std::string name) : Colleague(mediator), name(name) {}
    void Send(std::string message) override;
    void Receive(std::string message) override;

private:
    std::string name;
};

class Monster : public Colleague
{
public:
    Monster(Mediator *mediator, std::string name) : Colleague(mediator), name(name) {}
    void Send(std::string message) override;
    void Receive(std::string message) override;

private:
    std::string name;
};

class Mediator
{
public:
    void AddColleague(Colleague *colleague)
    {
        colleagues.push_back(colleague);
    }
    void DistributeMessage(Colleague *sender, std::string message)
    {
        for (Colleague *colleague : colleagues)
        {
            if (colleague != sender)
            {
                colleague->Receive(message);
            }
        }
    }

private:
    std::vector<Colleague *> colleagues;
};

void Player::Send(std::string message)
{
    std::cout << name << " sends: " << message << std::endl;
    mediator->DistributeMessage(this, message);
}

void Player::Receive(std::string message)
{
    std::cout << name << " receives: " << message << std::endl;
}

void Monster::Send(std::string message)
{
    std::cout << name << " sends: " << message << std::endl;
    mediator->DistributeMessage(this, message);
}

void Monster::Receive(std::string message)
{
    std::cout << name << " receives: " << message << std::endl;
}

int main()
{
    Mediator mediator;

    Player player(&mediator, "Alice");
    Monster monster(&mediator, "Dragon");

    mediator.AddColleague(&player);
    mediator.AddColleague(&monster);

    player.Send("Hello, Monster!");
    monster.Send("Greetings, Player!");

    return 0;
}
