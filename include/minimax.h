#pragma once
#include <vector>
#include <match.h>
#include <pieceShapes.h>
#include <board.h>


// using BlokusMove = std::tuple<blokusShapeType, int, int>;

class BlokusEngine{

    private:
        int seen;
        std::unordered_map<BlokusBoard, int, BlokusBoardHashFunction> seenBoards;
        std::unique_ptr<BlokusBoard> board;
        std::unique_ptr<BlokusMatch> match;

        

    public:
        BlokusEngine(); 
        int minimax(BlokusMatch& match, int depth, int alpha, int beta, bool maximising);   
        BlokusMove p_getNextMove(BlokusMatch& match, int maxDepth, bool maximising);
        BlokusMove getNextMove(int maxDepth, bool maximising);
        bool playMove(BlokusMove move, bool maximising);
        bool gameOver();
        const BlokusBoard& getBoard() const;

};