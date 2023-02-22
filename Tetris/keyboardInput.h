#ifndef KEYBOARD_INPUT
#define KEYBOARD_INPUT

class KeyboardInput{

    public:
        static bool left();
        static bool right();
        static bool rotateRight();
        static bool rotateLeft();
        static bool dropFaster();
        static bool dropOnce();
};

#endif