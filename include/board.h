#pragma once
#include <string>
#include "pieceShapes.h"
#include <memory>

const int WIDTH = 10;
const int HEIGHT = 10;

class BlokusBoard{
    private:
        int height;
        int width;
        bool cpuTurn;
        bool state[WIDTH][HEIGHT];


    public:

        BlokusBoard();
        void reset();
        void printBoardState();
        bool placePiece(blokusShapeType p, int x, int y);
        int getWidth();
        int getHeight();
        bool isCpuTurn();
        
};