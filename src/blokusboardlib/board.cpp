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

bool BlokusBoard::placePiece(BlokusPiece& piece, int row, int col, uint8_t rotation, uint8_t turn){
    std::vector<std::vector<bool>> rotated = piece.rotate(rotation);
    int w = static_cast<int>(rotated[0].size());
    int h = static_cast<int>(rotated.size());
    for(int i = 0 ; i < w ; i++){
        for(int j = 0 ; j < h; j++){
            bool pieceBlockUsed = rotated[j][i];
            if(pieceBlockUsed){
                state[(row+j)*WIDTH + col+i] = turn;
            }
        }
    }
    return true;
}


bool BlokusBoard::canPlacePiece(BlokusPiece& piece, int row, int col, uint8_t rotation, uint8_t turn, bool firstMove){
    if(col<0 || row <0){
        return false;
    }

    std::vector<std::vector<bool>> rotated = piece.rotate(rotation);
    int w = static_cast<int>(rotated[0].size());
    int h = static_cast<int>(rotated.size());

    if(row + h > HEIGHT || col + w > WIDTH){
        return false;
    }

    bool touchesSelfCorner = firstMove;

    for(int i = 0 ; i < w ; i++){
        for(int j = 0 ; j < h; j++){
            bool blockUsed = state[(row+j)*WIDTH + col+i] != EMPTYCELL;
            bool pieceBlockUsed = rotated[j][i];
            if(blockUsed && pieceBlockUsed){
                return false;
            }
            if(pieceBlockUsed) {
                if(isAdjacentOccupied(row+j, col+i, turn)){
                    return false;
                }

                if(!firstMove && !touchesSelfCorner && isDiagonalOccupied(row+j, col+i, turn)  // no need to check on first move or if already touching self
                ){
                    touchesSelfCorner = true;
                }
            }
        }

    }
    return touchesSelfCorner;
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

bool BlokusBoard::isInCorner(BlokusPiece& piece, int row, int col, uint8_t rotation){

    std::vector<std::vector<bool>> rotated = piece.rotate(rotation);
    int w = static_cast<int>(rotated[0].size());
    int h = static_cast<int>(rotated.size());
    for(int i = 0 ; i < w ; i++){
        for(int j = 0 ; j < h; j++){
            bool pieceBlockUsed = rotated[j][i];
            int boardRow = row+j;
            int boardCol = col+i;
            if (pieceBlockUsed && isCorner(boardRow, boardCol)){
                return true;
            }
        }
    }
    return false;
}

void BlokusBoard::removePiece(BlokusPiece& piece, int row, int col, uint8_t rotation){
    std::vector<std::vector<bool>> rotated = piece.rotate(rotation);
    int w = static_cast<int>(rotated[0].size());
    int h = static_cast<int>(rotated.size());
    for(int i = 0 ; i < w ; i++){
        for(int j = 0 ; j < h; j++){
            bool pieceBlockUsed = rotated[j][i];
            if(pieceBlockUsed){
                state[(row+j)*WIDTH + col+i] = 0;
            }
        }
    }
}

bool BlokusBoard::isCorner(int row, int col){
    return (
        (row == 0 && col == 0) ||
        (row == 0 && col == WIDTH - 1) ||
        (row == HEIGHT - 1 && col == 0) ||
        (row == HEIGHT - 1 && col == WIDTH - 1)
    );
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

int8_t BlokusBoard::getBlock(int row, int col){
    return state[row*WIDTH+col];
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
