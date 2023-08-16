#include <iostream>
#include <vector>

class Component
{
public:
    virtual ~Component() {}
    virtual void print(int) = 0;
};

class Directory : public Component
{
public:
    Directory(std::string id) : m_id_(id) {}

    void add(Component *input)
    {
        m_comp_.push_back(input);
    }

    void print(int tap = 0) override
    {
        for (int i = 0; i < tap; i++)
            std::cout << "\t";
        std::cout << "directory: " << m_id_ << std::endl;

        for (auto dir : m_comp_)
        {
            dir->print(tap + 1);
        }
    }

private:
    std::vector<Component *> m_comp_;
    std::string m_id_;
};

class File : public Component
{
public:
    File(std::string id) : m_id_(id) {}

    void print(int tap = 0) override
    {
        for (int i = 0; i < tap; i++)
            std::cout << "\t";
        std::cout << "file: " << m_id_ << std::endl;
    }

private:
    std::string m_id_;
};