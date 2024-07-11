#include <match.h>
#include <memory>
#include <iostream>
#include <pieceShapes.h>

BlokusMatch::BlokusMatch(BlokusBoard& aBoard, bool isCpuTurn): board(aBoard){
    turn = isCpuTurn;
    p1Played = false;
    p2Played = false;
}

void BlokusMatch::newGame(){
    for(const auto& pair : piecesMap){
        p1Pieces.insert(pair.first);
        p2Pieces.insert(pair.first);
    }
    p1Played = false;
    p2Played = false;
    board.reset();
}

bool BlokusMatch::playMove(blokusShapeType p, int row, int col){

    
    if ((turn == false && !p1Played) || (turn == true && !p2Played)){ // First move must be in corner.
        if (!board.isInCorner(p, row, col)){
            std::cout<<"First move must be placed in a corner"<<std::endl;
            return false;
        }
    }

    std::unordered_set<blokusShapeType> playerPieces;
    if(turn){
        playerPieces = getP1Pieces();
    } else{
        playerPieces = getP2Pieces();
    }
    if(!(playerPieces.find(p) != playerPieces.end())){
        return false;
    }

    uint8_t turnRep = turn == 1 ? 1 : 2;
    bool success = board.placePiece(p, col, row, turnRep);
    if(turn){
        p1Played = true;
    } else{
        p2Played = true;
    }
    turn = !turn;
    return success;
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
