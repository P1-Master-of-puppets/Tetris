#include "rightL.h"

RightL::RightL() : Piece(3, 3)
{
    (*_array)[2][0] = Color::Orange;
    (*_array)[1][0] = Color::Orange;
    (*_array)[1][1] = Color::Orange;
    (*_array)[1][2] = Color::Orange;
    _coordinate.y = 2;
    _typePiece = RIGHT_L;
}

RightL::~RightL()
{
}

bool RightL::resetPieceTodefault()
{
    (*_array)[0][0] = Color::Transparent;
    (*_array)[1][0] = Color::Orange;
    (*_array)[2][0] = Color::Orange;
    (*_array)[0][1] = Color::Transparent;
    (*_array)[1][1] = Color::Orange;
    (*_array)[2][1] = Color::Transparent;
    (*_array)[0][2] = Color::Transparent;
    (*_array)[1][2] = Color::Orange;
    (*_array)[2][2] = Color::Transparent;

    return true;
}
