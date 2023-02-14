#include "piece.h"

Piece::Piece(int height, int width){
    
}

Piece::~Piece(){

}

Color* Piece::getPiece(){
    return _piece; 
}

bool Piece::isColliding(Color* board){
    return true;
}

bool Piece::rotateLeft(Color* board){
    return true;
}

bool Piece::rotateRight(Color* board){
    return true;
}


