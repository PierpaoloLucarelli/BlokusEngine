#include <match.h>
#include <memory>

BlokusMatch::BlokusMatch(BlokusBoard& aBoard, bool isCpuTurn): board(aBoard){
    turn = isCpuTurn;
}

void BlokusMatch::newGame(){
    board.reset();
}

bool BlokusMatch::playMove(std::unique_ptr<BlokusPiece>& p, int x, int y){
    return board.placePiece(p, x, y);
}

bool BlokusMatch::gameOver(){
    return false; // todo
}

int BlokusMatch::evaluatePosition(){
    return 1; // todo
}
