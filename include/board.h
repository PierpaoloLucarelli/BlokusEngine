#pragma once
#include <string>
#include "pieceShapes.h"
#include <memory>
#include <cstdint> 

const int WIDTH = 20;
const int HEIGHT = 20;

class BlokusBoard{
    private:
        uint8_t state[WIDTH * HEIGHT];


    public:

        BlokusBoard();
        BlokusBoard(BlokusBoard& otherBoard);

        void reset();
        void printBoardState();
        bool placePiece(blokusShapeType p, int x, int y, uint8_t turn);
        int getWidth();
        int getHeight();
        std::string getStrReprForBlock(int i);
        bool isInCorner(blokusShapeType p, int row, int col);
        std::string hash();
};