#pragma once

#include <iostream>

class Singleton
{
private:
    // 정적 멤버 변수로 유일한 인스턴스를 저장
    static Singleton *instance;

    Singleton() {}
    Singleton(const Singleton &) {}

public:
    // 정적 메서드를 통해 인스턴스에 접근
    static Singleton *getInstance();
    void showMessage();
};