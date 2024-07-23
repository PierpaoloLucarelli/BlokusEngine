#pragma once
#include <ncurses.h>
#include <board.h>

class BlokusGUI{
    private: 
        WINDOW* mainGame;

    public:
        BlokusGUI();
        WINDOW* getGameWindow();
        void endGUI();
        void printGameState(BlokusBoard& board);
};