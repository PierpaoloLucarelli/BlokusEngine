#pragma once
#include <ncurses.h>
#include <board.h>

class BlokusGUI{
    private: 
        WINDOW* mainGameWindow;
        WINDOW* mainGame;
        WINDOW* pieces;
        WINDOW* pieceTest;
        int paddingTop;

    public:
        BlokusGUI();
        WINDOW* getGameWindow();
        void endGUI();
        void printGameState(const BlokusBoard& board);
};