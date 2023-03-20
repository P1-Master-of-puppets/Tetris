#ifndef THOMAS_H__
#define THOMAS_H__

#include <iostream>
#include <typeinfo>
#include "piece.h"
#include "type.h"


class Thomas : public Piece
{
public:
    Thomas();
    ~Thomas();
    virtual bool resetPieceTodefault();
};

#endif // THOMAS_H__