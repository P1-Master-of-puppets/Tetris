#include "testPiece.h"

void TestPiece::testTranslateRight(){
    std::cout << "testTranslaterRight" << std::endl;
}

void TestPiece::testTranslateLeft(){
    std::cout << "testTranslaterLeft" << std::endl;
}

void TestPiece::testRotateRight(){






    std::cout << "testRotateRight" << std::endl;
}

void TestPiece::testRotateLeft(){
    std::cout << "testRotateLeft" << std::endl;
}

void TestPiece::testIsColliding(){

    std::cout << "\n\ntestIsColliding\n\n" << std::endl;



    ColorArray2D board(10,20);

    board.fill(Color::Transparent);
    ConsoleDisplay monDisplay;
    Piece* maPiece = new Thomas();
    Coordinate newCoords;
    newCoords.x = 5;
    newCoords.y = 14;

    maPiece->setCoordinate(newCoords);

    board.getGrid()[5][15] = Color::Blue;
    board.getGrid()[6][15] = Color::Blue;
    board.getGrid()[7][15] = Color::Blue;

    std::cout << "Board : \n" << std::endl;

    monDisplay.display2DArray(board);

    std::cout << maPiece->isColliding(maPiece->getPiece(), maPiece->getCoordinate(), board) << "\n\n";


}
