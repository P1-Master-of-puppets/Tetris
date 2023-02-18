#include "leftL.h"

LeftL::LeftL() : Piece(3, 3)
{
    (*_array)[0][1] = Color::Blue;
    (*_array)[1][1] = Color::Blue;
    (*_array)[2][1] = Color::Blue;
    (*_array)[2][0] = Color::Blue;
}

LeftL::~LeftL()
{
}