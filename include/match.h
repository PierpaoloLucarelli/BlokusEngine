#pragma once

#include <memory>
#include <unordered_set>

#include <board.h>
#include <pieceShapes.h>


class BlokusMatch{
    private:
        bool turn;
        BlokusBoard& board;
        std::unordered_set<blokusShapeType> p1Pieces;
        std::unordered_set<blokusShapeType> p2Pieces;
        bool p1Played;
        bool p2Played;

    public:
        BlokusMatch(BlokusBoard& aBoard, bool isCPuTurn);

        void newGame();
        bool playMove(blokusShapeType p, int row, int col);
        bool gameOver();
        int evaluatePosition();
        BlokusBoard& getBoard();
        std::unordered_set<blokusShapeType>& getP1Pieces();
        std::unordered_set<blokusShapeType>& getP2Pieces();

};