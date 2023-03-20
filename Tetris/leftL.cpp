#include "leftL.h"

LeftL::LeftL() : Piece(3, 3)
{
    (*_array)[1][0] = Color::Blue;
    (*_array)[1][1] = Color::Blue;
    (*_array)[1][2] = Color::Blue;
    (*_array)[2][2] = Color::Blue;
    _coordinate.y = 1;
    _typePiece = LEFT_L;
}

LeftL::~LeftL()
{
}

bool LeftL::resetPieceTodefault()
{
    (*_array)[0][0] = Color::Transparent;
    (*_array)[1][0] = Color::Blue;
    (*_array)[2][0] = Color::Transparent;
    (*_array)[0][1] = Color::Transparent;
    (*_array)[1][1] = Color::Blue;
    (*_array)[2][1] = Color::Transparent;
    (*_array)[0][2] = Color::Transparent;
    (*_array)[1][2] = Color::Blue;
    (*_array)[2][2] = Color::Blue;

    return true;
}