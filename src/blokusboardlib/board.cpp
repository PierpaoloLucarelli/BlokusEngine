#include <iostream>
#include <cstring>
#include <cstdint>
#include <board.h>

BlokusBoard::BlokusBoard(){

}


BlokusBoard::BlokusBoard(const BlokusBoard& otherBoard){
    std::memcpy(state, otherBoard.state, WIDTH * HEIGHT  * sizeof(uint8_t) );
}


void BlokusBoard::reset(){
    for(int i = 0; i < WIDTH*HEIGHT ; i++){
        state[i] = EMPTYCELL;
    }
}

std::vector<uint8_t> BlokusBoard::getState(){
    return std::vector<uint8_t>(std::begin(state), std::end(state));
}

void BlokusBoard::setState(int row, int col, uint8_t turn){
    state[row*WIDTH + col] = turn;
}

bool BlokusBoard::isOccupied(int row, int col){
    return state[row*WIDTH + col] != EMPTYCELL;
}

bool BlokusBoard::placePiece(const Block& piece, int row, int col, uint8_t rotation, uint8_t turn){
    std::vector<std::pair<int, int>> coords = piece.coords[rotation];
    for (const auto& coord : coords) {
        setState(row+coord.second, col+coord.first, turn);
    }
    return true;
}


bool BlokusBoard::canPlacePiece(const Block& piece, int row, int col, uint8_t rotation, uint8_t turn, bool firstMove){
    if(col<0 || row <0 || row > HEIGHT-1 || col > WIDTH-1){
        return false;
    }
    if (firstMove == true){
        if (isInCorner(piece, row, col, rotation)){
            return false;
        }
    }
    std::vector<std::pair<int, int>> coords = piece.coords[rotation];
    if(firstMove){
        if(isInCorner(piece, row, col, rotation)){
            for (const auto& coord : coords) {
                int newRow = row + coord.second;
                int newCol = col + coord.first;
                if(isOccupied(newRow, newCol)){ // TODO: can maybe be combined into one loop.
                    return false;
                }
            }
            return true;
        } else {
            return false;
        }
    }

    bool hasDiagonal = false;

    for (const auto& coord : coords) {
        int newRow = row + coord.second;
        int newCol = col + coord.first;

        if(newCol<0 || newRow <0 || newRow > HEIGHT-1 || newCol > WIDTH-1){ // out of bounds.
            return false;
        }

        if(isOccupied(newRow, newCol)){
            return false;
        }

        if (isAdjacentOccupied(newRow, newCol, turn)) {
            return false;
        }

        if (isDiagonalOccupied(newRow, newCol, turn)) {
            hasDiagonal = true;
        }
    }
    return hasDiagonal;
}

const char* BlokusBoard::getStrReprForBlock(int i){
    int8_t tileState = state[i];
    if(tileState == 0){
        return "[#]";
    } else if(tileState == 1){
        return "[O]";
    } else if(tileState == 2){
          return "[X]";
      } else if(tileState == 3){
          return "[+]";
    } else{
        return "[ ]";
    }
}

std::string BlokusBoard::getStrReprForBoard() const{
    std::string boardStr;
    for(int i = 0 ; i < WIDTH * HEIGHT ; i++){
        boardStr += static_cast<char>(state[i]);
    }
    return boardStr;
}

int BlokusBoard::getWidth() const{
    return WIDTH;
}

int BlokusBoard::getHeight() const{
    return HEIGHT;
}

bool BlokusBoard::isInCorner(const Block& piece, int row, int col, uint8_t rotation){
    bool touchesCorner = false;
    std::vector<std::pair<int, int>> coords = piece.coords[rotation];
    for(const auto coord : coords){
        int newRow = row + coord.second;
        int newCol = col + coord.first;

        if ((newRow < 0 || newRow > HEIGHT-1) || (newCol < 0 || newCol > WIDTH-1)){
            return false;
        }

        if (
            (newRow == 0 && newCol == 0) || 
            (newRow == 0 && newCol == WIDTH - 1) ||
            (newRow == WIDTH - 1 && newCol == 0) ||
            (newRow == WIDTH - 1 && newCol == HEIGHT - 1)
          ) {
            touchesCorner = true;
          }
    }
    return touchesCorner;
}

void BlokusBoard::removePiece(const Block& piece, int row, int col, uint8_t rotation){

    std::vector<std::pair<int, int>> coords = piece.coords[rotation];
    for(const auto coord : coords){
        int newRow = row + coord.second;
        int newCol = col + coord.first;

        setState(newRow, newCol, EMPTYCELL);
    }
}

bool BlokusBoard::isAdjacentOccupied(int row, int col, uint8_t turn){
    return (
        (row-1 >= 0 && state[(row-1)*WIDTH + col] == turn) || // UP
        (row+1 < HEIGHT && state[(row+1) * WIDTH + col] == turn) || // DOWN
        (col-1 >= 0 && state[row * WIDTH + col-1] == turn) || // LEFT
        (col+1 < WIDTH && state[row * WIDTH + col+1] == turn) // RIGHT
    );
}

bool BlokusBoard::isDiagonalOccupied(int row, int col, uint8_t turn){
    return (
        (row-1 >= 0 && col-1 >= 0 && state[(row-1)*WIDTH + col-1] == turn) || // UP-LEFT
        (row+1 < HEIGHT && col-1 >= 0 && state[(row+1) * WIDTH + col-1] == turn) || // DOWN-LEFT
        (row+1 < HEIGHT && col+1 < WIDTH && state[(row+1) * WIDTH + col+1] == turn) || // DOWN-RIGHT
        (row-1 >= 0 && col+1 < WIDTH && state[(row-1) * WIDTH + col+1] == turn) // UP-RIGHT
    );
}

void BlokusBoard::printBoardState(){

    std::cout<< "*****************************************" << std::endl;
    std::cout<< "****************BLOKUS*******************" << std::endl;
    std::cout<< "*****************************************" << std::endl;

    std::string colNums = "";
    for(int i = 0 ; i < WIDTH ; i++){
        colNums += " " + std::to_string(i%10) + "  ";
    }
    std::cout<<colNums<<std::endl;
    std::string strRepr;
    for(int i = 0; i < WIDTH * HEIGHT ; i++){
        strRepr += std::string(getStrReprForBlock(i)) + " ";
        if((i+1) % WIDTH == 0){
            strRepr += std::to_string(i/WIDTH) + " \n";
        }
    }
    std::cout<<strRepr;
}
