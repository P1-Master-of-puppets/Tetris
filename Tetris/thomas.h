#ifndef THOMAS_H__
#define THOMAS_H__

#include "piece.h"

class Thomas : Piece
{
public:
    Thomas();
    ~Thomas();
    bool rotateRight(const ColorArray2D& board);
    bool rotateLeft(const ColorArray2D& board);
};

#endif // THOMAS_H__