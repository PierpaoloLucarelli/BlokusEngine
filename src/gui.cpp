#include <gui.h>

BlokusGUI::BlokusGUI(){

    paddingTop = 5;

    initscr();
    mainGameWindow = newwin(30, 60, 0, 0);
    mainGame = subwin(mainGameWindow, 30, 60, 0, 0);
    pieces = newwin(30, 30, 0, 60);

    box(mainGameWindow, 0, 0);
    box(pieces, 0, 0);
    wrefresh(pieces);

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