#include "bridge_pattern.hpp"

int main()
{
    TVDevice tv;
    RadioDevice radio;

    SmartRemoteControl smartRemote(&tv);
    BasicRemoteControl basicRemote(&radio);

    smartRemote.pressButton();
    basicRemote.pressButton();

    return 0;
}
