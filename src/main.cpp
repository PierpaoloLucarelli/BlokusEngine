#include <iostream>
#include <board.h>
#include <pieceShapes.h>
#include <match.h>
#include <minimax.h>
#include <chrono>


int main(){
    BlokusBoard board;
    initializePieceMap();
    BlokusMatch match(board, true);
    match.newGame();

    std::cout << match.evaluatePosition() << std::endl;

    match.getBoard().printBoardState();


    bool maximise = true;

    while(!match.gameOver()){
        BlokusMove bestMove = getNextMove(match, 4, maximise);
        match.playMove(std::get<0>(bestMove), std::get<1>(bestMove), std::get<2>(bestMove));
        match.getBoard().printBoardState();
        maximise = !maximise;
    }
}