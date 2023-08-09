#include <iostream>

// '구현' 인터페이스
class Device
{
public:
    virtual ~Device(){};

    virtual bool isEnabled() = 0;
    virtual void enable() = 0;
    virtual void disable() = 0;
    virtual int getVolume() = 0;
    virtual void setVolume(int percent) = 0;
    virtual int getChannel() = 0;
    virtual void setChannel(int channel) = 0;
};

// 구현 클래스들
class Tv : public Device
{
public:
    bool isEnabled() override
    {
        // TV의 상태 확인
        return false;
    }

    void enable() override
    {
        // TV 켜기
    }

    void disable() override
    {
        // TV 끄기
    }

    int getVolume() override
    {
        // 볼륨 가져오기
        return 0;
    }

    void setVolume(int percent) override
    {
        // 볼륨 설정
    }

    int getChannel() override
    {
        // 채널 가져오기
        return 0;
    }

    void setChannel(int channel) override
    {
        // 채널 설정
    }
};

class Radio : public Device
{
public:
    // Radio의 구현은 위와 유사하게 작성

    bool isEnabled() override
    {
        // Radio의 상태 확인
        return false;
    }

    void enable() override
    {
        // Radio 켜기
    }

    void disable() override
    {
        // Radio 끄기
    }

    int getVolume() override
    {
        // 볼륨 가져오기
        return 0;
    }

    void setVolume(int percent) override
    {
        // 볼륨 설정
    }

    int getChannel() override
    {
        // 채널 가져오기
        return 0;
    }

    void setChannel(int channel) override
    {
        // 채널 설정
    }
};

// '추상화' 클래스
class RemoteControl
{
protected:
    Device *device;

public:
    RemoteControl(Device *device) : device(device) {}

    void togglePower()
    {
        if (device->isEnabled())
        {
            device->disable();
        }
        else
        {
            device->enable();
        }
    }

    // 다른 메서드들도 유사하게 작성
};

// '추상화' 클래스 확장
class AdvancedRemoteControl : public RemoteControl
{
public:
    AdvancedRemoteControl(Device *device) : RemoteControl(device) {}

    void mute()
    {
        device->setVolume(0);
    }
};
