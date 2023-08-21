#pragma once

#include <iostream>
#include <string>
#include <vector>

// 1.Iterator, 2.Concrete Iterator
template <typename T, typename U>
class Iterator
{
public:
    typedef typename std::vector<T>::iterator iter_type;
    Iterator(U *p_data, bool reverse = false) : m_p_data_(p_data)
    {
        m_it_ = m_p_data_->m_data_.begin();
    }

    void First()
    {
        m_it_ = m_p_data_->m_data_.begin();
    }

    void Next()
    {
        m_it_++;
    }

    bool IsDone()
    {
        return (m_it_ == m_p_data_->m_data_.end());
    }

    iter_type Current()
    {
        return m_it_;
    }

private:
    U *m_p_data_;
    iter_type m_it_;
};

// 3.Iterable Collection
template <class T>
class Container
{
    friend class Iterator<T, Container>;

public:
    void Add(T a)
    {
        m_data_.push_back(a);
    }

    // 4.Concrete Collection
    Iterator<T, Container> *CreateIterator()
    {
        return new Iterator<T, Container>(this);
    }

private:
    std::vector<T> m_data_;
};

// 단순히 Data 넣어주기 위한 class
class Data
{
public:
    Data(int a = 0) : m_data_(a) {}

    void set_data(int a)
    {
        m_data_ = a;
    }

    int data()
    {
        return m_data_;
    }

private:
    int m_data_;
};
