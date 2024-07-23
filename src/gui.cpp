#include <gui.h>

BlokusGUI::BlokusGUI(){
    initscr();
    mainGame = newwin(30, 60, 0, 0);
    box(mainGame, 0, 0);
}

void BlokusGUI::endGUI(){
    endwin();
}

WINDOW* BlokusGUI::getGameWindow(){
    return mainGame;
}

void BlokusGUI::printGameState(BlokusBoard& board){
    wclear(mainGame);
    mvwprintw(mainGame, 1, 5, "************************************************");
    mvwprintw(mainGame, 2, 5, "*******************BLOKUS***********************");
    mvwprintw(mainGame, 3, 5, "************************************************");
    std::string strRepr;
    for(int i = 0; i < board.getWidth() * board.getHeight() ; i++){
        mvwprintw(mainGame, 4+(int)i/board.getWidth(), 7+(i%board.getWidth())*3, "%s", board.getStrReprForBlock(i));
    }

    wrefresh(mainGame);
}