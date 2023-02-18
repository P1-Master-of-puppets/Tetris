#include "rightL.h"

RightL::RightL() : Piece(3, 3)
{
    (*_array)[0][1] = Color::Orange;
    (*_array)[1][1] = Color::Orange;
    (*_array)[2][1] = Color::Orange;
    (*_array)[2][2] = Color::Orange;
}

RightL::~RightL()
{
}
