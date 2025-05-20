#include <match.h>
#include <memory>
#include <algorithm>
#include <iostream>
#include <pieceShapes.h>
#include <cstdint>

const Block& BlokusMatch::getPiece(int piece_id){
    if(piece_id < 0 || piece_id > 22){
        throw std::runtime_error("Piece not found in piece map.");
    } else {
        return rotatedPieces[piece_id];
    }
}


BlokusMatch::BlokusMatch(int nPlayers): board(), nPlayers(nPlayers){
    playerPieces.resize(4);
    turnTracker = 0;
    gameOver = false;
    for(int i = 0; i < 4 ; i++){
      playersPassed[i] = false;
      playersPlayed[i] = false;

      for(int pieceId = 0 ; pieceId < 21 ; pieceId++){
          playerPieces[i].insert(pieceId);
      }
    }
    moveNum = 0;
}

BlokusMatch::BlokusMatch(BlokusMatch& otherMatch): board(otherMatch.board){ // todo: other match might not have a new game, then pieces are None.

    for(int i = 0 ; i < 4 ; i++){
      playersPlayed[i] = otherMatch.playersPlayed[i];
      playersPassed[i] = otherMatch.playersPassed[i];

      playerPieces[i].clear();
      for (int pieceId : otherMatch.playerPieces[i]) {
          playerPieces[i].insert(pieceId);
      }
    }
    moveNum = otherMatch.moveNum;
    nPlayers = otherMatch.nPlayers;
    turnTracker = otherMatch.turnTracker;
    gameOver = otherMatch.gameOver;
}

void BlokusMatch::newGame(){
    for(int i = 0 ; i < 4 ; i++){
        playersPassed[i] = false;
        playersPlayed[i] = false;

        playerPieces[i].clear();

        for(int pieceId = 0 ; pieceId < 21 ; pieceId++){
            playerPieces[i].insert(pieceId);
        }
    }
    moveNum = 0;
    turnTracker = 0;
    gameOver = false;
    board.reset();
}

bool BlokusMatch::play_move_(BlokusMove& move, uint8_t turn){
    return playMove(std::get<0>(move), std::get<1>(move), std::get<2>(move), std::get<3>(move), turn);
}

bool BlokusMatch::playMove(int pieceId, int row, int col, uint8_t rotation, uint8_t turn){
    bool canPlay = canPlayMove(pieceId, row, col, rotation, turn);
    if (!canPlay){
        return false;
    }
    bool success = applyMove(pieceId, row, col, rotation, turn);
    if (success) {
        if (pieceId == 22 && turnTracker != turn) {
            return true; // async resign
        }
        int8_t nextTurn = getNextTurn();
        if(nextTurn == -1){
            gameOver = true;
        } else {
            turnTracker = nextTurn;
        }
        moveNum++;
    }
    return success;
}

bool BlokusMatch::applyMove(int pieceId, int row, int col, uint8_t rotation, uint8_t turn){
    if(pieceId == 22){
        playersPassed[turn] = true;
        return true;
    }

    if(turn != turnTracker){
        std::cout << "Not your turn to play" << std::endl;
        return false;
    }

    const Block& piece = getPiece(pieceId);
    bool success = board.placePiece(piece, row, col, rotation, turn);
    if (success){
        playersPlayed[turn] = true;
        playerPieces[turn].erase(pieceId);
    }
    return success;
}

int8_t BlokusMatch::getNextTurn(){
    uint8_t nextTurn = (turnTracker+1)%nPlayers;
    while(nextTurn != turnTracker){
        if(!playersPassed[nextTurn]){
            return nextTurn;
        }
        nextTurn = (nextTurn+1)%nPlayers;
    }
    return -1;
}

void BlokusMatch::removeMove(int pieceId, int row, int col, uint8_t rotation, uint8_t turn){
    if(pieceId == 22){
        moveNum--;
        playersPassed[turn] = false;
        return;
    }
    const Block& piece = getPiece(pieceId);
    board.removePiece(piece, row, col, rotation);
    playerPieces[turn].insert(pieceId);
    if(playerPieces[turn].size() == 21){
      playersPlayed[turn] = false;
    }
    moveNum--;
}

