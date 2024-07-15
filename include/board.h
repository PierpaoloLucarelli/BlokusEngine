#pragma once
#include <string>
#include "pieceShapes.h"
#include <memory>
#include <cstdint> 
#include <bitset>

const int WIDTH = 20;
const int HEIGHT = 20;
const int BOARDSIZE = WIDTH*HEIGHT;

class BlokusBoard{
    private:
        std::bitset<BOARDSIZE> p1State;
        std::bitset<BOARDSIZE> p2State;


    public:

        BlokusBoard();
        BlokusBoard(BlokusBoard& otherBoard);

        void reset();
        void printBoardState();
        bool placePiece(blokusShapeType p, int row, int col, int8_t turn);
        bool canPlacePiece(blokusShapeType p, int row, int col, int8_t turn, bool firstMove);
        int getWidth();
        int getHeight();
        std::string getStrReprForBlock(int i);
        bool isInCorner(blokusShapeType p, int row, int col);
        void removePiece(blokusShapeType p, int row, int col, bool turn);
};