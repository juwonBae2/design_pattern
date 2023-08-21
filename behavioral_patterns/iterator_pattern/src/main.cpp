#include "iterator_pattern.hpp"

void ClientCode()
{
    std::cout << "________________Iterator with int______________________________________" << std::endl;
    Container<int> cont;

    for (int i = 0; i < 10; i++)
    {
        cont.Add(i);
    }

    // linked list(자료구조)
    Iterator<int, Container<int>> *it = cont.CreateIterator();
    for (it->First(); !it->IsDone(); it->Next())
    {
        std::cout << *it->Current() << std::endl;
    }
    delete it;
}

// iterator_pattern2

class IntArray
{
public:
    IntArray(int *arr, int s) : array_(arr), size_(s) {}

    int *begin() { return array_; }
    int *end() { return array_ + size_; }

private:
    int *array_;
    int size_;
};

int main()
{
    // iterator_pattern1
    ClientCode();

    Container<Data> cont2;
    Data a(100), b(1000), c(10000);
    cont2.Add(a);
    cont2.Add(b);
    cont2.Add(c);

    std::cout << "________________Iterator with custom Class______________________________" << std::endl;
    Iterator<Data, Container<Data>> *it2 = cont2.CreateIterator();
    for (it2->First(); !it2->IsDone(); it2->Next())
    {
        std::cout << it2->Current()->data() << std::endl;
    }

    delete it2;

    // iterator_pattern2
    std::cout << "\niterator_pattern2" << std::endl;
    int arr[] = {10, 20, 30, 40, 50};
    IntArray intArray(arr, 5);

    for (int *it = intArray.begin(); it != intArray.end(); ++it)
    {
        std::cout << *it << " " << std::endl;
    }

    return 0;
}