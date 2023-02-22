#include "leftL.h"

LeftL::LeftL() : Piece(3, 3)
{
    (*_array)[1][0] = Color::Blue;
    (*_array)[1][1] = Color::Blue;
    (*_array)[1][2] = Color::Blue;
    (*_array)[2][2] = Color::Blue;
}

LeftL::~LeftL()
{
}