#include "thomas.h"

Thomas::Thomas() : Piece(3, 3)
{
    *_array[0][1] = Color::Purple;
    *_array[1][1] = Color::Purple;
    *_array[2][1] = Color::Purple;
    *_array[1][2] = Color::Purple;
}

Thomas::~Thomas()
{
}

bool Thomas::rotateRight(const ColorArray2D& board){

    Piece* temp = new Thomas();

    for(int i = 0; i < _array->getWidth(); i++){
        for(int j = 0; j < _array->getHeight(); j++){
            *(temp->getPiece())[i][j] = *_array[i][j];
        }
    }

    if(isColliding(temp, board)){
        return false;
    }



    return true;
}


bool Thomas::rotateLeft(const ColorArray2D& board){
    return true;
}