bool BlokusMatch::canPlayMove(int pieceId, int row, int col, uint8_t rotation, uint8_t turn){

    if(turn >= nPlayers || playersPassed[turn] == true){
        return false;
    }

    if(pieceId == 22){
        return true;
    }

    bool firstMove = !playersPlayed[turn];
    const Block& piece = getPiece(pieceId);
    if (firstMove == true){
        if (!board.isInCorner(piece, row, col, rotation)){
            return false;
        }
    }

    std::unordered_set<int> playerPieces = getPiecesForPlayer(turn);
    if(!(playerPieces.find(pieceId) != playerPieces.end())){
        return false;
    }
    return board.canPlacePiece(piece, row, col, rotation, turn, firstMove);
}

const BlokusBoard& BlokusMatch::getBoard() const{
    return board;
}

std::vector<uint8_t> BlokusMatch::getState(){
    return board.getState();
}

std::unordered_set<int>& BlokusMatch::getPiecesForPlayer(uint8_t turn){
    return playerPieces[turn];
}

std::vector<std::vector<bool>> BlokusMatch::getPlayerPieces(){
    std::vector<std::vector<bool>> res;
    for(int i = 0 ; i < nPlayers ; i++){
        std::vector<bool> vec(21, false);
        for(int p : playerPieces[i]){
            vec[p] = true;
        }
        res.push_back(vec);
    }
    return res;
}

std::array<bool, 4> BlokusMatch::getFirstTurns(){
    return {!playersPlayed[0], !playersPlayed[1], !playersPlayed[2], !playersPlayed[3]};
}

std::array<bool, 4> BlokusMatch::getPlayersPassed(){
    return {playersPassed[0], playersPassed[1], playersPassed[2], playersPassed[3]};
}

struct less_than_key
{
    inline bool operator() (const BlokusMove& move1, const BlokusMove& move2)
    {
        return (std::get<0>(move1) < std::get<0>(move2));
    }
};

bool BlokusMatch::hasMoves(uint8_t turn){
    std::unordered_set<int>& playerPieces = getPiecesForPlayer(turn);
    const BlokusBoard& board = getBoard();
    int w = board.getWidth();

    for(const int pieceId : playerPieces){
        for(int i = 0 ; i < board.getHeight() * w; i++){
            for(int rotation = 0 ; rotation < 4 ; rotation++){
                if(canPlayMove(pieceId, (int)i/w, i%w, rotation, turn)){ // can play move
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
        if(!board.isOccupied(row, col)){ // empty
            if(!board.isAdjacentOccupied(row, col, turn) && board.isDiagonalOccupied(row, col, turn)){
                corners.push_back(std::make_tuple(row, col));
            }
        }
    }
    return corners;
}

std::vector<BlokusMove> BlokusMatch::getMovesFromPos(uint8_t turn) {
    std::vector<BlokusMove> moves;
    std::unordered_set<int>& playerPieces = getPiecesForPlayer(turn);
    std::vector<std::tuple<int, int>> freeCorners = getCornersFromPos(turn);


    for(const int pieceId : playerPieces){

        if((moveNum < 14 && pieceId > 8) || pieceId == 22){
            continue; // todo: remove for the python wrapper. this is only needed for the minimax search.
        }

        //  if(p == blokusShapeType::passShapeType){
        //     continue;
        // }

        const Block& piece = getPiece(pieceId);

        for(std::tuple<int, int> corner : freeCorners){
            for(int rotation = 0 ; rotation < 8 ; rotation++){

                std::vector<std::pair<int, int>> coords = piece.coords[rotation];
                for(int cornerIndex : piece.corners){
                    std::tuple<int, int> placementOffset = getOffsetForCorner(corner, coords[cornerIndex]);
                    int row = std::get<0>(placementOffset);
                    int col = std::get<1>(placementOffset);
                    if(canPlayMove(pieceId, row, col, rotation, turn)){ // can play move
                        moves.push_back(std::make_tuple(pieceId, row, col, rotation));
                    };
                }
            }
        }
    }

     if(moves.size() == 0){
        moves.push_back(std::make_tuple(22, 0, 0, 0)); // pass
    }
    return moves;
}

std::tuple<int, int> BlokusMatch::getOffsetForCorner(
        std::tuple<int,int> boardCorner,
        std::pair<int,int> pieceCorner
){
    int rowOffset = std::get<0>(boardCorner) - pieceCorner.second;
    int colOffset = std::get<1>(boardCorner) - pieceCorner.first;
    return std::make_tuple(rowOffset, colOffset);
}

void BlokusMatch::setPlayerPieces(std::unordered_set<int> pieces, uint8_t turn){
    playerPieces[turn] = pieces;
}

uint8_t BlokusMatch::getTurn(){
    return turnTracker;
}

bool BlokusMatch::getGameOver(){
    return gameOver;
}