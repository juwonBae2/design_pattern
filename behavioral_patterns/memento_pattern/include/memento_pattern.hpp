#include <iostream>

// 2.Memento
class Memento
{
public:
    virtual ~Memento() {}
    virtual std::string GetName() const = 0;
    virtual std::string date() const = 0;
    virtual std::string state() const = 0;
};
// 2.Concrete Memento
class ConcreteMemento : public Memento
{
public:
    ConcreteMemento(std::string state) : state_(state)
    {
        this->state_ = state;
        std::time_t now = std::time(0);
        this->date_ = std::ctime(&now);
    }

    std::string state() const override
    {
        return this->state_;
    }

    std::string GetName() const override
    {
        return this->date_ + " / (" + this->state_.substr(0, 9) + "...)";
    }
    std::string date() const override
    {
        return this->date_;
    }

private:
    std::string state_;
    std::string date_;
};

// 1.Originator
class Originator
{
public:
    Originator(std::string state) : state_(state)
    {
        std::cout << "Originator: My initial state is: " << this->state_ << "\n";
    }

    void DoSomething()
    {
        std::cout << "Originator: I'm doing something important.\n";
        this->state_ = this->GenerateRandomString(30);
        std::cout << "Originator: and my state has changed to: " << this->state_ << "\n";
    }

    Memento *Save()
    {
        return new ConcreteMemento(this->state_);
    }

    void Restore(Memento *memento)
    {
        this->state_ = memento->state();
        std::cout << "Originator: My state has changed to: " << this->state_ << "\n";
    }

private:
    std::string state_;

    std::string GenerateRandomString(int length = 10)
    {
        const std::array<char, 62> alphanum = {
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
            'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
            'U', 'V', 'W', 'X', 'Y', 'Z',
            'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
            'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
            'u', 'v', 'w', 'x', 'y', 'z'};

        int stringLength = alphanum.size();

        std::string random_string;
        for (int i = 0; i < length; i++)
        {
            random_string += alphanum[std::rand() % stringLength];
        }
        return random_string;
    }
};

// 3.Caretaker
class Caretaker
{
public:
    Caretaker(Originator *originator) : originator_(originator) {}
    ~Caretaker()
    {
        for (auto m : mementos_)
        {
            delete m;
        }
    }

    void Backup()
    {
        std::cout << "\nCaretaker: Saving Originator's state...\n";
        this->mementos_.push_back(this->originator_->Save());
    }
    void Undo()
    {
        if (!this->mementos_.size())
        {
            return;
        }
        Memento *memento = this->mementos_.back();
        this->mementos_.pop_back();
        std::cout << "Caretaker: Restoring state to: " << memento->GetName() << "\n";
        try
        {
            this->originator_->Restore(memento);
        }
        catch (...)
        {
            this->Undo();
        }
    }
    void ShowHistory() const
    {
        std::cout << "Caretaker: Here's the list of mementos:\n";
        for (Memento *memento : this->mementos_)
        {
            std::cout << memento->GetName() << "\n";
        }
    }

private:
    std::vector<Memento *> mementos_;
    Originator *originator_;
};