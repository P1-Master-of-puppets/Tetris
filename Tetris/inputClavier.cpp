#include <iostream>
// #include <conio.h>
#include <string>
#include <windows.h>

using namespace std;

int main ()
{
    int waitingTime = 130; // Temps minimal entre chaque input, peut être ajusté en fonction des besoins
    while (true)
    {
        if (GetAsyncKeyState(VK_UP))
        {
            cout << "Up arrow" << endl;
            // break;
            Sleep(waitingTime);
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            cout << "Down arrow" << endl;
            // break;
            Sleep(waitingTime);
        }
        if (GetAsyncKeyState(VK_LEFT))
        {
            cout << "Left arrow" << endl;
            // break;
            Sleep(waitingTime);
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            cout << "Right arrow" << endl;
            // break;
            Sleep(waitingTime);
        }
        // On peut rajouter des touches ici
    }
    return 0;
}

// https://www.youtube.com/watch?v=nU-nXlAlX7g