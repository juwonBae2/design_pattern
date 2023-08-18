#pragma once

#include <iostream>
#include <list>
#include <string>

class Reporter;
class Account;
class PassbookAccount;
class CheckingAccount;

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

class Reporter
{
public:
    virtual void visit_passbook_account(PassbookAccount *acc) = 0;
    virtual void visit_checking_account(CheckingAccount *acc) = 0;
};

class PassbookAccount : public Account
{
public:
    PassbookAccount(std::string n) : Account{n} {}

    void accept(Reporter &r) override
    {
        r.visit_passbook_account(this);
    }

    int get_total_sum() const override
    {
        return money_;
    }
};

class CheckingAccount : public Account
{
public:
    CheckingAccount(std::string n) : Account{n} {}

    void accept(Reporter &r) override
    {
        r.visit_checking_account(this);
    }

    int get_total_sum() const override
    {
        return money_;
    }
};

class TotalSumReporter : public Reporter
{
public:
    void visit_passbook_account(PassbookAccount *acc) override
    {
        std::cout << acc->get_customer_name() << "Amount held by: " << acc->get_total_sum() << std::endl;
    }

    void visit_checking_account(CheckingAccount *acc) override
    {
        std::cout << acc->get_customer_name() << "Amount held by: " << acc->get_total_sum() << std::endl;
    }
};

class HistoryReporter : public Reporter
{
public:
    void visit_passbook_account(PassbookAccount *acc) override
    {
        std::cout << acc->get_customer_name() << "'s deposit and withdrawal history" << std::endl;
        for (auto &elem : acc->get_history())
        {
            std::cout << elem << std::endl;
        }
    }

    void visit_checking_account(CheckingAccount *acc) override
    {
        std::cout << acc->get_customer_name() << "'s deposit and withdrawal history" << std::endl;
        for (auto &elem : acc->get_history())
        {
            std::cout << elem << std::endl;
        }
    }
};
