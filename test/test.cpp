#include <iostream>
#include <match.h>

std::string PASSED = "TEST PASSED";
std::string FAILED = "TEST FAILED";

namespace {
    Matrix& getPiece(blokusShapeType p, uint8_t rotation){
        auto it = piecesMap.find(p);
        if(it == piecesMap.end()){
            throw std::runtime_error("Piece not found in piece map");
        }
        return it->second[rotation];
    }
}

int testGameOver(){
    BlokusBoard board;
    initializePieceMap();
    BlokusMatch match(board);
    match.newGame();
    match.playMove(blokusShapeType::zShapeType, 0, 0, 0, true);
    match.playMove(blokusShapeType::zShapeType, 18, 17, 0, false);
    match.playMove(blokusShapeType::iShapeType, 2, 3, 0, true);
    match.playMove(blokusShapeType::iShapeType, 17, 12, 0, false);
    match.playMove(blokusShapeType::smallCornerShapeType, 3, 8, 0, true);
    match.playMove(blokusShapeType::smallCornerShapeType, 15, 10, 0, false);
    match.playMove(blokusShapeType::bigCornerShapeType, 5, 7, 0, true);
    match.playMove(blokusShapeType::bigCornerShapeType, 12, 7, 0, false);
    match.playMove(blokusShapeType::singleShapeType, 1, 8, 0, true);
    match.playMove(blokusShapeType::singleShapeType, 15, 6, 0, false);
    match.playMove(blokusShapeType::crossShapeType, 8, 9, 0, true);
    match.playMove(blokusShapeType::crossShapeType, 12, 10, 0, false);
    match.playMove(blokusShapeType::tShapeType, 2, 10, 0, true);
    match.playMove(blokusShapeType::tShapeType, 15, 17, 0, false);
    match.playMove(blokusShapeType::oShapeType, 4, 13, 0, true);
    match.playMove(blokusShapeType::oShapeType, 13, 16, 0, false);

    match.getBoard().printBoardState();

    return match.gameOver(true);

}

int testRotatePiece(){
    BlokusBoard board;
    initializePieceMap();
    BlokusMatch match(board);
    match.newGame();

    Matrix& p = getPiece(blokusShapeType::longlShapeType, 0);
    // match.getBoard().placePiece(p, 5, 5, true);
    // match.getBoard().printBoardState();
    // match.getBoard().removePiece(p, 5, 5);
    // BlokusPiece& p2 = getPiece(blokusShapeType::longlShapeType, 1);
    // match.getBoard().placePiece(p2, 5, 5, true);
    // match.getBoard().printBoardState();
    // match.getBoard().removePiece(p2, 5, 5);
    // BlokusPiece& p3 = getPiece(blokusShapeType::longlShapeType, 2);
    // match.getBoard().placePiece(p3, 5, 5, true);
    // match.getBoard().printBoardState();
    // match.getBoard().removePiece(p3, 5, 5);
    // BlokusPiece& p4 = getPiece(blokusShapeType::longlShapeType, 3);
    // match.getBoard().placePiece(p4, 5, 5, true);
    // match.getBoard().printBoardState();
    // return 1;

}

int main(){
    std::cout << "Running tests." << std::endl;

    // if(testGameOver()){
    //     std::cout << "testGameOver(): " + PASSED << std::endl;
    // } else{
    //     std::cout << "testGameOver(): " + FAILED << std::endl;
    // }

    testRotatePiece();
    return 0;
}