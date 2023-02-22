#include "inputKeyboard.h"

static bool KeyboardInput::left(){
    return GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(0x44);
}

static bool KeyboardInput::right(){
    return GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(0x41);
}

static bool KeyboardInput::rotateRight(){
    return GetAsyncKeyState(0x45);
}

static bool KeyboardInput::rotateLeft(){
    return GetAsyncKeyState(0x51);
}

static bool KeyboardInput::dropFaster(){
    return GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState(0x53);
}

static bool KeyboardInput::dropOnce(){
    return GetAsyncKeyState(VK_SPACE);
}