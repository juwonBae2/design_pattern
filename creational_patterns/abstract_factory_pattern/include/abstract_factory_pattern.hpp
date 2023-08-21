#pragma once

#include <iostream>
#include <string>

// 1.Abstract Products
class Button
{
public:
    virtual void paint() const = 0;
    virtual ~Button() {}
};

// 2.Concrete Products
class WinButton : public Button
{
public:
    void paint() const override;
};

// 2.Concrete Products
class MacButton : public Button
{
public:
    void paint() const override;
};

// 1.Abstract Products
class Checkbox
{
public:
    virtual void paint() const = 0;
    virtual ~Checkbox() {}
};

// 2.Concrete Products
class WinCheckbox : public Checkbox
{
public:
    void paint() const override;
};

// 2.Concrete Products
class MacCheckbox : public Checkbox
{
public:
    void paint() const override;
};

// 3.Abstract Factory
class GUIFactory
{
public:
    virtual Button *createButton() const = 0;
    virtual Checkbox *createCheckbox() const = 0;
    virtual ~GUIFactory() {}
};

// 4.Concrete Factories
class WinFactory : public GUIFactory
{
public:
    Button *createButton() const override;
    Checkbox *createCheckbox() const override;
};

class MacFactory : public GUIFactory
{
public:
    Button *createButton() const override;
    Checkbox *createCheckbox() const override;
};

// TODO: Application.. 코드 분리 해야 됨
class Application
{
private:
    GUIFactory *factory;
    Button *button;

public:
    Application(GUIFactory *factory);
    void createUI();
    void paint();
};

class ApplicationConfigurator
{
public:
    void main(const std::string &OS);
};