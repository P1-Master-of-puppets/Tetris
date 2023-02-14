#ifndef LONGBAR_H__
#define LONGBAR_H__

#include "piece.h"

class LongBar : Piece
{
public:
    LongBar();
    ~LongBar();

    bool rotateRight(Color *board);
    bool rotateLeft(Color *board);
};

#endif // LONGBAR_H__
