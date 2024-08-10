#pragma once
#include <string>
#include "pieceShapes.h"
#include <memory>
#include <cstdint> 

const int WIDTH = 14;
const int HEIGHT = 14;

class BlokusBoard{
    private:
        int8_t state[WIDTH * HEIGHT];


    public:

        BlokusBoard();
        BlokusBoard(BlokusBoard& otherBoard);

        void reset();
        bool placePiece(BlokusPiece& piece, int row, int col, uint8_t rotation, int8_t turn);
        bool canPlacePiece(BlokusPiece& piece, int row, int col, uint8_t rotation, int8_t turn, bool firstMove);
        int getWidth();
        int getHeight();
        const char* getStrReprForBlock(int i);
        bool isInCorner(BlokusPiece& piece, int row, int col, uint8_t rotation);
        void removePiece(BlokusPiece& piece, int row, int col, uint8_t rotation);
        bool isCorner(int row, int col);
        bool isAdjacentOccupied(int row, int col, int8_t turn);
        bool isDiagonalOccupied(int row, int col, int8_t turn);
        int8_t getBlock(int row, int col);
};