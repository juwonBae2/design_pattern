#pragma once
#include <iostream>

// 추상 기초 클래스 (AbstractClass)
class BaseAI
{
public:
    virtual ~BaseAI() {}

    // 템플릿 메서드
    void ExecuteAI()
    {
        GatherResources();
        BuildStructures();
        AttackEnemies();
        // 기타 공통 동작 수행
    }

    // 추상 메서드들
    virtual void GatherResources() = 0;
    virtual void BuildStructures() = 0;
    virtual void AttackEnemies() = 0;
};

// 오크 종족의 인공지능 클래스
class OrcAI : public BaseAI
{
public:
    void GatherResources() override
    {
        std::cout << "Orcs are gathering resources aggressively." << std::endl;
    }

    void BuildStructures() override
    {
        std::cout << "Orcs are building offensive structures." << std::endl;
    }

    void AttackEnemies() override
    {
        std::cout << "Orcs are attacking enemies with full force." << std::endl;
    }
};

// 인간 종족의 인공지능 클래스
class HumanAI : public BaseAI
{
public:
    void GatherResources() override
    {
        std::cout << "Humans are efficiently gathering resources." << std::endl;
    }

    void BuildStructures() override
    {
        std::cout << "Humans are constructing defensive buildings." << std::endl;
    }

    void AttackEnemies() override
    {
        std::cout << "Humans are focusing on defensive strategies." << std::endl;
    }
};

// 몬스터 종족의 인공지능 클래스
class MonsterAI : public BaseAI
{
public:
    void GatherResources() override
    {
        std::cout << "Monsters don't gather resources." << std::endl;
    }

    void BuildStructures() override
    {
        std::cout << "Monsters cannot build structures." << std::endl;
    }

    void AttackEnemies() override
    {
        std::cout << "Monsters attack using their brute strength." << std::endl;
    }
};
