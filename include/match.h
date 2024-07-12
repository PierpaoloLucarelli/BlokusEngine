#pragma once

#include <memory>
#include <unordered_set>

#include <board.h>
#include <pieceShapes.h>

using BlokusMove = std::tuple<blokusShapeType, int, int>;

class BlokusMatch{
    private:
        bool turn;
        BlokusBoard board;
        std::unordered_set<blokusShapeType> p1Pieces;
        std::unordered_set<blokusShapeType> p2Pieces;
        bool p1Played;
        bool p2Played;

    public:
        BlokusMatch(BlokusBoard& aBoard, bool isCPuTurn);
        BlokusMatch(BlokusMatch& otherMatch);


        void newGame();
        bool playMove(blokusShapeType p, int row, int col);
        bool canPlayMove(blokusShapeType p, int row, int col);
        bool gameOver();
        int evaluatePosition();
        BlokusBoard& getBoard();
        std::unordered_set<blokusShapeType>& getPiecesForCurretPlayer();
        std::vector<BlokusMove> getMovesFromPos();
};