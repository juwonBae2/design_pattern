#include <iostream>

// Button 인터페이스
class Button {
public:
    virtual void paint() const = 0;
};

class WinButton : public Button {
public:
    void paint() const override {
        std::cout << "Rendering a Windows button.\n";
    }
};

class MacButton : public Button {
public:
    void paint() const override {
        std::cout << "Rendering a Mac button.\n";
    }
};

// Checkbox 인터페이스
class Checkbox {
public:
    virtual void paint() const = 0;
};

class WinCheckbox : public Checkbox {
public:
    void paint() const override {
        std::cout << "Rendering a Windows checkbox.\n";
    }
};

class MacCheckbox : public Checkbox {
public:
    void paint() const override {
        std::cout << "Rendering a Mac checkbox.\n";
    }
};

// GUIFactory 인터페이스
class GUIFactory {
public:
    virtual Button* createButton() const = 0;
    virtual Checkbox* createCheckbox() const = 0;
};

class WinFactory : public GUIFactory {
public:
    Button* createButton() const override {
        return new WinButton();
    }
    Checkbox* createCheckbox() const override {
        return new WinCheckbox();
    }
};

class MacFactory : public GUIFactory {
public:
    Button* createButton() const override {
        return new MacButton();
    }
    Checkbox* createCheckbox() const override {
        return new MacCheckbox();
    }
};

// Application 클래스
class Application {
private:
    GUIFactory* factory;
    Button* button;

public:
    Application(GUIFactory* factory) : factory(factory), button(nullptr) {}
    
    void createUI() {
        button = factory->createButton();
    }

    void paint() {
        if (button) {
            button->paint();
        }
    }
};

class ApplicationConfigurator {
public:
    void main(const std::string& OS) {
        GUIFactory* factory;
        if (OS == "Windows") {
            factory = new WinFactory();
        } else if (OS == "Mac") {
            factory = new MacFactory();
        } else {
            throw std::runtime_error("Error! Unknown operating system.");
        }
        
        Application app(factory);
        app.createUI();
        app.paint();
    }
};