#include <iostream>
#include <board.h>
#include <pieceShapes.h>
#include <match.h>
#include "minimax.h"
#include <chrono>
#include <thread>

void waitForExit() {
    int t;
    std::cout << "Game finished! Press any key to exit!";
    std::cin >> t;
}

void printMoves(std::vector<BlokusMove> moves){
   for(auto m : moves){
       std::cout<<"piece: "<<std::get<0>(m) << " row: "<<std::get<1>(m)<<" col: " << std::get<2>(m)<<" Rot: " << (int)std::get<3>(m)<<std::endl;
   }
}

int main(){
    BlokusBoard board;
    initializePieceMap();
    BlokusMatch match(board);
    match.newGame();
    match.printGame();

    std::vector<BlokusMove> moves = match.getMovesFromPos(0);
    printMoves(moves);


    bool maxPlayer = true;
    waitForExit();
    return 0;
}
