#include <iostream>
#include <minimax.h>

int minimax(BlokusMatch match, int depth, bool maximising){
    if(depth == 0 || match.gameOver()){
        match.evaluatePosition();
    }
    maximising = false; // todo remove
    return maximising;
}