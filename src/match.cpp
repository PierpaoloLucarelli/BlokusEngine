#include <match.h>
#include <memory>
#include <algorithm>
#include <iostream>
#include <pieceShapes.h>
#include <minimax.h>

namespace {
    BlokusPiece& getPiece(blokusShapeType p){
        auto it = piecesMap.find(p);
        if(it == piecesMap.end()){
            throw std::runtime_error("Piece not found in piece map");
        }
        return it->second;
    }

    int evalPieces(std::unordered_set<blokusShapeType>& pieces){
        int eval = 0;
        for (const auto piece : pieces){
            BlokusPiece& p = getPiece(piece);
            eval += p.getSize();
        }
        return eval;
    }

}

BlokusMatch::BlokusMatch(BlokusBoard& aBoard): board(aBoard){
    p1Played = false;
    p2Played = false;
    p1Passed = false;
    p2Passed = false;
}

BlokusMatch::BlokusMatch(BlokusMatch& otherMatch): board(otherMatch.board){
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
    p1Passed = false;
    p2Passed = false;
    board.reset();
}

bool BlokusMatch::playMove(blokusShapeType p, int row, int col, uint8_t rotation, bool turn){
    bool canPlay = canPlayMove(p, row, col, rotation, turn);
    if (!canPlay){
        return false;
    }
    return applyMove(p, row, col, rotation, turn);
}

bool BlokusMatch::applyMove(blokusShapeType p, int row, int col, uint8_t rotation, bool turn){

    if(p == blokusShapeType::passShapeType){
        if(turn){
            p1Passed = true;
        } else{
            p2Passed = true;
        }
        return true;
    }

    BlokusPiece& piece = getPiece(p);
    int8_t turnRep = turn == 1 ? 1 : -1;
        bool success = board.placePiece(piece, row, col, rotation, turnRep);
        if (success){
            if(turn){
                p1Played = true;
                p1Pieces.erase(p);
            } else{
                p2Played = true;
                p2Pieces.erase(p);
            }
        }
        return success;
}

void BlokusMatch::removeMove(blokusShapeType p, int row, int col, uint8_t rotation, bool turn){
    if(p == blokusShapeType::passShapeType){
        return;
    }
    BlokusPiece& piece = getPiece(p);
    board.removePiece(piece, row, col, rotation);
    if(turn){
        p1Pieces.insert(p);
    } else{
        p2Pieces.insert(p);
    }
}

bool BlokusMatch::canPlayMove(blokusShapeType p, int row, int col, uint8_t rotation, bool turn){

    if(p == blokusShapeType::passShapeType){
        return row == 0 && col == 0 && rotation == 0;
    }

    BlokusPiece& piece = getPiece(p);
    if ((turn == true && !p1Played) || (turn == false && !p2Played)){ // First move must be in corner.
        if (!board.isInCorner(piece, row, col, rotation)){
            // std::cout<<"First move must be placed in a corner"<<std::endl;
            return false;
        }
    }
    std::unordered_set<blokusShapeType> playerPieces = getPiecesForPlayer(turn);;
    if(!(playerPieces.find(p) != playerPieces.end())){
        std::cout<<"Atempted to play a piece that you dont have."<<std::endl;
        return false;
    }
    int8_t turnRep = turn == 1 ? 1 : -1;
    bool firstMove = turn ? !p1Played : !p2Played;
    return board.canPlacePiece(piece, row, col, rotation, turnRep, firstMove);
}

bool BlokusMatch::gameOver(){
    
    return p1Passed && p2Passed;
}

int BlokusMatch::evaluatePosition(){
    return evalPieces(p2Pieces)-evalPieces(p1Pieces);
}

BlokusBoard& BlokusMatch::getBoard(){
    return board;
}

std::unordered_set<blokusShapeType>& BlokusMatch::getPiecesForPlayer(bool turn){
    if(turn){
        return p1Pieces;
    } else {
        return p2Pieces;
    }
}

struct less_than_key
{
    inline bool operator() (const BlokusMove& move1, const BlokusMove& move2)
    {
        return (std::get<0>(move1) < std::get<0>(move2));
    }
};

std::vector<BlokusMove> BlokusMatch::getMovesFromPos(bool turn) {
    std::vector<BlokusMove> moves; 
    std::unordered_set<blokusShapeType>& playerPieces = getPiecesForPlayer(turn);

    BlokusBoard& board = getBoard();
    int w = board.getWidth();

    for(const auto& piece : playerPieces){
        if(piece != blokusShapeType::passShapeType){
            for(int i = 0 ; i < board.getHeight() * w; i++){
                for(int rotation = 0 ; rotation < 2 ; rotation++){
                    if(canPlayMove(piece, (int)i/w, i%w, rotation, turn)){ // can play move
                        moves.push_back(std::make_tuple(piece, (int)i/w, i%w, rotation));
                    };
                }
            }
        }
    }
    if(moves.size() == 0){
        moves.push_back(std::make_tuple(blokusShapeType::passShapeType, 0, 0, 0));
    }
    std::sort(moves.begin(), moves.end(), less_than_key());
    return moves;
}

bool BlokusMatch::hasMoves(bool turn){
    std::unordered_set<blokusShapeType>& playerPieces = getPiecesForPlayer(turn);
    BlokusBoard& board = getBoard();
    int w = board.getWidth();

    for(const auto& piece : playerPieces){
        for(int i = 0 ; i < board.getHeight() * w; i++){
            for(int rotation = 0 ; rotation < 2 ; rotation++){
                if(canPlayMove(piece, (int)i/w, i%w, rotation, turn)){ // can play move
                    return true;
                };
            }
        }
    }
    return false;
}