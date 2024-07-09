#include <iostream>
#include "board.h"
#include "piece.h"
#include "pieceFactory.h"
#include "pieceShapes.h"



int main(){
    BlokusBoard board;

    PieceFactory pieceFactory;

    auto iPiece = pieceFactory.getPiece(blokusShapeType::iShapeType);
    auto bigCornerPiece = pieceFactory.getPiece(blokusShapeType::BigCornerShapeType);

    // BlokusPiece lBlokusPiece(lPiece);

    // board.placePiece(lBlokusPiece, 0, 0);

    // board.placePiece(lBlokusPiece, board.getWidth(), 0);

    // board.placePiece(lBlokusPiece, board.getWidth()-2, 0);

    // board.placePiece(lBlokusPiece, board.getWidth()-1, 0);

    // board.placePiece(lBlokusPiece, 0, board.getHeight()-2);

    // board.placePiece(lBlokusPiece, 0, board.getHeight()-1);

    // board.placePiece(lBlokusPiece, board.getWidth()-2, board.getHeight()-2);

    // board.placePiece(lBlokusPiece, board.getWidth()-1, board.getHeight()-2);


    board.placePiece(iPiece, 5, 5);

    board.placePiece(iPiece, 6, 5);

    board.placePiece(bigCornerPiece, 0, board.getHeight()-3);

    board.printBoardState();



    return 0;
}