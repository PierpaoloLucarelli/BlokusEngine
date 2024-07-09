#include <match.h>
#include <memory>

BlokusMatch::BlokusMatch(BlokusBoard& aBoard, bool isCpuTurn): board(aBoard){
    turn = isCpuTurn;
}

void BlokusMatch::newGame(PieceFactory& pieceFactory){
    board.reset();
    pieceFactory.fillPieceSet(p1Pieces);
    pieceFactory.fillPieceSet(p2Pieces);
}

bool BlokusMatch::playMove(std::unique_ptr<BlokusPiece>& p, int x, int y){
    std::unordered_set<BlokusPiece, BlokusPiece::HashFunction> playerPieces;
    if(turn){
        playerPieces = getP1Pieces();
    } else{
        playerPieces = getP2Pieces();
    }
    if(!(playerPieces.find(*p) != playerPieces.end())){
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

std::unordered_set<BlokusPiece, BlokusPiece::HashFunction>& BlokusMatch::getP1Pieces(){
    return p1Pieces;
}

std::unordered_set<BlokusPiece, BlokusPiece::HashFunction>& BlokusMatch::getP2Pieces(){
    return p2Pieces;
}