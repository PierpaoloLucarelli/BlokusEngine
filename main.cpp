#include <iostream>
#include <board.h>
#include <piece.h>
#include <pieceFactory.h>
#include <pieceShapes.h>



int main(){
    BlokusBoard board;

    PieceFactory pieceFactory;

    auto iPiece = pieceFactory.getPiece(blokusShapeType::iShapeType);
    auto bigCornerPiece = pieceFactory.getPiece(blokusShapeType::BigCornerShapeType);

    board.placePiece(iPiece, 5, 5);

    board.placePiece(iPiece, 6, 5);

    board.placePiece(bigCornerPiece, 0, board.getHeight()-3);

    board.placePiece(bigCornerPiece, 1, board.getHeight()-4);

    board.printBoardState();


    return 0;
}