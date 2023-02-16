#include "rightS.h"

RightS::RightS() : Piece(3, 3)
{
    *_array[1][1] = Color::Green;
    *_array[2][1] = Color::Green;
    *_array[0][2] = Color::Green;
    *_array[1][2] = Color::Green;
}

RightS::~RightS()
{
}