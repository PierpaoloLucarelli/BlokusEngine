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

void printMove(BlokusMove& move){
    std::cout<<"piece: "<<std::get<0>(move) << " row: "<<std::get<1>(move)<<" col: " << std::get<2>(move)<<" Rot: " << (int)std::get<3>(move)<<std::endl;
}

void printMoves(std::vector<BlokusMove>& moves){
   for(auto m : moves){
       printMove(m);
   }
}

int main(){
    int nPlayers = 2;
    // BlokusBoard board;
    BlokusMatch match(nPlayers);
    match.newGame();
    match.printGame();

    // std::vector<BlokusMove> moves = match.getMovesFromPos(0);
    // printMoves(moves);
    // BlokusMove randMove = moves[0];
    // match.playMove(iShapeType, 0, 0, 0, 0);

    // match.playMove(iShapeType, 0, 9, 0, 1);

    // match.playMove(iShapeType, 13, 0, 0, 2);

    // match.playMove(iShapeType, 13, 9, 0, 3);

    // match.printGame();

    BlokusMove move = getNextMove(match, 4, 1);
    printMove(move);

    bool success = match.play_move_(move, 0);

    match.printGame();


    waitForExit();
    return 0;
}
