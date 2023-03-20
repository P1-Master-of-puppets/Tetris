#include "longBar.h"

LongBar::LongBar() : Piece(4, 4)
{
    (*_array)[2][0] = Color::Cyan;
    (*_array)[2][1] = Color::Cyan;
    (*_array)[2][2] = Color::Cyan;
    (*_array)[2][3] = Color::Cyan;
    vertical = true;
    _coordinate.y = 0;
    _typePiece = LONGBAR;
}

LongBar::~LongBar()
{
}

bool LongBar::rotateBar(const ColorArray2D& board){
        
    ColorArray2D* newArray = new ColorArray2D(_array->getWidth(), _array->getHeight());


    if(vertical){
        newArray->fill(Color::Transparent);
        (*newArray)[2][0] = Color::Cyan;
        (*newArray)[2][1] = Color::Cyan;
        (*newArray)[2][2] = Color::Cyan;
        (*newArray)[2][3] = Color::Cyan;
    }
    else{
        newArray->fill(Color::Transparent);
        (*newArray)[0][2] = Color::Cyan;
        (*newArray)[1][2] = Color::Cyan;
        (*newArray)[2][2] = Color::Cyan;
        (*newArray)[3][2] = Color::Cyan;
    }

    if(isColliding(newArray, _coordinate, board)){
        delete newArray;
        return false;
    }

    delete _array;

    _array = newArray;

    vertical = !vertical;

    return true;
}

bool LongBar::rotateLeft(const ColorArray2D& board){
    return rotateBar(board);
}


bool LongBar::rotateRight(const ColorArray2D& board){
    return rotateBar(board);
}

bool LongBar::resetPieceTodefault()
{
    (*_array)[0][0] = Color::Transparent;
    (*_array)[1][0] = Color::Transparent;
    (*_array)[2][0] = Color::Cyan;
    (*_array)[3][0] = Color::Transparent;
    (*_array)[0][1] = Color::Transparent;
    (*_array)[1][1] = Color::Transparent;
    (*_array)[2][1] = Color::Cyan;
    (*_array)[3][1] = Color::Transparent;
    (*_array)[0][2] = Color::Transparent;
    (*_array)[1][2] = Color::Transparent;
    (*_array)[2][2] = Color::Cyan;
    (*_array)[3][2] = Color::Transparent;
    (*_array)[0][3] = Color::Transparent;
    (*_array)[1][3] = Color::Transparent;
    (*_array)[2][3] = Color::Cyan;
    (*_array)[3][3] = Color::Transparent;

    return true;
}
