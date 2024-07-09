#include <iostream>
#include <board.h>

#include <match.h>


int main(){
    BlokusBoard board;
    BlokusMatch match(board, true);
    PieceFactory pieceFactory;

    match.newGame(pieceFactory);

    auto iPiece = pieceFactory.getPiece(blokusShapeType::iShapeType);
    // auto bigCornerPiece = pieceFactory.getPiece(blokusShapeType::BigCornerShapeType);

    // board.placePiece(iPiece, 5, 5);

    // board.placePiece(iPiece, 6, 5);

    // board.placePiece(bigCornerPiece, 0, board.getHeight()-3);

    // board.placePiece(bigCornerPiece, 1, board.getHeight()-4);

    // board.printBoardState();

    // seems kinda stupid to have a set containing the actual pieces. Maybe best to just have the enums in the sets and have the piece objects as global vars.

    match.playMove(iPiece, 0, 0);
    match.getBoard().printBoardState();


    return 0;
}