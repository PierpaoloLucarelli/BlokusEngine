#include <iostream>
#include <board.h>
#include <pieceShapes.h>
#include <match.h>


int main(){
    BlokusBoard board;
    initializePieceMap();
    BlokusMatch match(board, true);
    match.newGame();

    match.playMove(blokusShapeType::zShapeType, 8, 7);
    // match.playMove(blokusShapeType::iShapeType, 5, 0);
    // match.playMove(blokusShapeType::iShapeType, 1, 5);
    // match.playMove(blokusShapeType::oShapeType, 2, 2);
    // match.playMove(blokusShapeType::zShapeType, 6, 6);
    match.getBoard().printBoardState();


    return 0;
}