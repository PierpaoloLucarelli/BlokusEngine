#pragma once

#include <memory>
#include <unordered_set>

#include <board.h>
#include <pieceShapes.h>

using BlokusMove = std::tuple<blokusShapeType, int, int>;

class BlokusMatch{
    private:
        // bool turn;
        BlokusBoard board;
        std::unordered_set<blokusShapeType> p1Pieces;
        std::unordered_set<blokusShapeType> p2Pieces;
        bool p1Played;
        bool p2Played;

    public:
        BlokusMatch(BlokusBoard& aBoard);
        BlokusMatch(BlokusMatch& otherMatch);


        void newGame();
        bool playMove(blokusShapeType p, int row, int col, bool turn);
        bool applyMove(blokusShapeType p, int row, int col, bool turn);
        void removeMove(blokusShapeType p, int row, int col);
        bool canPlayMove(blokusShapeType p, int row, int col, bool turn);
        bool gameOver(bool turn);
        int evaluatePosition();
        BlokusBoard& getBoard();
        std::unordered_set<blokusShapeType>& getPiecesForPlayer(bool turn);
        std::vector<BlokusMove> getMovesFromPos(bool turn);
        bool hasMoves(bool turn);
};