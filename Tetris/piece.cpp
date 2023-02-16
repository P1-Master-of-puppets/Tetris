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

bool Piece::translateLeft(const ColorArray2D& board)
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



bool Piece::isColliding(const Piece* future, const ColorArray2D& board){
    
    for(int i = 0; i < future->getPiece()->getWidth(); i++){
        for(int j = 0; j < future->getPiece()->getHeight(); j++){
            if(*(future->getPiece())[i][j] != Color::Transparent){
                if(board[future->getCoordinate().x + i][future->getCoordinate().y + j] != Color::Transparent
                   || future->getCoordinate().x + i < 0 
                   || future->getCoordinate().x + i > board.getWidth()
                   || future->getCoordinate().y + j < 0
                   || future->getCoordinate().y + j > board.getHeight()){
                    return false;
                }
            }
        }
    }

    return true;
}

const Coordinate& Piece::getCoordinate() const
{
    return _coordinate;
}

ColorArray2D* Piece::getPiece() const
{
    return _array;
}
