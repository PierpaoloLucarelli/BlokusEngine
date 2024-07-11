#include <iostream>
#include <board.h>
#include <pieceShapes.h>
#include <match.h>


int main(){
    BlokusBoard board;
    initializePieceMap();
    BlokusMatch match(board, true);
    match.newGame();

    match.playMove(blokusShapeType::zShapeType, 0, 0);
    match.playMove(blokusShapeType::iShapeType, 9, 5);
    match.getBoard().printBoardState();

    return 0;
}