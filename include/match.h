#pragma once

#include <memory>
#include <unordered_set>

#include <board.h>
#include <pieceFactory.h>


class BlokusMatch{
    private:
        bool turn;
        BlokusBoard& board;
        std::unordered_set<BlokusPiece, BlokusPiece::HashFunction> p1Pieces;
        std::unordered_set<BlokusPiece, BlokusPiece::HashFunction> p2Pieces;


    public:

        BlokusMatch(BlokusBoard& aBoard, bool isCPuTurn);

        void newGame(PieceFactory& pieceFactory);
        bool playMove(std::unique_ptr<BlokusPiece>& p, int x, int y);
        bool gameOver();
        int evaluatePosition();
        BlokusBoard& getBoard();
        std::unordered_set<BlokusPiece, BlokusPiece::HashFunction>& getP1Pieces();
        std::unordered_set<BlokusPiece, BlokusPiece::HashFunction>& getP2Pieces();

};