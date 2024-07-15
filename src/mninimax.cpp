#include <iostream>
#include <minimax.h>

int minimax(BlokusMatch& match, int depth, int alpha, int beta, bool maximising){
    if(depth == 0 || match.gameOver(maximising)){
        return match.evaluatePosition();
    }
    if(maximising){
        int maxEval = -10000;
        for (const auto& move : match.getMovesFromPos(maximising)){ // todo: might ge tout of sync with turn. best to handle turn as an arg.
            // BlokusMatch matchCopy(match);
            match.applyMove(std::get<0>(move), std::get<1>(move), std::get<2>(move), maximising);
            int eval = minimax(match, depth-1, alpha, beta, false);
            match.removeMove(std::get<0>(move), std::get<1>(move), std::get<2>(move), maximising);
            maxEval = std::max(maxEval, eval);
            alpha = std::max(alpha, eval);
            if(beta <= alpha){
                break;
            }
        }
        return maxEval;
    } else{
        int minEval = 20000;
        auto moves = match.getMovesFromPos(maximising);
        
        for (const auto& move : moves){ // todo: might ge tout of sync with turn. best to handle turn as an arg.
            // BlokusMatch matchCopy(match);
            match.applyMove(std::get<0>(move), std::get<1>(move), std::get<2>(move), maximising);
            int eval = minimax(match, depth-1, alpha, beta, true);
            match.removeMove(std::get<0>(move), std::get<1>(move), std::get<2>(move), maximising);
            minEval = std::min(minEval, eval);
            beta = std::min(beta, eval);
            if(beta <= alpha){
                break;
            }
        }
        return minEval;
    }
    return maximising;
}

BlokusMove getNextMove(BlokusMatch& match, int maxDepth, bool maximising){
    if (maximising){ // super dirty
        int maxEval = -10000;
        BlokusMove bestMove;
        for (const auto& move : match.getMovesFromPos(maximising)){
            // BlokusMatch matchCopy(match);
            match.applyMove(std::get<0>(move), std::get<1>(move), std::get<2>(move), maximising);
            int eval = minimax(match, maxDepth-1, -1000, 1000, !maximising);
            match.removeMove(std::get<0>(move), std::get<1>(move), std::get<2>(move), maximising);
            
            if(eval > maxEval){
                std::cout << "found better one" <<std::endl;
                bestMove = move;
                maxEval = eval;
            }
        }
        std::cout << "Max chose move with eval " << std::to_string(maxEval) << std::endl; 
        return bestMove;
    } else {
        int maxEval = 10000;
        BlokusMove bestMove;
        for (const auto& move : match.getMovesFromPos(maximising)){
            // BlokusMatch matchCopy(match);
            match.applyMove(std::get<0>(move), std::get<1>(move), std::get<2>(move), maximising);
            int eval = minimax(match, maxDepth-1, -1000, 1000, !maximising);
            match.removeMove(std::get<0>(move), std::get<1>(move), std::get<2>(move), maximising);
            if(eval < maxEval){
                bestMove = move;
                maxEval = eval;
            }
        }
        std::cout << "MIN chose move with eval " << std::to_string(maxEval) << std::endl; 
        return bestMove;
    }
}