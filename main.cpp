#include "board.h"
#include "piece.h"



int main(){
    BlokusBoard board;

    std::vector<std::vector<bool>> lPiece = {
        {1,0},
        {1,1}
    };

    BlokusPiece lBlokusPiece(lPiece);

    board.placePiece(lBlokusPiece, 0, 0);

    board.placePiece(lBlokusPiece, board.getWidth(), 0);

    board.placePiece(lBlokusPiece, board.getWidth()-2, 0);

    board.placePiece(lBlokusPiece, board.getWidth()-1, 0);

    board.placePiece(lBlokusPiece, 0, board.getHeight()-2);

    board.placePiece(lBlokusPiece, 0, board.getHeight()-1);

    board.placePiece(lBlokusPiece, board.getWidth()-2, board.getHeight()-2);

    board.placePiece(lBlokusPiece, board.getWidth()-1, board.getHeight()-2);

    board.printBoardState();

    return 0;
}