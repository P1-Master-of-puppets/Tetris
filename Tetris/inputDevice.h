#ifndef INPUT_DEVICE
#define INPUT_DEVICE

#include "keyboardInput.h"

class InputDevice{

    public:
        bool left();
        bool right();
        bool rotateRight();
        bool rotateLeft();
        bool dropFaster();
        bool dropOnce();
};



#endif