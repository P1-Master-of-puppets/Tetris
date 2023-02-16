#include "piece.h"

Piece::Piece(int width, int height){
    
    _array = new ColorArray2D(width, height);
    _coordinate.x = 5;
    _coordinate.y = 0;
}

Piece::~Piece(){
    delete  _array;
}

bool Piece::translateRight(const ColorArray2D& board)
{
    return false;
}

bool Piece::translateLeft(const ColorArray2D& board)
{
    return false;
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
