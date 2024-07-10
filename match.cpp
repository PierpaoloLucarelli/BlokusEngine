#include <match.h>
#include <memory>
#include <pieceShapes.h>

BlokusMatch::BlokusMatch(BlokusBoard& aBoard, bool isCpuTurn): board(aBoard){
    turn = isCpuTurn;
}

void BlokusMatch::newGame(){
    for(const auto& pair : piecesMap){
        p1Pieces.insert(pair.first);
        p2Pieces.insert(pair.first);
    }
    board.reset();
}

bool BlokusMatch::playMove(blokusShapeType p, int x, int y){
    std::unordered_set<blokusShapeType> playerPieces;
    if(turn){
        playerPieces = getP1Pieces();
    } else{
        playerPieces = getP2Pieces();
    }
    if(!(playerPieces.find(p) != playerPieces.end())){
        return false;
    }
    turn = !turn;
    return board.placePiece(p, x, y);
}

bool BlokusMatch::gameOver(){
    return false; // todo
}

int BlokusMatch::evaluatePosition(){
    return 1; // todo
}

BlokusBoard& BlokusMatch::getBoard(){
    return board;
}

std::unordered_set<blokusShapeType>& BlokusMatch::getP1Pieces(){
    return p1Pieces;
}

std::unordered_set<blokusShapeType>& BlokusMatch::getP2Pieces(){
    return p2Pieces;
}