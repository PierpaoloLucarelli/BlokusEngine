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

BlokusMatch::BlokusMatch(BlokusBoard& aBoard, BlokusGUI& bgui): board(aBoard){
    p1Played = false;
    p2Played = false;
    p1Passed = false;
    p2Passed = false;
    moveNum = 0;
    gui = bgui;
}

BlokusMatch::BlokusMatch(BlokusMatch& otherMatch): board(otherMatch.board){
    p1Played = otherMatch.p1Played;
    p2Played = otherMatch.p2Played;
    moveNum = otherMatch.moveNum;
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
    moveNum = 0;
    board.reset();
}

bool BlokusMatch::playMove(blokusShapeType p, int row, int col, uint8_t rotation, bool turn){
    bool canPlay = canPlayMove(p, row, col, rotation, turn);
    if (!canPlay){
        return false;
    }
    bool success = applyMove(p, row, col, rotation, turn);
    return success;
}

bool BlokusMatch::applyMove(blokusShapeType p, int row, int col, uint8_t rotation, bool turn){

    if(p == blokusShapeType::passShapeType){
        if(turn){
            p1Passed = true;
        } else{
            p2Passed = true;
        }
        moveNum++;
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
            moveNum++;
        }
        return success;
}

void BlokusMatch::removeMove(blokusShapeType p, int row, int col, uint8_t rotation, bool turn){
    if(p == blokusShapeType::passShapeType){
        moveNum--;
        return;
    }
    BlokusPiece& piece = getPiece(p);
    board.removePiece(piece, row, col, rotation);
    if(turn){
        p1Pieces.insert(p);
        if(p1Pieces.size() == 21){
            p1Played = false;
        }
    } else{
        p2Pieces.insert(p);
        if(p2Pieces.size() == 21){
            p2Played = false;
        }
    }
    moveNum--;
}

bool BlokusMatch::canPlayMove(blokusShapeType p, int row, int col, uint8_t rotation, bool turn){

    if(p == blokusShapeType::passShapeType){
        return row == 0 && col == 0 && rotation == 0;
    }

    BlokusPiece& piece = getPiece(p);
    if ((turn == true && !p1Played) || (turn == false && !p2Played)){ // First move must be in corner.
        if (!board.isInCorner(piece, row, col, rotation)){
            return false;
        }
    }
    std::unordered_set<blokusShapeType> playerPieces = getPiecesForPlayer(turn);
    if(!(playerPieces.find(p) != playerPieces.end())){
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
        if(moveNum < 14 && piece > 8){
            continue;
        }
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

void BlokusMatch::printGame(){
    gui.printGameState(board);
}

std::vector<std::tuple<int, int>> BlokusMatch::getCornersFromPos(bool turn){

    // if first move, return the four corners (before you call this func)
    std::vector<std::tuple<int, int>> corners;
    int w = board.getWidth();
    for(int i = 0 ; i < board.getHeight() * w; i++){
        int row = i/w;
        int col = i%w;
        if(board.getBlock(row, col) == 0){
            if(!board.isAdjacentOccupied(row, col, turn) && board.isDiagonalOccupied(row, col, turn)){
                corners.push_back(std::make_tuple(row, col));
            }
        }
    }
    return corners;
}