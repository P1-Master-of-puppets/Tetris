#include "keyboardInput.h"

bool KeyboardInput::translateLeft(){
    //Left arrow or "A"
    return GetAsyncKeyState(VK_LEFT);
}

bool KeyboardInput::translateRight(){
    //Right arrow or "D"
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
    return false;
}

bool KeyboardInput::dropFaster()
{
    return GetAsyncKeyState(VK_DOWN);
}

bool KeyboardInput::holdPiece()
{
    return false;
}

bool KeyboardInput::menu()
{
    return false;
}

