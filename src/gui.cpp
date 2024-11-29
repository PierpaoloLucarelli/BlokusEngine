#include <iostream>
#include <gui.h>

BlokusGUI::BlokusGUI(){

    paddingTop = 5;

    initscr();

    int height, width, split;
    getmaxyx(stdscr, height, width);
    split = width / 2;
    mainGameWindow = newwin(height, width, 0, 0);
    mainGame = subwin(mainGameWindow, height, width, 0, 0);
    pieces = newwin(height, width, 0, split);

    pieceTest = newwin(5, 5, 0, split+1);

    box(mainGameWindow, 0, 0);
    box(pieces, 0, 0);
    box(pieceTest, 0, 0);
    
    wrefresh(pieces);
    wrefresh(pieceTest);

    refresh();

}

void BlokusGUI::endGUI(){
    endwin();
}

WINDOW* BlokusGUI::getGameWindow(){
    return mainGame;
}

void BlokusGUI::printGameState(BlokusBoard& board){
    // wclear(mainGame);
    mvwprintw(mainGame, paddingTop+1, 5, "************************************************");
    mvwprintw(mainGame, paddingTop+2, 5, "*******************BLOKUS***********************");
    mvwprintw(mainGame, paddingTop+3, 5, "************************************************");
    std::string strRepr;
    for(int i = 0; i < board.getWidth() * board.getHeight() ; i++){
        mvwprintw(mainGame, paddingTop+4+(int)i/board.getWidth(), 7+(i%board.getWidth())*3, "%s", board.getStrReprForBlock(i));
    }

    wrefresh(mainGame);
}