#include <iostream>
#include <board.h>
#include <pieceShapes.h>
#include <match.h>


int main(){
    BlokusBoard board;
    initializePieceMap();
    BlokusMatch match(board, true);
    match.newGame();

    // auto bigCornerPiece = pieceFactory.getPiece(blokusShapeType::BigCornerShapeType);

    // board.placePiece(iPiece, 5, 5);

    // board.placePiece(iPiece, 6, 5);

    // board.placePiece(bigCornerPiece, 0, board.getHeight()-3);

    // board.placePiece(bigCornerPiece, 1, board.getHeight()-4);

    // board.printBoardState();

    match.playMove(blokusShapeType::iShapeType, 0, 0);
    match.playMove(blokusShapeType::oShapeType, 2, 2);
    match.playMove(blokusShapeType::zShapeType, 6, 6);
    match.getBoard().printBoardState();


    return 0;
}