#include <iostream>
#include <board.h>
#include <pieceShapes.h>
#include <match.h>
#include "minimax.h"

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
    int nPlayers = 2;
    // BlokusBoard board;
    BlokusMatch match(nPlayers);
    match.newGame();
    match.printGame();

    std::vector<BlokusMove> moves = match.getMovesFromPos(0);
    printMoves(moves);
    BlokusMove randMove = moves[0];
    match.playMove(iShapeType, 0, 0, 0, 0);

    match.playMove(iShapeType, 0, 9, 0, 1);

    match.playMove(iShapeType, 13, 0, 0, 2);

    match.playMove(iShapeType, 13, 9, 0, 3);

    match.printGame();


    bool maxPlayer = true;
    waitForExit();
    return 0;
}
