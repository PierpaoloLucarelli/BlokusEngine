#include <iostream>
#include <minimax.h>
#include <board.h>

int seen = 0;
std::unordered_map<BlokusBoard, int, BlokusBoardHashFunction> seenBoards;


int minimax(BlokusMatch& match, int depth, int alpha, int beta, bool maximising){
    seen++;
    if(depth == 0 || match.gameOver()){
        return match.evaluatePosition();
    }

    int bestEval = maximising ? -1000000 : 1000000;
    std::vector<BlokusMove> moves = match.getMovesFromPos(maximising);
    for (const auto& move : moves){
        match.applyMove(std::get<0>(move), std::get<1>(move), std::get<2>(move), std::get<3>(move), maximising);
        int eval = minimax(match, depth-1, alpha, beta, !maximising);
        match.removeMove(std::get<0>(move), std::get<1>(move), std::get<2>(move), std::get<3>(move), maximising);

        if(maximising){
            bestEval = std::max(bestEval, eval);
            alpha = std::max(alpha, eval);
        } else{
            bestEval = std::min(bestEval, eval);
            beta = std::min(beta, eval);
        }
        if(beta <= alpha){
            break;
        }
    }
    return bestEval;
}

BlokusMove getNextMove(BlokusMatch& match, int maxDepth, bool maximising){
    seen = 0;
    seenBoards.clear();
    BlokusMove bestMove;

    int bestEval = maximising ? -1000000 : 1000000;
    std::vector<BlokusMove> moves = match.getMovesFromPos(maximising);
    for (const auto& move : moves){
        match.applyMove(std::get<0>(move), std::get<1>(move), std::get<2>(move), std::get<3>(move), maximising);
        const BlokusBoard& board = match.getBoard();
        auto it = seenBoards.find(board);
        int eval;
        if (it != seenBoards.end()) {
            eval = it->second;
        } else {
            eval = minimax(match, maxDepth-1, -1000, 1000, !maximising);
        }
        seenBoards[board] = eval;
        match.removeMove(std::get<0>(move), std::get<1>(move), std::get<2>(move), std::get<3>(move), maximising);

        if((maximising && (eval > bestEval)) || (!maximising && eval < bestEval)){
            bestMove = move;
            bestEval = eval;
        }
    }
    return bestMove;
}