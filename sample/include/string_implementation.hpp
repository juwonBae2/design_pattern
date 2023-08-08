#include <iostream>
#include <cstring>

class String
{

private:
    char *data;

public:
    String() : data(nullptr) {}

    String(const char *str)
    {
        if (str != nullptr)
        {
            data = new char[strlen(str) + 1];
            strcpy(data, str);
        }
        else
        {
            data = nullptr;
        }
    }

    ~String()
    {
        delete[] data;
    }

    // 복사 생성자
    String(const String &other)
    {
        if (other.data != nullptr)
        {
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }
        else
        {
            data = nullptr;
        }
    }

    // 이동 생성자
    String(String &&other) noexcept
    {
        data = other.data;
        other.data = nullptr;
    }

    // 복사 대입 연산자
    String &operator=(const String &other)
    {
        if (this != &other)
        {
            delete[] data;
            if (other.data != nullptr)
            {
                data = new char[strlen(other.data) + 1];
                strcpy(data, other.data);
            }
            else
            {
                data = nullptr;
            }
        }
        return *this;
    }

    // 이동 대입 연산자
    String &operator=(String &&other) noexcept
    {
        if (this != &other)
        {
            delete[] data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }

    // operator엔 웬만하면 this를 넣어줘야 됨 (명시적) 
    // operator ==
    bool operator==(const String &other) const
    {
        return (strcmp(data, other.data) == 0);
    }

    // operator <
    bool operator<(const String &other) const
    {
        return (strcmp(data, other.data) < 0);
    }

    // operator >
    bool operator>(const String &other) const
    {
        return (strcmp(data, other.data) > 0);
    }

    friend std::ostream &operator<<(std::ostream &os, const String &str)
    {
        if (str.data != nullptr)
        {
            os << str.data;
        }
        return os;
    }

    // operator +
    String operator+(const String &other) const
    {
        size_t totalLen = strlen(data) + strlen(other.data);
        char *temp = new char[totalLen + 1];
        strcpy(temp, data);
        strcat(temp, other.data);
        String result(temp);
        delete[] temp;
        return result;
    }
};