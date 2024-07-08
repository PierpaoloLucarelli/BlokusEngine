#pragma once
#include <string>
#include "piece.h"

const int WIDTH = 10;
const int HEIGHT = 10;

class BlokusBoard{
    private:
        int height;
        int width;

        bool state[WIDTH][HEIGHT];

    public:

        BlokusBoard();
        void reset();
        void printBoardState();

        bool placePiece(BlokusPiece& p, int x, int y);

        int getWidth();
        int getHeight();
};