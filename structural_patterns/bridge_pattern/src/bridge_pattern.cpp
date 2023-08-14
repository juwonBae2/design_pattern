#include "bridge_pattern.hpp"

int main()
{
    Device *tv = new Tv();
    RemoteControl *remote = new RemoteControl(tv);

    remote->togglePower();

    Device *radio = new Radio();
    AdvancedRemoteControl *advancedRemote = new AdvancedRemoteControl(radio);

    advancedRemote->mute();

    // 메모리 해제
    delete tv;
    delete remote;
    delete radio;
    delete advancedRemote;

    return 0;
}
