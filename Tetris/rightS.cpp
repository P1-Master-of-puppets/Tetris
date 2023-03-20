#include "rightS.h"

RightS::RightS() : Piece(3, 3)
{
    isVertical = false;
    (*_array)[1][1] = Color::Green;
    (*_array)[1][2] = Color::Green;
    (*_array)[2][0] = Color::Green;
    (*_array)[2][1] = Color::Green;
    _coordinate.y = 1;
    _typePiece = RIGHT_S;
}

RightS::~RightS()
{
}

bool RightS::rotateS(const ColorArray2D& board){
    if(isVertical){
        if(Piece::rotateLeft(board)){
            isVertical = false;
            return true;
        }
    }
    else{
        if(Piece::rotateRight(board)){
            isVertical = true;
            return true;
        }
    }

    return false;
}

bool RightS::rotateLeft(const ColorArray2D& board){
    return rotateS(board);
}

bool RightS::rotateRight(const ColorArray2D& board){
    return rotateS(board);
}

bool RightS::resetPieceTodefault()
{
    (*_array)[0][0] = Color::Transparent;
    (*_array)[1][0] = Color::Transparent;
    (*_array)[2][0] = Color::Green;
    (*_array)[0][1] = Color::Transparent;
    (*_array)[1][1] = Color::Green;
    (*_array)[2][1] = Color::Green;
    (*_array)[0][2] = Color::Transparent;
    (*_array)[1][2] = Color::Green;
    (*_array)[2][2] = Color::Transparent;

    return true;
}