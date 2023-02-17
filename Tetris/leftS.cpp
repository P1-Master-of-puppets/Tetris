#include "leftS.h"

LeftS::LeftS() : Piece(3, 3)
{
    (*_array)[0][1] = Color::Red;
    (*_array)[1][1] = Color::Red;
    (*_array)[1][2] = Color::Red;
    (*_array)[2][2] = Color::Red;
}

LeftS::~LeftS()
{
}

