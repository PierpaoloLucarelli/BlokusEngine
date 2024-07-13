#include <iostream>
#include <minimax.h>

int minimax(BlokusMatch& match, int depth, bool maximising){
    if(depth == 0 || match.gameOver()){
        return match.evaluatePosition();
    }
    if(maximising){
        int maxEval = -10000;
        for (const auto& move : match.getMovesFromPos()){ // todo: might ge tout of sync with turn. best to handle turn as an arg.
            BlokusMatch matchCopy(match);
            matchCopy.applyMove(std::get<0>(move), std::get<1>(move), std::get<2>(move));
            int eval = minimax(matchCopy, depth-1, false);
            maxEval = std::max(maxEval, eval);
        }
        return maxEval;
    } else{
        int minEval = 1000;
        for (const auto& move : match.getMovesFromPos()){ // todo: might ge tout of sync with turn. best to handle turn as an arg.
            BlokusMatch matchCopy(match);
            matchCopy.applyMove(std::get<0>(move), std::get<1>(move), std::get<2>(move));
            int eval = minimax(matchCopy, depth-1, true);
            minEval = std::min(minEval, eval);
        }
        return minEval;
    }
    return maximising;
}

BlokusMove getNextMove(BlokusMatch& match, int maxDepth){
    int maxEval = -10000;
    BlokusMove bestMove;
    for (const auto& move : match.getMovesFromPos()){
        BlokusMatch matchCopy(match);
        matchCopy.applyMove(std::get<0>(move), std::get<1>(move), std::get<2>(move));
        int eval = minimax(matchCopy, maxDepth-1, false);
        if(eval > maxEval){
            bestMove = move;
            maxEval = eval;
        }
    }
    return bestMove;
}