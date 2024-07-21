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


    
    // match.playMove(blokusShapeType::iShapeType, 0, 0, 0, true);
    // match.getBoard().printBoardState();
    // return 0;

    // auto moves = match.getMovesFromPos(true);
    // for(auto m : moves){
    //     std::cout<<"piece: "<<std::get<0>(m) << " row: "<<std::get<1>(m)<<" col: " << std::get<2>(m)<<" Rot: " << (int)std::get<3>(m)<<std::endl;
    // }
    // return 0;

    bool maxPlayer = true;

    auto start = std::chrono::high_resolution_clock::now();
    while(!match.gameOver()){
        BlokusMatch matchCopy(match);
        BlokusMove bestMove = getNextMove(matchCopy, 4, maxPlayer);
        // std::cout<<"piece: "<<std::get<0>(bestMove) << " row: "<<std::get<1>(bestMove)<<" col: " << std::get<2>(bestMove)<<" Rot: " << (int)std::get<3>(bestMove)<<std::endl;
        match.playMove(std::get<0>(bestMove), std::get<1>(bestMove), std::get<2>(bestMove), std::get<3>(bestMove), maxPlayer);
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

    std::cout<<"P1 has: "<<match.getPiecesForPlayer(0).size()<<" pieces"<<std::endl;
    std::cout<<"P2 has: "<<match.getPiecesForPlayer(1).size()<<" pieces"<<std::endl;

    std::cout<<"Match eval: "<<match.evaluatePosition()<<std::endl;

    // auto moves = match.getMovesFromPos(true);
    // for(auto m : moves){
    //     std::cout<<"piece: "<<std::get<0>(m) << " row: "<<std::get<1>(m)<<" col: " << std::get<2>(m)<<" Rot: " << (int)std::get<3>(m)<<std::endl;
    // }
}