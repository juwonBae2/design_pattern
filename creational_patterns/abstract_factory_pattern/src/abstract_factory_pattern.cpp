#include "abstract_factory_pattern.hpp"

void WinButton::paint() const
{
    std::cout << "Rendering a Windows button.\n";
}

void MacButton::paint() const
{
    std::cout << "Rendering a Mac button.\n";
}

void WinCheckbox::paint() const
{
    std::cout << "Rendering a Windows checkbox.\n";
}

void MacCheckbox::paint() const
{
    std::cout << "Rendering a Mac checkbox.\n";
}

Button *WinFactory::createButton() const
{
    return new WinButton();
}

Checkbox *WinFactory::createCheckbox() const
{
    return new WinCheckbox();
}

Button *MacFactory::createButton() const
{
    return new MacButton();
}

Checkbox *MacFactory::createCheckbox() const
{
    return new MacCheckbox();
}

Application::Application(GUIFactory *factory) : factory(factory), button(nullptr) {}

void Application::createUI()
{
    button = factory->createButton();
}

void Application::paint()
{
    if (button)
    {
        button->paint();
    }
}

void ApplicationConfigurator::main(const std::string &OS)
{
    GUIFactory *factory;
    if (OS == "Windows")
    {
        factory = new WinFactory();
    }
    else if (OS == "Mac")
    {
        factory = new MacFactory();
    }
    else
    {
        throw std::runtime_error("Error! Unknown operating system.");
    }

    Application app(factory);
    app.createUI();
    app.paint();
}
