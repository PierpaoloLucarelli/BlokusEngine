#include <iostream>
#include <minimax.h>

int minimax(BlokusMatch match, int depth, bool maximising){
    if(depth == 0 || match.gameOver()){
        match.evaluatePosition();
    }
    return 1;
}

std::vector<BlokusMove> getMovesFromMatch(BlokusMatch& match) {
    std::vector<BlokusMove> moves; 
    std::unordered_set<blokusShapeType>& playerPieces = match.getPiecesForCurretPlayer();

    BlokusBoard& board = match.getBoard();
    int w = board.getWidth();

    for(const auto& piece : playerPieces){
        for(int i = 0 ; i < board.getHeight() * board.getWidth(); i++){
            BlokusMatch matchCopy(match); 
            if(matchCopy.playMove(piece, (int)i/w, i%w)){ // can play move
                moves.push_back(std::make_tuple(piece, (int)i/w, i%w));
                // matchCopy.getBoard().printBoardState();
            };
        }
    }
   return moves;
}