#include <iostream>
#include <minimax.h>

int minimax(BlokusMatch& match, int depth, int alpha, int beta, bool maximising){
    if(depth == 0 || match.gameOver()){
        return match.evaluatePosition();
    }
    if(maximising){
        int maxEval = -10000;
        for (const auto& move : match.getMovesFromPos()){ // todo: might ge tout of sync with turn. best to handle turn as an arg.
            BlokusMatch matchCopy(match);
            matchCopy.applyMove(std::get<0>(move), std::get<1>(move), std::get<2>(move));
            int eval = minimax(matchCopy, depth-1, alpha, beta, false);
            maxEval = std::max(maxEval, eval);
            alpha = std::max(alpha, eval);
            if(beta <= alpha){
                break;
            }
        }
        return maxEval;
    } else{
        int minEval = 10000;
        for (const auto& move : match.getMovesFromPos()){ // todo: might ge tout of sync with turn. best to handle turn as an arg.
            BlokusMatch matchCopy(match);
            matchCopy.applyMove(std::get<0>(move), std::get<1>(move), std::get<2>(move));
            int eval = minimax(matchCopy, depth-1, alpha, beta, true);
            beta = std::min(beta, eval);
            if(beta <= alpha){
                break;
            }
            minEval = std::min(minEval, eval);
        }
        return minEval;
    }
    return maximising;
}

BlokusMove getNextMove(BlokusMatch& match, int maxDepth, bool maximising){
    if (maximising){ // super dirty
        int maxEval = -10000;
        BlokusMove bestMove;
        for (const auto& move : match.getMovesFromPos()){
            BlokusMatch matchCopy(match);
            matchCopy.applyMove(std::get<0>(move), std::get<1>(move), std::get<2>(move));
            int eval = minimax(matchCopy, maxDepth-1, -1000, 1000, false);
            if(eval > maxEval){
                bestMove = move;
                maxEval = eval;
            }
        }
        std::cout << "chose move with eval " << std::to_string(maxEval) << std::endl; 
        return bestMove;
    } else {
        int maxEval = 10000;
        BlokusMove bestMove;
        for (const auto& move : match.getMovesFromPos()){
            BlokusMatch matchCopy(match);
            matchCopy.applyMove(std::get<0>(move), std::get<1>(move), std::get<2>(move));
            int eval = minimax(matchCopy, maxDepth-1, -1000, 1000,false);
            if(eval < maxEval){
                bestMove = move;
                maxEval = eval;
            }
        }
        std::cout << "chose move with eval " << std::to_string(maxEval) << std::endl; 
        return bestMove;
    }
}