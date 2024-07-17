#include <iostream>
#include <match.h>

std::string PASSED = "TEST PASSED";
std::string FAILED = "TEST FAILED";

namespace {
    BlokusPiece& getPiece(blokusShapeType p){
        auto it = piecesMap.find(p);
        if(it == piecesMap.end()){
            throw std::runtime_error("Piece not found in piece map");
        }
        return it->second;
    }
}

int testGameOver(){
    BlokusBoard board;
    initializePieceMap();
    BlokusMatch match(board);
    match.newGame();
    match.playMove(blokusShapeType::zShapeType, 0, 0, true);
    match.playMove(blokusShapeType::zShapeType, 18, 17, false);
    match.playMove(blokusShapeType::iShapeType, 2, 3, true);
    match.playMove(blokusShapeType::iShapeType, 17, 12, false);
    match.playMove(blokusShapeType::smallCornerShapeType, 3, 8, true);
    match.playMove(blokusShapeType::smallCornerShapeType, 15, 10, false);
    match.playMove(blokusShapeType::bigCornerShapeType, 5, 7, true);
    match.playMove(blokusShapeType::bigCornerShapeType, 12, 7, false);
    match.playMove(blokusShapeType::singleShapeType, 1, 8, true);
    match.playMove(blokusShapeType::singleShapeType, 15, 6, false);
    match.playMove(blokusShapeType::crossShapeType, 8, 9, true);
    match.playMove(blokusShapeType::crossShapeType, 12, 10, false);
    match.playMove(blokusShapeType::tShapeType, 2, 10, true);
    match.playMove(blokusShapeType::tShapeType, 15, 17, false);
    match.playMove(blokusShapeType::oShapeType, 4, 13, true);
    match.playMove(blokusShapeType::oShapeType, 13, 16, false);

    match.getBoard().printBoardState();

    return match.gameOver(true);

}

int testRotatePiece(){
    BlokusBoard board;
    initializePieceMap();
    BlokusMatch match(board);
    match.newGame();

    BlokusPiece& p = getPiece(blokusShapeType::longlShapeType);
    match.getBoard().placePiece(p, 5, 5, true);
    match.getBoard().printBoardState();
    match.getBoard().removePiece(p, 5, 5);
    p.rotate();
    match.getBoard().placePiece(p, 5, 5, true);
    match.getBoard().printBoardState();
    match.getBoard().removePiece(p, 5, 5);
    p.rotate();
    match.getBoard().placePiece(p, 5, 5, true);
    match.getBoard().printBoardState();
    match.getBoard().removePiece(p, 5, 5);
    p.rotate();
    match.getBoard().placePiece(p, 5, 5, true);
    match.getBoard().printBoardState();
    match.getBoard().removePiece(p, 5, 5);
    return 1;
}

int main(){
    std::cout << "Running tests." << std::endl;

    if(testRotatePiece()){
        std::cout << "testGameOver(): " + PASSED << std::endl;
    } else{
        std::cout << "testGameOver(): " + FAILED << std::endl;
    }
    return 0;

}