#pragma once

#include <iostream>
#include <list>
#include <string>

class Reporter;
class Account;
class PassbookAccount;
class CheckingAccount;

// 3.Element
class Account
{
public:
    Account(std::string n) : customer_name_{n}, money_{0}, history_{} {}
    virtual ~Account() {}

    virtual void accept(Reporter &r) = 0;
    virtual int get_total_sum() const = 0;

    std::list<int> get_history() const
    {
        return history_;
    }

    std::string get_customer_name() const
    {
        return customer_name_;
    }

    void deposit(int money)
    {
        money_ += money;
        history_.push_back(money);
    }

    void withdraw(int money)
    {
        money_ -= money;
        history_.push_back(-money);
    }

protected:
    std::list<int> history_;
    std::string customer_name_;
    int money_;
};

// 1.Visitor interface
class Reporter
{
public:
    virtual void visitPassbookAccount(PassbookAccount *acc) = 0;
    // 사용 x
    virtual void visitCheckingAccount(CheckingAccount *acc) = 0;
};

// 4.Concrete Element
class PassbookAccount : public Account
{
public:
    PassbookAccount(std::string n) : Account{n} {}

    void accept(Reporter &r) override
    {
        r.visitPassbookAccount(this);
    }

    int get_total_sum() const override
    {
        return money_;
    }
};

// 사용 x
class CheckingAccount : public Account
{
public:
    CheckingAccount(std::string n) : Account{n} {}

    void accept(Reporter &r) override
    {
        r.visitCheckingAccount(this);
    }

    int get_total_sum() const override
    {
        return money_;
    }
};

// 2.Concrete Visitors
class TotalSumReporter : public Reporter
{
public:
    void visitPassbookAccount(PassbookAccount *acc) override
    {
        std::cout << acc->get_customer_name() << "Amount held by: " << acc->get_total_sum() << std::endl;
    }

    // 사용 x
    void visitCheckingAccount(CheckingAccount *acc) override
    {
        std::cout << acc->get_customer_name() << "Amount held by: " << acc->get_total_sum() << std::endl;
    }
};

// 2.Concrete Visitors
class HistoryReporter : public Reporter
{
public:
    void visitPassbookAccount(PassbookAccount *acc) override
    {
        std::cout << acc->get_customer_name() << "'s deposit and withdrawal history" << std::endl;
        for (auto &elem : acc->get_history())
        {
            std::cout << elem << std::endl;
        }
    }

    // 사용 x
    void visitCheckingAccount(CheckingAccount *acc) override
    {
        std::cout << acc->get_customer_name() << "'s deposit and withdrawal history" << std::endl;
        for (auto &elem : acc->get_history())
        {
            std::cout << elem << std::endl;
        }
    }
};
