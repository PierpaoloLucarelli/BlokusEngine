#include <iostream>
#include <board.h>
#include <pieceShapes.h>
#include <match.h>
#include <minimax.h>
#include <chrono>


int main(){
    BlokusBoard board;
    initializePieceMap();
    BlokusMatch match(board);
    match.newGame();

    std::cout << match.evaluatePosition() << std::endl;

    match.getBoard().printBoardState();


    bool maxPlayer = true;

    auto start = std::chrono::high_resolution_clock::now();
    while(!match.gameOver(maxPlayer)){
        BlokusMatch matchCopy(match);
        BlokusMove bestMove = getNextMove(matchCopy, 20, maxPlayer);
        match.playMove(std::get<0>(bestMove), std::get<1>(bestMove), std::get<2>(bestMove), maxPlayer);
        match.getBoard().printBoardState();
        maxPlayer = !maxPlayer;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Duration: " << duration.count() << " seconds" << std::endl;
}