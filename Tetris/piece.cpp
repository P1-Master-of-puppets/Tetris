#include "piece.h"

Piece::Piece(int width, int height){
    _array = new ColorArray2D(width, height);
}

Piece::~Piece(){
    delete  _array;
}

bool Piece::isColliding(const Piece* future, const ColorArray2D& board)
{
    
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
