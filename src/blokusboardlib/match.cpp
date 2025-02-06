#include <match.h>
#include <memory>
#include <algorithm>
#include <iostream>
#include <pieceShapes.h>
#include <cstdint>

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

BlokusMatch::BlokusMatch(BlokusBoard& aBoard, int nPlayers): board(aBoard){
    // p1Played = false;
    // p2Played = false;
    // p1Passed = false;
    // p2Passed = false;

    playerPieces.resize(4);

    for(int i = 0; i < 4 ; i++){
      playersPassed[i] = false;
      playersPlayed[i] = false;

      for(const auto& pair : piecesMap){
          playerPieces[i].insert(pair.first);
      }
    }
    moveNum = 0;
    nPlayers = nPlayers;
}

BlokusMatch::BlokusMatch(BlokusMatch& otherMatch): board(otherMatch.board){ // todo: other match might not have a new game, then pieces are None.

    for(int i = 0 ; i < 4 ; i++){
      playersPlayed[i] = otherMatch.playersPlayed[i];
      playersPassed[i] = otherMatch.playersPassed[i];

      playerPieces[i].clear();
      for (blokusShapeType p : otherMatch.playerPieces[i]) {
          playerPieces[i].insert(p);
      }
    }
    //
    // playersPlayed = otherMatch.playersPlayed;
    // p2Played = otherMatch.p2Played;
    moveNum = otherMatch.moveNum;
    nPlayers = otherMatch.nPlayers;
    // for (blokusShapeType p : otherMatch.p1Pieces) {
    //     p1Pieces.insert(p);
    // }
    // for (blokusShapeType p : otherMatch.p2Pieces) {
    //     p2Pieces.insert(p);
    // }
}

void BlokusMatch::newGame(){
    for(int i = 0 ; i < 4 ; i++){
      playersPassed[i] = false;
      playersPlayed[i] = false;

      playerPieces[i].clear();

      for(const auto& pair : piecesMap){
          playerPieces[i].insert(pair.first);
      }
    }

    // p1Played = false;
    // p2Played = false;
    // p1Passed = false;
    // p2Passed = false;
    moveNum = 0;
    board.reset();
}

bool BlokusMatch::playMove(blokusShapeType p, int row, int col, uint8_t rotation, uint8_t turn){
    bool canPlay = canPlayMove(p, row, col, rotation, turn);
    if (!canPlay){
        return false;
    }
    bool success = applyMove(p, row, col, rotation, turn);
    return success;
}

bool BlokusMatch::applyMove(blokusShapeType p, int row, int col, uint8_t rotation, uint8_t turn){

    if(p == blokusShapeType::passShapeType){
        playersPassed[turn] = true;
        moveNum++;
        return true;
    }

    BlokusPiece& piece = getPiece(p);
    // int8_t turnRep = turn == 1 ? 1 : -1;
        bool success = board.placePiece(piece, row, col, rotation, turn);
        if (success){
            // if(turn){
            //     p1Played = true;
            //     p1Pieces.erase(p);
            // } else{
            //     p2Played = true;
            //     p2Pieces.erase(p);
            // }
            playersPlayed[turn] = true;
            playerPieces[turn].erase(p);
            moveNum++;
        }
        return success;
}

void BlokusMatch::removeMove(blokusShapeType p, int row, int col, uint8_t rotation, uint8_t turn){
    if(p == blokusShapeType::passShapeType){
        moveNum--;
        // if(turn){
        //     p1Passed = false;
        // } else {
        //     p2Passed = false;
        // }
        playersPassed[turn] = false;
        return;
    }
    BlokusPiece& piece = getPiece(p);
    board.removePiece(piece, row, col, rotation);
    // if(turn){
    //     p1Pieces.insert(p);
    //     if(p1Pieces.size() == 21){
    //         p1Played = false;
    //     }
    // } else{
    //     p2Pieces.insert(p);
    //     if(p2Pieces.size() == 21){
    //         p2Played = false;
    //     }
    // }
    playerPieces[turn].insert(p);
    if(playerPieces[turn].size() == 21){
      playersPlayed[turn] = false;
    }
    moveNum--;
}

bool BlokusMatch::canPlayMove(blokusShapeType p, int row, int col, uint8_t rotation, uint8_t turn){

    if(p == blokusShapeType::passShapeType){
        return row == 0 && col == 0 && rotation == 0;
    } // todo: this might be wrong.

    bool firstMove = !playersPlayed[turn];
    BlokusPiece& piece = getPiece(p);
    if (firstMove == true){
        if (!board.isInCorner(piece, row, col, rotation)){
            return false;
        }
    }

    std::unordered_set<blokusShapeType> playerPieces = getPiecesForPlayer(turn);
    if(!(playerPieces.find(p) != playerPieces.end())){
        return false;
    }
    // int8_t turnRep = turn == 1 ? 1 : -1;
    return board.canPlacePiece(piece, row, col, rotation, turn, firstMove);
}

