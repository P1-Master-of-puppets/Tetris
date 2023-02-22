#include "keyboardInput.h"

bool KeyboardInput::translateLeft(){
    //Left arrow or "A"
    return GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(0x41);
}

bool KeyboardInput::translateRight(){
    //Right arrow or "D"
    return GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(0x44);
}

bool KeyboardInput::rotateRight(){
    //E
    return GetAsyncKeyState(0x45);
}

bool KeyboardInput::rotateLeft(){
    //Q
    return GetAsyncKeyState(0x51);
}

bool KeyboardInput::dropFaster(){
    //Down arrow or "S"
    return GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState(0x53);
}

bool KeyboardInput::dropOnce(){
    //Space
    return GetAsyncKeyState(VK_SPACE);
}