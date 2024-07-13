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


    // match.playMove(blokusShapeType::zShapeType, 0, 0);
    // match.playMove(blokusShapeType::iShapeType, 19, 15);
    // match.playMove(blokusShapeType::iShapeType, 2, 3);

    match.getBoard().printBoardState();

    // match.playMove(blokusShapeType::iShapeType, 2, 3);
    // match.playMove(blokusShapeType::zShapeType, 17, 12);

    // match.getBoard().printBoardState();

    // std::cout << match.evaluatePosition() << std::endl;

    // auto start = std::chrono::steady_clock::now();
    // for(int i = 0 ; i < 1000 ; i++){
    //     std::vector<BlokusMove> movesForMatch = match.getMovesFromPos();
    // }
    // auto end = std::chrono::steady_clock::now();

    // auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // std::cout << "Seconds passed: " << duration.count() << " mil seconds" << std::endl;

    // match.getBoard().printBoardState();

    // std::vector<BlokusMove> movesForMatch = match.getMovesFromPos();

    // for(auto& move : movesForMatch){
    //     std::cout<< blokusShapeTypeNames[std::get<0>(move)] << " " << std::get<1>(move) << " "  << std::get<2>(move) << std::endl; 
    // }

    BlokusMove bestMove = getNextMove(match, 3);

    std::cout<< "Best move is: " << blokusShapeTypeNames[std::get<0>(bestMove)] << " " << std::get<1>(bestMove) << " "  << std::get<2>(bestMove)<< std::endl; 

    match.playMove(std::get<0>(bestMove), std::get<1>(bestMove), std::get<2>(bestMove));
    
    match.getBoard().printBoardState();

    BlokusMove otherBestMove = getNextMove(match, 3);

    std::cout<< "Best move is: " << blokusShapeTypeNames[std::get<0>(bestMove)] << " " << std::get<1>(bestMove) << " "  << std::get<2>(bestMove)<< std::endl; 

    match.playMove(std::get<0>(otherBestMove), std::get<1>(otherBestMove), std::get<2>(otherBestMove));
    
    match.getBoard().printBoardState();

    return 0;
}