bool BlokusMatch::gameOver(){
    for(int i = 0 ; i < nPlayers ; i++){
      if(playersPassed[i] == false){
        return false;
      }
    }
    return true;
}

int BlokusMatch::evaluatePosition(){ // TODO: should not be part of the match class
    // return evalPieces(p2Pieces)-evalPieces(p1Pieces);
    return 0; // todo
}

const BlokusBoard& BlokusMatch::getBoard() const{
    return board;
}

std::unordered_set<blokusShapeType>& BlokusMatch::getPiecesForPlayer(uint8_t turn){
    return playerPieces[turn];
}

struct less_than_key
{
    inline bool operator() (const BlokusMove& move1, const BlokusMove& move2)
    {
        return (std::get<0>(move1) < std::get<0>(move2));
    }
};

bool BlokusMatch::hasMoves(uint8_t turn){
    std::unordered_set<blokusShapeType>& playerPieces = getPiecesForPlayer(turn);
    const BlokusBoard& board = getBoard();
    int w = board.getWidth();

    for(const auto& piece : playerPieces){
        for(int i = 0 ; i < board.getHeight() * w; i++){
            for(int rotation = 0 ; rotation < 4 ; rotation++){
                if(canPlayMove(piece, (int)i/w, i%w, rotation, turn)){ // can play move
                    return true;
                };
            }
        }
    }
    return false;
}

void BlokusMatch::printGame(){
    board.printBoardState();
}

std::vector<std::tuple<int, int>> BlokusMatch::getCornersFromPos(uint8_t turn){

    std::vector<std::tuple<int, int>> corners;

    bool firstMove = !playersPlayed[turn];
    if(firstMove){
        corners.push_back(std::make_tuple(0,0));
        corners.push_back(std::make_tuple(0, board.getWidth()-1));
        corners.push_back(std::make_tuple(board.getHeight()-1,0));
        corners.push_back(std::make_tuple(board.getHeight() - 1, board.getWidth() - 1));

        return corners;
    }

    int w = board.getWidth();
    for(int i = 0 ; i < board.getHeight() * w; i++){
        int row = i/w;
        int col = i%w;
        if(board.getBlock(row, col) == 7){ // empty
            // int8_t turnRep = turn == 1 ? 1 : -1;
            if(!board.isAdjacentOccupied(row, col, turn) && board.isDiagonalOccupied(row, col, turn)){
                corners.push_back(std::make_tuple(row, col));
            }
        }
    }
    return corners;
}

std::vector<BlokusMove> BlokusMatch::getMovesFromPos(uint8_t turn) {
    std::vector<BlokusMove> moves;
    std::unordered_set<blokusShapeType>& playerPieces = getPiecesForPlayer(turn);
    std::vector<std::tuple<int, int>> freeCorners = getCornersFromPos(turn);


    for(const auto& p : playerPieces){

        // if((moveNum < 14 && p > 8) || p == blokusShapeType::passShapeType){
        //     continue;
        // }

        BlokusPiece& piece = getPiece(p);

        for(std::tuple<int, int> corner : freeCorners){
            for(int rotation = 0 ; rotation < 4 ; rotation++){
                for(auto pieceCorner : piece.getCornerBlocks(rotation)){
                    std::tuple<int, int> placementOffset = getOffsetForCorner(corner, pieceCorner);
                    int row = std::get<0>(placementOffset);
                    int col = std::get<1>(placementOffset);
                    if(canPlayMove(p, row, col, rotation, turn)){ // can play move
                        moves.push_back(std::make_tuple(p, row, col, rotation));
                    };
                }

            }
        }
    }

     if(moves.size() == 0){
        moves.push_back(std::make_tuple(blokusShapeType::passShapeType, 0, 0, 0));
    }
    // std::sort(moves.begin(), moves.end(), less_than_key());
    return moves;
}

std::tuple<int, int> BlokusMatch::getOffsetForCorner(
        std::tuple<int,int> boardCorner,
        std::tuple<int,int> pieceCorner
){
    int rowOffset = std::get<0>(boardCorner) - std::get<0>(pieceCorner);
    int colOffset = std::get<1>(boardCorner) - std::get<1>(pieceCorner);
    return std::make_tuple(rowOffset, colOffset);
}
