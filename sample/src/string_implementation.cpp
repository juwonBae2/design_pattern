#include "string_implementation.hpp"

int main()
{
    String str1 = "Hello";
    std::cout << "Concatenated string(str1): " << str1 << std::endl;

    String str2 = "World";

    String str3 = str1 + str2;
    std::cout << "Concatenated string: " << str3 << std::endl;

    if (str1 == str2)
    {
        std::cout << "str1 and str2 are equal." << std::endl;
    }
    else if (str1 < str2)
    {
        std::cout << "str1 is less than str2." << std::endl;
    }
    else if (str1 > str2)
    {
        std::cout << "str1 is greater than str2." << std::endl;
    }

    return 0;
}

// 얕은 복사 vs 깊은 복사
// #include <iostream>
// class MyClass
// {
// public:
//     int *data;

//     MyClass(int value)
//     {
//         data = new int(value);
//     }

//     // 복사 생성자를 정의하여 깊은 복사를 수행
//     MyClass(const MyClass &other)
//     {
//         data = new int(*(other.data));
//     }

//     ~MyClass()
//     {
//         delete data;
//     }
// };

// int main()
// {
//     MyClass obj1(10);
//     MyClass obj2 = obj1; // 깊은 복사가 발생

//     // obj1과 obj2는 서로 다른 메모리를 가리킴
//     *(obj1.data) = 20;

//     std::cout << *(obj2.data) << std::endl; // 출력 결과: 10

//     std::cout << *(obj1.data) << std::endl; // 출력 결과: 10

//     return 0;
// }
