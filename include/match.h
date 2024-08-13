#pragma once

#include <memory>
#include <unordered_set>

#include <board.h>
#include <pieceShapes.h>
#include <gui.h>

using BlokusMove = std::tuple<blokusShapeType, int, int, uint8_t>;

class BlokusMatch{
    private:
        // bool turn;
        BlokusBoard board;
        std::unordered_set<blokusShapeType> p1Pieces;
        std::unordered_set<blokusShapeType> p2Pieces;
        bool p1Played;
        bool p2Played;
        bool p1Passed;
        bool p2Passed;
        int moveNum;
        BlokusGUI gui;

    public:
        BlokusMatch(BlokusBoard& aBoard, BlokusGUI& gui);
        BlokusMatch(BlokusMatch& otherMatch);


        void newGame();
        bool playMove(blokusShapeType p, int row, int col, uint8_t rotation, bool turn);
        bool applyMove(blokusShapeType p, int row, int col, uint8_t rotation, bool turn);
        void removeMove(blokusShapeType p, int row, int col, uint8_t rotation, bool turn);
        bool canPlayMove(blokusShapeType p, int row, int col, uint8_t rotation, bool turn);
        bool gameOver();
        int evaluatePosition();
        BlokusBoard& getBoard();
        std::unordered_set<blokusShapeType>& getPiecesForPlayer(bool turn);
        std::vector<BlokusMove> getMovesFromPos(bool turn);
        bool hasMoves(bool turn);
        void printGame();
        std::vector<std::tuple<int, int>> getCornersFromPos(int8_t turn);
        std::tuple<int, int> getOffsetForCorner(std::tuple<int,int> boardCorner, std::tuple<int,int> pieceCorner);
};