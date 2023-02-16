#ifndef SQUARE_H__
#define SQUARE_H__

#include "piece.h"

class Square : Piece
{
public:
    Square();
    ~Square();
    bool rotateLeft(const ColorArray2D& board);
    bool rotateRight(const ColorArray2D& board);
};

#endif // SQUARE_H__