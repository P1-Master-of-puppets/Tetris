#ifndef LEFTL_H__
#define LEFTL_H__

#include "piece.h"
#include "type.h"

class LeftL : public Piece
{
public:
    LeftL();
    ~LeftL();

    virtual bool resetPieceTodefault();
    
};

#endif // LEFTL_H__
