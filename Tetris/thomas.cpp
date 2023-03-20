#include "thomas.h"

Thomas::Thomas() : Piece(3, 3)
{
    (*_array)[1][0] = Color::Purple;
    (*_array)[1][1] = Color::Purple;
    (*_array)[1][2] = Color::Purple;
    (*_array)[2][1] = Color::Purple;
    _coordinate.y = 1;
    _typePiece = THOMAS;
}

Thomas::~Thomas()
{
}

bool Thomas::resetPieceTodefault()
{
    (*_array)[0][0] = Color::Transparent;
    (*_array)[1][0] = Color::Purple;
    (*_array)[2][0] = Color::Transparent;
    (*_array)[0][1] = Color::Transparent;
    (*_array)[1][1] = Color::Purple;
    (*_array)[2][1] = Color::Purple;
    (*_array)[0][2] = Color::Transparent;
    (*_array)[1][2] = Color::Purple;
    (*_array)[2][2] = Color::Transparent;

    return true;
}
