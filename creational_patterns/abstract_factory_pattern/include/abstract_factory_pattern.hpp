#pragma once

#include <iostream>
#include <string>

// Button
class Button
{
public:
    virtual void paint() const = 0;
    virtual ~Button() {}
};

class WinButton : public Button
{
public:
    void paint() const override;
};

class MacButton : public Button
{
public:
    void paint() const override;
};

// Check box
class Checkbox
{
public:
    virtual void paint() const = 0;
    virtual ~Checkbox() {}
};

class WinCheckbox : public Checkbox
{
public:
    void paint() const override;
};

class MacCheckbox : public Checkbox
{
public:
    void paint() const override;
};

class GUIFactory
{
public:
    virtual Button *createButton() const = 0;
    virtual Checkbox *createCheckbox() const = 0;
    virtual ~GUIFactory() {}
};

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