#pragma once

#include <iostream>
#include <vector>

class SortStrategy
{
public:
    virtual void sort(std::vector<int> &data) = 0;
    virtual ~SortStrategy() {}
};

class QuickSort : public SortStrategy
{
public:
    void sort(std::vector<int> &data) override;
};

class MergeSort : public SortStrategy
{
public:
    void sort(std::vector<int> &data) override;
};

class BubbleSort : public SortStrategy
{
public:
    void sort(std::vector<int> &data) override;
};

// SortContext
class SortContext
{
private:
    SortStrategy *strategy;

public:
    SortContext(SortStrategy *strategy) : strategy(strategy) {}

    void setStrategy(SortStrategy *newStrategy)
    {
        strategy = newStrategy;
    }

    void executeSort(std::vector<int> &data)
    {
        strategy->sort(data);
    }
};