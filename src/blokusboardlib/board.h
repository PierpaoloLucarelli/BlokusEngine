#pragma once
#include <string>
#include "pieceShapes.h"
#include <memory>
#include <cstdint>
#include <vector>

const int WIDTH = 20;
const int HEIGHT = 20;
const uint8_t EMPTYCELL = 7;

class BlokusBoard{
    private:
        uint8_t state[WIDTH * HEIGHT];


    public:

        BlokusBoard();
        BlokusBoard(const BlokusBoard& otherBoard);

        void reset();
        std::vector<uint8_t> getState();
        bool placePiece(const Block& piece, int row, int col, uint8_t rotation, uint8_t turn);
        bool canPlacePiece(const Block& piece, int row, int col, uint8_t rotation, uint8_t turn, bool firstMove);
        std::vector<std::string> getPlacedCoords(const Block& piece, int row, int col, uint8_t rotation);
        int getWidth() const;
        int getHeight() const;
        const char* getStrReprForBlock(int i);
        std::string getStrReprForBoard() const;
        bool isInCorner(const Block& piece, int row, int col, uint8_t rotation);
        void removePiece(const Block& piece, int row, int col, uint8_t rotation);
        // bool isCorner(int row, int col);
        bool isAdjacentOccupied(int row, int col, uint8_t turn);
        bool isDiagonalOccupied(int row, int col, uint8_t turn);
        void printBoardState();
        void setState(int row, int col, uint8_t turn);
        bool isOccupied(int row, int col);

        bool operator==(const BlokusBoard& other) const {
           for(int i = 0 ; i < WIDTH * HEIGHT ; i++){
                if (state[i] != other.state[i]){
                    return false;
                }
           }
           return true;
        }
};

class BlokusBoardHashFunction {
public:
    size_t operator()(const BlokusBoard& board) const
    {
        std::string boardStr = board.getStrReprForBoard();
        return std::hash<std::string>()(boardStr);
    }
};
