#pragma once
#include <string>
#include "pieceShapes.h"
#include <memory>
#include <cstdint> 

const int WIDTH = 20;
const int HEIGHT = 20;

class BlokusBoard{
    private:
        int8_t state[WIDTH * HEIGHT];


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
        std::string hash();
};