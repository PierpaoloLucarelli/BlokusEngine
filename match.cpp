#include <match.h>
#include <memory>
#include <iostream>
#include <pieceShapes.h>
#include <minimax.h>

namespace {
    int evalPieces(std::unordered_set<blokusShapeType> pieces){
        int eval = 0;
        for (const auto piece : pieces){
            auto it = piecesMap.find(piece);
            if(it == piecesMap.end()){
                throw std::runtime_error("Piece not found in piece map");
            }
            BlokusPiece& p = it->second; // todo check if its a reference.
            eval += p.getSize();
        }
        return eval;
    }
}

BlokusMatch::BlokusMatch(BlokusBoard& aBoard, bool isCpuTurn): board(aBoard){
    turn = isCpuTurn;
    p1Played = false;
    p2Played = false;
}

BlokusMatch::BlokusMatch(BlokusMatch& otherMatch): board(otherMatch.board){
    turn = otherMatch.turn;
    p1Played = otherMatch.p1Played;
    p2Played = otherMatch.p2Played;
    for (blokusShapeType p : otherMatch.p1Pieces) {
        p1Pieces.insert(p);
    }
    for (blokusShapeType p : otherMatch.p2Pieces) {
        p2Pieces.insert(p);
    }
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
    if ((turn == true && !p1Played) || (turn == false && !p2Played)){ // First move must be in corner.
    
        if (!board.isInCorner(p, row, col)){
            std::cout<<"First move must be placed in a corner"<<std::endl;
            return false;
        }
    }

    std::unordered_set<blokusShapeType> playerPieces = getPiecesForCurretPlayer();;
    if(!(playerPieces.find(p) != playerPieces.end())){
        std::cout<<"Atempted to play a piece that you dont have."<<std::endl;
        return false;
    }

    int8_t turnRep = turn == 1 ? 1 : -1;
    bool success = board.placePiece(p, row, col, turnRep);

    if (success){
        if(turn){
            p1Played = true;
            p1Pieces.erase(p);
        } else{
            p2Played = true;
            p2Pieces.erase(p);
        }
        turn = !turn;
    }

    return success;
}

bool BlokusMatch::gameOver(){
    // std::vector<BlokusMove> getMovesFromMatch;
    return false;
}

int BlokusMatch::evaluatePosition(){
    return evalPieces(p2Pieces)-evalPieces(p1Pieces);
}

BlokusBoard& BlokusMatch::getBoard(){
    return board;
}

std::unordered_set<blokusShapeType>& BlokusMatch::getPiecesForCurretPlayer(){
    if(turn){
        return p1Pieces;
    } else {
        return p2Pieces;
    }
}

std::vector<BlokusMove> BlokusMatch::getMovesFromPos() {
    std::vector<BlokusMove> moves; 
    std::unordered_set<blokusShapeType>& playerPieces = getPiecesForCurretPlayer();

    BlokusBoard& board = getBoard();
    int w = board.getWidth();

    for(const auto& piece : playerPieces){
        for(int i = 0 ; i < board.getHeight() * board.getWidth(); i++){
            BlokusMatch matchCopy(*this);
            if(matchCopy.playMove(piece, (int)i/w, i%w)){ // can play move
                moves.push_back(std::make_tuple(piece, (int)i/w, i%w));
                // matchCopy.getBoard().printBoardState();
            };
        }
    }
   return moves;
}