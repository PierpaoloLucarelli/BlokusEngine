#pragma once
#include <string>
#include "pieceShapes.h"
#include <memory>
#include <cstdint> 

const int WIDTH = 10;
const int HEIGHT = 10;

class BlokusBoard{
    private:
        int height;
        int width;
        uint8_t state[WIDTH][HEIGHT];


    public:

        BlokusBoard();
        void reset();
        void printBoardState();
        bool placePiece(blokusShapeType p, int x, int y, uint8_t turn);
        int getWidth();
        int getHeight();
        std::string getstrReprForBlock(int x, int y);
        bool isInCorner(blokusShapeType p, int row, int col);
};