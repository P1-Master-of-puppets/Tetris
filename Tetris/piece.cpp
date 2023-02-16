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



bool Piece::isColliding(const ColorArray2D* future, const Coordinate pos, const ColorArray2D& board){
    
    for(int i = 0; i < future->getWidth(); i++){
        for(int j = 0; j < future->getHeight(); j++){
            if(*future[i][j] != Color::Transparent){
                if(board[pos.x + i][pos.y + j] != Color::Transparent
                   || pos.x + i < 0 
                   || pos.x + i > board.getWidth()
                   || pos.y + j < 0
                   || pos.y + j > board.getHeight()){
                    return true;
                }
            }
        }
    }

    return false;
}

bool Piece::rotateLeft(const ColorArray2D& board){
    
    ColorArray2D* newArray = new ColorArray2D(_array->getWidth(), _array->getHeight());

    for(int i = 0; i < _array->getWidth(); i++){
        for(int j = 0; j < _array->getHeight(); j++){
            *newArray[i][j] = *_array[_array->getWidth()-1-j][i];
        }
    }

    if(isColliding(newArray, _coordinate, board)){
        delete newArray;
        return false;
    }

    delete _array;

    _array = newArray;

    return true;
}

bool Piece::rotateRight(const ColorArray2D& board){

    ColorArray2D* newArray = new ColorArray2D(_array->getWidth(), _array->getHeight());

    for(int i = 0; i < _array->getWidth(); i++){
        for(int j = 0; j < _array->getHeight(); j++){
            *newArray[i][j] = *_array[j][_array->getWidth()-1-i];
        }
    }

    if(isColliding(newArray, _coordinate, board)){
        delete newArray;
        return false;
    }

    delete _array;

    _array = newArray;

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
