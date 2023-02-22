#ifndef INPUT_DEVICE
#define INPUT_DEVICE

class InputDevice {

public:
    InputDevice();
    bool left();
    bool right();
    bool rotateRight();
    bool rotateLeft();
    bool dropFaster();
    bool dropOnce();
};

#endif