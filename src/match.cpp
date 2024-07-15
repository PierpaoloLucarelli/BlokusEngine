#include <match.h>
#include <memory>
#include <algorithm>
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

BlokusMatch::BlokusMatch(BlokusBoard& aBoard): board(aBoard){
    p1Played = false;
    p2Played = false;
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
    board.reset();
}

bool BlokusMatch::playMove(blokusShapeType p, int row, int col, bool turn){
    bool canPlay = canPlayMove(p, row, col, turn);
    if (!canPlay){
        return false;
    }
    return applyMove(p, row, col, turn);
}

bool BlokusMatch::applyMove(blokusShapeType p, int row, int col, bool turn){
        bool success = board.placePiece(p, row, col, turn);
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

void BlokusMatch::removeMove(blokusShapeType p, int row, int col, bool turn){
        board.removePiece(p, row, col, turn);
}

bool BlokusMatch::canPlayMove(blokusShapeType p, int row, int col, bool turn){
    if ((turn == true && !p1Played) || (turn == false && !p2Played)){ // First move must be in corner.
        if (!board.isInCorner(p, row, col)){
            // std::cout<<"First move must be placed in a corner"<<std::endl;e
            return false;
        }
    }
    std::unordered_set<blokusShapeType> playerPieces = getPiecesForPlayer(turn);;
    if(!(playerPieces.find(p) != playerPieces.end())){
        std::cout<<"Atempted to play a piece that you dont have."<<std::endl;
        return false;
    }
    bool firstMove = turn ? !p1Played : !p2Played;
    return board.canPlacePiece(p, row, col, turn, firstMove);
}

bool BlokusMatch::gameOver(bool turn){
    bool gameOver = false;
    if (p1Pieces.size() == 0 || p2Pieces.size() == 0){
        gameOver = true;
    }else{
        gameOver = !hasMoves(turn);
    }
    if(gameOver){
        std::cout << "Game over. Score is: P1: " << evalPieces(p1Pieces) << " P2: " << evalPieces(p2Pieces) << std::endl;
    }
    return gameOver;
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
        for(int i = 0 ; i < board.getHeight() * w; i++){
            if(canPlayMove(piece, (int)i/w, i%w, turn)){ // can play move
                moves.push_back(std::make_tuple(piece, (int)i/w, i%w));
            };
        }
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
            if(canPlayMove(piece, (int)i/w, i%w, turn)){ // can play move
                return true;
            };
        }
    }
    return false;
}