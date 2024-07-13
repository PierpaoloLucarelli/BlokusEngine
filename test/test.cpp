#include <iostream>
#include <match.h>

std::string PASSED = "TEST PASSED";
std::string FAILED = "TEST FAILED";

int testGameOver(){
    BlokusBoard board;
    initializePieceMap();
    BlokusMatch match(board, true);
    match.newGame();
    match.playMove(blokusShapeType::zShapeType, 0, 0);
    match.playMove(blokusShapeType::zShapeType, 18, 17);
    match.playMove(blokusShapeType::iShapeType, 2, 3);
    match.playMove(blokusShapeType::iShapeType, 17, 12);
    match.playMove(blokusShapeType::smallCornerShapeType, 3, 8);
    match.playMove(blokusShapeType::smallCornerShapeType, 15, 10);
    match.playMove(blokusShapeType::bigCornerShapeType, 5, 7);
    match.playMove(blokusShapeType::bigCornerShapeType, 12, 7);
    match.playMove(blokusShapeType::singleShapeType, 1, 8);
    match.playMove(blokusShapeType::singleShapeType, 15, 6);
    match.playMove(blokusShapeType::crossShapeType, 8, 9);
    match.playMove(blokusShapeType::crossShapeType, 12, 10);
    match.playMove(blokusShapeType::tShapeType, 2, 10);
    match.playMove(blokusShapeType::tShapeType, 15, 17);
    match.playMove(blokusShapeType::oShapeType, 4, 13);
    match.playMove(blokusShapeType::oShapeType, 13, 16);

    match.getBoard().printBoardState();

    return match.gameOver();

}

int main(){
    std::cout << "Running tests." << std::endl;

    if(testGameOver()){
        std::cout << "testGameOver(): " + PASSED << std::endl;
    } else{
        std::cout << "testGameOver(): " + FAILED << std::endl;
    }
    return 0;
}