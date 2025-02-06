#include <iostream>
#include <board.h>
#include <pieceShapes.h>
#include <match.h>
#include "minimax.h"
#include <chrono>
#include <thread>

void waitForExit() {
    int t;
    std::cout << "Game finished! Press any key to exit!";
    std::cin >> t;
}

int main(){
    BlokusBoard board;
    initializePieceMap();
    BlokusMatch match(board);
    match.newGame();
    match.printGame();
    bool maxPlayer = true;
    waitForExit();
    return 0;
}
