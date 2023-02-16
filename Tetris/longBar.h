#ifndef LONGBAR_H__
#define LONGBAR_H__

#include "piece.h"

class LongBar : Piece
{
public:
    LongBar();
    ~LongBar();
    bool rotateBar(const ColorArray2D& board);
    bool rotateLeft(const ColorArray2D& board);
    bool rotateRight(const ColorArray2D& board);
private:
    bool vertical;
};

#endif // LONGBAR_H__
