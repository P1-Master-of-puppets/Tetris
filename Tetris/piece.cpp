#include "piece.h"

Piece::Piece(int width, int height){
    
    _array = new ColorArray2D(width, height);
}

Piece::~Piece(){
    delete  _array;
}

bool Piece::rotateRight(const ColorArray2D& board)
{
    //TODO IMPLEMENT
    return false;
}

bool Piece::rotateLeft(const ColorArray2D& board)
{
    //TODO IMPLEMENT
    return false;
}

bool Piece::isColliding(const ColorArray2D& board)
{
    //TODO IMPLEMENT
    return false;
}

const Coordinate& Piece::getCoordinate()
{
    return _coordinate;
}

const ColorArray2D* Piece::getPiece()
{
    return _array;
}
