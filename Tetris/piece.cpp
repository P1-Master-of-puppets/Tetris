#include "piece.h"

Piece::Piece(int width, int height){
    
    _array = new ColorArray2D(width, height);
    _coordinate.x = 5;
    _coordinate.y = 0;
}

Piece::~Piece(){
    delete  _array;
}

bool Piece::translateRight(ColorArray2D& board)
{
    int newCoordsX = _coordinate.x + 1;
    Color** gridPiece = _array->getGrid();
    Color** gridBoard = board.getGrid();
    for (int i = 0; i < _array->getWidth(); i++)
    {
        for (int j = 0; i < _array->getHeight(); i++)
        {
            if (gridPiece[i][j] != Color::Transparent)
            {
                if (i + newCoordsX > board.getWidth() || gridBoard[i + newCoordsX][j + _coordinate.y] != Color::Transparent)
                {
                    return false;
                }
            }
        }
    }
    _coordinate.x = newCoordsX;
    return true; 
}

bool Piece::translateLeft(ColorArray2D& board)
{
    int newCoordsX = _coordinate.x - 1;
    Color** gridPiece = _array->getGrid();
    Color** gridBoard = board.getGrid();
    for (int i = 0; i < _array->getWidth(); i++)
    {
        for (int j = 0; i < _array->getHeight(); i++)
        {
            if (gridPiece[i][j] != Color::Transparent)
            {
                if (i + newCoordsX < 0 || gridBoard[i + newCoordsX][j + _coordinate.y] != Color::Transparent)
                {
                    return false;
                }
            }
        }
    }
    _coordinate.x = newCoordsX;
    return true;
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
