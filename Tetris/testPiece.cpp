#include "testPiece.h"

void TestPiece::testTranslateRight(){
    std::cout << "testTranslaterRight" << std::endl;
}

void TestPiece::testTranslateLeft(){
    std::cout << "\ntestTranslateLeft\n" << std::endl;
}

void TestPiece::testRotateRight(){
    std::cout << "\ntestRotateRight\n" << std::endl;
    
    
    Piece* maPiece = new LeftS();
    ConsoleDisplay monDisplay;
    ColorArray2D board(10,20);

    std::cout << "Piece actuelle :" << std::endl;
    monDisplay.display2DArray(*(maPiece->getPiece()));

    std::cout << "Piece apres rotateRight :" << std::endl;
    maPiece->rotateRight(board);
    monDisplay.display2DArray(*(maPiece->getPiece()));

    std::cout << "Piece apres rotateRight :" << std::endl;
    maPiece->rotateRight(board);
    monDisplay.display2DArray(*(maPiece->getPiece()));

    std::cout << "Piece apres rotateRight :" << std::endl;
    maPiece->rotateRight(board);
    monDisplay.display2DArray(*(maPiece->getPiece()));

    std::cout << "Piece apres rotateRight :" << std::endl;
    maPiece->rotateRight(board);
    monDisplay.display2DArray(*(maPiece->getPiece()));
}

void TestPiece::testRotateLeft(){
    std::cout << "\ntestRotateLeft\n" << std::endl;
    
    
    Piece* maPiece = new LeftS();
    ConsoleDisplay monDisplay;
    ColorArray2D board(10,20);

    std::cout << "Piece actuelle :" << std::endl;
    monDisplay.display2DArray(*(maPiece->getPiece()));

    std::cout << "Piece apres rotateRight :" << std::endl;
    maPiece->rotateLeft(board);
    monDisplay.display2DArray(*(maPiece->getPiece()));

    std::cout << "Piece apres rotateRight :" << std::endl;
    maPiece->rotateLeft(board);
    monDisplay.display2DArray(*(maPiece->getPiece()));

    std::cout << "Piece apres rotateRight :" << std::endl;
    maPiece->rotateLeft(board);
    monDisplay.display2DArray(*(maPiece->getPiece()));

    std::cout << "Piece apres rotateRight :" << std::endl;
    maPiece->rotateLeft(board);
    monDisplay.display2DArray(*(maPiece->getPiece()));
}

void TestPiece::testIsColliding(){

    std::cout << "\ntestIsColliding\n" << std::endl;

    ColorArray2D board(10,20);

    board.fill(Color::Transparent);
    ConsoleDisplay monDisplay;
    Piece* maPiece = new Thomas();
    Coordinate newCoords;

    board.getGrid()[15][5] = Color::Blue;
    board.getGrid()[15][7] = Color::Blue;
    board.getGrid()[15][6] = Color::Blue;


    std::cout << "Test de collision avec pieces dans board : ";
    newCoords.x = 5;
    newCoords.y = 14;
    maPiece->setCoordinate(newCoords);
    if(maPiece->isColliding(maPiece->getPiece(), maPiece->getCoordinate(), board)){
        std::cout << " Reussite!" << std::endl;
    }

    std::cout << "Test de collision avec le bas du board: ";
    newCoords.x = 5;
    newCoords.y = 18;
    maPiece->setCoordinate(newCoords);
    if(maPiece->isColliding(maPiece->getPiece(), maPiece->getCoordinate(), board)){
        std::cout << " Reussite!" << std::endl;
    }

    std::cout << "Test de collision avec cote droit du board: ";
    newCoords.x = 8;
    newCoords.y = 14;
    maPiece->setCoordinate(newCoords);
    if(maPiece->isColliding(maPiece->getPiece(), maPiece->getCoordinate(), board)){
        std::cout << " Reussite!" << std::endl;
    }

    std::cout << "Test de collision avec cote gauche du board: ";
    newCoords.x = -1;
    newCoords.y = 14;
    maPiece->setCoordinate(newCoords);
    if(maPiece->isColliding(maPiece->getPiece(), maPiece->getCoordinate(), board)){
        std::cout << " Reussite!" << std::endl;
    }

    std::cout << "Test de collision avec rien: ";
    newCoords.x = 3;
    newCoords.y = 7;
    maPiece->setCoordinate(newCoords);
    if(!maPiece->isColliding(maPiece->getPiece(), maPiece->getCoordinate(), board)){
        std::cout << " Reussite!" << std::endl;
    }


}
