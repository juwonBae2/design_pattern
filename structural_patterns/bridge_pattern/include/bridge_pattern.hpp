#include <iostream>

// Device 구현 인터페이스
class Device
{
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
};

// 구현 클래스들
class TVDevice : public Device
{
public:
    void turnOn() override
    {
        std::cout << "TV is turned on" << std::endl;
    }

    void turnOff() override
    {
        std::cout << "TV is turned off" << std::endl;
    }
};

class RadioDevice : public Device
{
public:
    void turnOn() override
    {
        std::cout << "Radio is turned on" << std::endl;
    }

    void turnOff() override
    {
        std::cout << "Radio is turned off" << std::endl;
    }
};

// RemoteControl 추상화 클래스
class RemoteControl
{
protected:
    Device *device;

public:
    RemoteControl(Device *dev) : device(dev) {}

    virtual void pressButton() = 0;
};

// RemoteControl의 확장 클래스들
class SmartRemoteControl : public RemoteControl
{
public:
    SmartRemoteControl(Device *dev) : RemoteControl(dev) {}

    void pressButton() override
    {
        std::cout << "Smart Remote Control is pressed -> ";
        device->turnOn();
    }
};

class BasicRemoteControl : public RemoteControl
{
public:
    BasicRemoteControl(Device *dev) : RemoteControl(dev) {}

    void pressButton() override
    {
        std::cout << "Basic Remote Control is pressed -> ";
        device->turnOn();
    }
};
