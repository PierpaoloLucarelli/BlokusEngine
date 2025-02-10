#pragma once

#include <memory>
#include <unordered_set>

#include <board.h>
#include <pieceShapes.h>
#include <cstdint>


using BlokusMove = std::tuple<blokusShapeType, int, int, uint8_t>;

class BlokusMatch{
    private:
        BlokusBoard board;
        std::vector<std::unordered_set<blokusShapeType>> playerPieces;
        bool playersPlayed[4];
        bool playersPassed[4];
        int moveNum;
        int nPlayers;

    public:
        BlokusMatch(int nPlayers);
        BlokusMatch(BlokusMatch& otherMatch);


        void newGame();
        bool playMove(blokusShapeType p, int row, int col, uint8_t rotation, uint8_t turn);
        bool applyMove(blokusShapeType p, int row, int col, uint8_t rotation, uint8_t turn);
        void removeMove(blokusShapeType p, int row, int col, uint8_t rotation, uint8_t turn);
        bool canPlayMove(blokusShapeType p, int row, int col, uint8_t rotation, uint8_t turn);
        bool gameOver();
        int evaluatePosition();
        const BlokusBoard& getBoard() const;
        std::vector<uint8_t> getState();
        std::unordered_set<blokusShapeType>& getPiecesForPlayer(uint8_t turn);
        std::vector<BlokusMove> getMovesFromPos(uint8_t turn);
        bool hasMoves(uint8_t turn);
        void printGame();
        std::vector<std::tuple<int, int>> getCornersFromPos(uint8_t turn);
        std::tuple<int, int> getOffsetForCorner(std::tuple<int,int> boardCorner, std::tuple<int,int> pieceCorner);


};
