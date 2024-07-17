#include <iostream>
#include <board.h>
#include <pieceShapes.h>
#include <match.h>
#include <minimax.h>
#include <chrono>
#include <ncurses.h>


int main(){
    // initscr();   
    BlokusBoard board;
    initializePieceMap();
    BlokusMatch match(board);
    match.newGame();


    // match.getBoard().printBoardState();


    bool maxPlayer = true;

    auto start = std::chrono::high_resolution_clock::now();
    while(!match.gameOver(maxPlayer)){
        BlokusMatch matchCopy(match);
        BlokusMove bestMove = getNextMove(matchCopy, 20, maxPlayer);
        match.playMove(std::get<0>(bestMove), std::get<1>(bestMove), std::get<2>(bestMove), maxPlayer);
        match.getBoard().printBoardState();
        maxPlayer = !maxPlayer;

        //  bool valid = false;
        // while(!valid){
        //     auto pieces = match.getPiecesForPlayer(false);
        //     for(auto p : pieces){
        //         std::cout<<p<<" ";
        //     }
        //     std::cout<<std::endl;
        //     std::cout<<"Enter your Piece."<<std::endl;
        //     int p;
        //     std::cin >> p;
        //     std::cout<<"Enter your row."<<std::endl;
        //     int r;
        //     std::cin >> r;
        //     std::cout<<"Enter your col."<<std::endl;
        //     int c;
        //     std::cin >> c;

        //     valid = match.playMove(static_cast<blokusShapeType>(p), r, c, false);
        // }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Duration: " << duration.count() << " seconds" << std::endl;
}