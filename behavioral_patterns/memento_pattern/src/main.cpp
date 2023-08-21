#include "memento_pattern.hpp"

void ClientCode()
{
    Originator *originator = new Originator("Super-duper-super-puper-super.");
    Caretaker *caretaker = new Caretaker(originator);
    caretaker->Backup();

    originator->DoSomething();
    caretaker->Backup();

    originator->DoSomething();
    caretaker->Backup();

    originator->DoSomething();
    std::cout << "\n";

    // Memento list
    caretaker->ShowHistory();
    std::cout << "\nClient: Now, let's rollback!\n\n";

    caretaker->Undo();
    std::cout << "\nClient: Once more!\n\n";
    caretaker->Undo();

    delete originator;
    delete caretaker;
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    ClientCode();
    return 0;
}