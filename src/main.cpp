#include <iostream>
#include <board.h>
#include <pieceShapes.h>
#include <match.h>
#include <minimax.h>
#include <chrono>
#include <ncurses.h>
#include <gui.h>
#include <thread>


int main(){
    BlokusBoard board;
    BlokusGUI gui;
    initializePieceMap();
    BlokusMatch match(board, gui);
    match.newGame();

    // match.playMove(blokusShapeType::bigCornerShapeType, 0, 0, 0, true);

    // match.playMove(blokusShapeType::bigCornerShapeType, 0, 11, 1, false);


    // auto corners = match.getCornersFromPos(false);
    // for(auto c : corners){
    //     std::cout<<"Corner: ( " << std::get<0>(c) << ", " << std::get<1>(c) << " ) ";
    // }



    // match.playMove(blokusShapeType::bigCornerShapeType, 1, 5, 0, true);

    // match.playMove(blokusShapeType::bigCornerShapeType, 10, 6, 0, false);
    match.printGame();

    // auto corners = match.getCornersFromPos(true);
    // for(auto c : corners){
    //     std::cout<<"Corner: ( " << std::get<0>(c) << ", " << std::get<1>(c) << " ) ";
    // }

    // auto moves = match.getMovesFromPos(true);

    // for(auto m : moves){
    //     std::cout<<"piece: "<<std::get<0>(m) << " row: "<<std::get<1>(m)<<" col: " << std::get<2>(m)<<" Rot: " << (int)std::get<3>(m)<<std::endl;
    // }
    // return 0;


    bool maxPlayer = true;

    // auto start = std::chrono::high_resolution_clock::now();
    while(!match.gameOver()){
        match.printGame();

        // auto corners = match.getCornersFromPos(maxPlayer);
        // for(auto c : corners){
        //     std::cout<<"Corner: ( " << std::get<0>(c) << ", " << std::get<1>(c) << " ) ";
        // }

        BlokusMatch matchCopy(match);
        BlokusMove bestMove = getNextMove(matchCopy, 5, maxPlayer);
        std::cout<<"piece: "<<std::get<0>(bestMove) << " row: "<<std::get<1>(bestMove)<<" col: " << std::get<2>(bestMove)<<" Rot: " << (int)std::get<3>(bestMove)<<std::endl;
        match.playMove(std::get<0>(bestMove), std::get<1>(bestMove), std::get<2>(bestMove), std::get<3>(bestMove), maxPlayer);
        // std::this_thread::sleep_for(std::chrono::seconds(3));
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
    // auto end = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> duration = end - start;
    // std::cout << "Duration: " << duration.count() << " seconds" << std::endl;

    // std::cout<<"P1 has: "<<match.getPiecesForPlayer(0).size()<<" pieces"<<std::endl;
    // std::cout<<"P2 has: "<<match.getPiecesForPlayer(1).size()<<" pieces"<<std::endl;

    // std::cout<<"Match eval: "<<match.evaluatePosition()<<std::endl;

    // auto moves = match.getMovesFromPos(true);
    // for(auto m : moves){
    //     std::cout<<"piece: "<<std::get<0>(m) << " row: "<<std::get<1>(m)<<" col: " << std::get<2>(m)<<" Rot: " << (int)std::get<3>(m)<<std::endl;
    // }
}