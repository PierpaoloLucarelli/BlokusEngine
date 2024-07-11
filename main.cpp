#include <iostream>
#include <board.h>
#include <pieceShapes.h>
#include <match.h>


int main(){
    BlokusBoard board;
    initializePieceMap();
    BlokusMatch match(board, true);
    match.newGame();

    std::cout << match.evaluatePosition() << std::endl;

    match.playMove(blokusShapeType::zShapeType, 0, 0);
    match.playMove(blokusShapeType::iShapeType, 9, 5);
    match.playMove(blokusShapeType::iShapeType, 3, 5);
    match.playMove(blokusShapeType::iShapeType, 2, 5);
    match.playMove(blokusShapeType::zShapeType, 7, 2);
    match.getBoard().printBoardState();

    std::cout << match.evaluatePosition() << std::endl;

    return 0;
}