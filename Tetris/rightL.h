#ifndef RightL_H__
#define RightL_H__

#include "piece.h"

class RightL : Piece
{
public:
    RightL();
    ~RightL();
    bool rotateRight(const ColorArray2D& board);
    bool rotateLeft(const ColorArray2D& board);
};

#endif // RightL_H__