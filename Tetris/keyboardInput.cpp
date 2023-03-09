#include "keyboardInput.h"

bool KeyboardInput::translateLeft(){
    //Left arrow
    return GetAsyncKeyState(VK_LEFT);
}

bool KeyboardInput::translateRight(){
    //Right arrow
    return GetAsyncKeyState(VK_RIGHT);
}

bool KeyboardInput::rotateRight(){
    //X
    return GetAsyncKeyState(0x58);
}

bool KeyboardInput::rotateLeft(){
    //Z
    return GetAsyncKeyState(0x5A);
}

bool KeyboardInput::dropInstant()
{
    // Space
    return GetAsyncKeyState(0x20);
}

bool KeyboardInput::dropFaster()
{
    //Down arrow
    return GetAsyncKeyState(VK_DOWN);
}

bool KeyboardInput::holdPiece()
{
    //C
    return GetAsyncKeyState(0x43);
}

bool KeyboardInput::menu()
{
    //M
    return GetAsyncKeyState(0x4D);
}

