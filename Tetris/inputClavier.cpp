#include "inputClavier.h"
#include <iostream>
// #include <conio.h>
#include <string>
#include <windows.h>

using namespace std;

bool isUpPressed()
{
    if (GetAsyncKeyState(VK_UP)) return true;
    else return false;
}

bool isDownPressed()
{
    if (GetAsyncKeyState(VK_DOWN)) return true;
    else return false;
}

bool isLeftPressed()
{
    if (GetAsyncKeyState(VK_LEFT)) return true;
    else return false;
}

bool isRightPressed()
{
    if (GetAsyncKeyState(VK_RIGHT)) return true;
    else return false;
}

int main ()
{
    if(isUpPressed())
    {
        cout << "Up arrow" << endl;
    }
    while (true)
    {
        int waitingTime = 130; // Temps entre chaque touche appuyée
        if(isUpPressed())
        {
            cout << "Up arrow" << endl;
            // break;
            Sleep(waitingTime);
        }
        if(isDownPressed())
        {
            cout << "Down arrow" << endl;
            // break;
            Sleep(waitingTime);
        }
        if(isLeftPressed())
        {
            cout << "Left arrow" << endl;
            // break;
            Sleep(waitingTime);
        }
        if(isRightPressed())
        {
            cout << "Right arrow" << endl;
            // break;
            Sleep(waitingTime);
        }
    }
    return 0;
}

// https://www.youtube.com/watch?v=nU-nXlAlX7g