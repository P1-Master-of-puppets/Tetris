#include "square.h"

Square::Square() : Piece(2, 2)
{
    _array->fill(Color::Yellow);
    _typePiece = SQUARE;
}

Square::~Square()
{
}

bool Square::rotateLeft(const ColorArray2D& board){
    return true;
}

bool Square::rotateRight(const ColorArray2D& board){
    return true;
}