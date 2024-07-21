#include <iostream>
#include <minimax.h>

int seen = 0;

int minimax(BlokusMatch& match, int depth, int alpha, int beta, bool maximising){
    seen++;
    // std::cout<<seen<<std::endl;
    if(depth == 0 || match.gameOver()){
        // std::cout<<depth<<std::endl;
        // std::cout<<match.getPiecesForPlayer(0).size()<<std::endl;
        // std::cout<<match.getPiecesForPlayer(1).size()<<std::endl;
        // match.getBoard().printBoardState();
        return match.evaluatePosition();
    }
    if(maximising){
        int maxEval = -10000;
        std::vector<BlokusMove> maxMoves = match.getMovesFromPos(maximising);
        // std::cout<<maxMoves.size()<<std::endl;
        for (const auto& move : maxMoves){
            match.applyMove(std::get<0>(move), std::get<1>(move), std::get<2>(move), std::get<3>(move), maximising);
            int eval = minimax(match, depth-1, alpha, beta, false);
            match.removeMove(std::get<0>(move), std::get<1>(move), std::get<2>(move), std::get<3>(move), maximising);
            maxEval = std::max(maxEval, eval);
            alpha = std::max(alpha, eval);
            if(beta <= alpha){
                break;
            }
        }
        return maxEval;
    } else{
        int minEval = 20000;
        std::vector<BlokusMove> minMoves = match.getMovesFromPos(maximising);
        // std::cout<<minMoves.size()<<std::endl;
        for (const auto& move : minMoves){
            match.applyMove(std::get<0>(move), std::get<1>(move), std::get<2>(move), std::get<3>(move), maximising);
            int eval = minimax(match, depth-1, alpha, beta, true);
            match.removeMove(std::get<0>(move), std::get<1>(move), std::get<2>(move), std::get<3>(move), maximising);
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
        std::vector<BlokusMove> maxMoves = match.getMovesFromPos(maximising);
        // std::cout<<maxMoves.size()<<std::endl;
        for (const auto& move : maxMoves){
            match.applyMove(std::get<0>(move), std::get<1>(move), std::get<2>(move), std::get<3>(move), maximising);
            int eval = minimax(match, maxDepth-1, -1000, 1000, !maximising);
            match.removeMove(std::get<0>(move), std::get<1>(move), std::get<2>(move), std::get<3>(move), maximising);
            if(eval > maxEval){
                bestMove = move;
                maxEval = eval;
            }
        }
        std::cout << "Max chose move with eval " << std::to_string(maxEval) << std::endl; 
        return bestMove;
    } else {
        int maxEval = 10000;
        BlokusMove bestMove;
        std::vector<BlokusMove> minMoves = match.getMovesFromPos(maximising);
        // std::cout<<minMoves.size()<<std::endl;
        for (const auto& move : minMoves){
            match.applyMove(std::get<0>(move), std::get<1>(move), std::get<2>(move), std::get<3>(move), maximising);
            int eval = minimax(match, maxDepth-1, -1000, 1000, !maximising);
            match.removeMove(std::get<0>(move), std::get<1>(move), std::get<2>(move), std::get<3>(move), maximising);
            if(eval < maxEval){
                bestMove = move;
                maxEval = eval;
            }
        }
        std::cout << "MIN chose move with eval " << std::to_string(maxEval) << std::endl; 
        return bestMove;
    }
}