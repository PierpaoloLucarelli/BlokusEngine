#include <iostream>
#include <cstring>

#include <board.h>

BlokusBoard::BlokusBoard(){

}


BlokusBoard::BlokusBoard(BlokusBoard& otherBoard){
    std::memcpy(state, otherBoard.state, WIDTH * HEIGHT  * sizeof(int8_t) );
}


void BlokusBoard::reset(){
    // std::cout << "Resetting the board of size: (" << WIDTH << ", " << HEIGHT << ")"<<std::endl;
    for(int i = 0; i < WIDTH*HEIGHT ; i++){
        state[i] = 0;
    }
}

bool BlokusBoard::placePiece(BlokusPiece& piece, int row, int col, uint8_t rotation, int8_t turn){
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


bool BlokusBoard::canPlacePiece(BlokusPiece& piece, int row, int col, uint8_t rotation, int8_t turn, bool firstMove){
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
            bool blockUsed = state[(row+j)*WIDTH + col+i] != 0;
            bool pieceBlockUsed = rotated[j][i];
            if(blockUsed && pieceBlockUsed){
                return false;
            }
            if(pieceBlockUsed) {  
                if( // touches own piece
                    (row+j-1 >= 0 && state[(row+j-1)*WIDTH + col+i] == turn) || // UP
                    (row+j+1 < HEIGHT && state[(row+j+1) * WIDTH + col+i] == turn) || // DOWN
                    (col+i-1 >= 0 && state[(row+j)*WIDTH + col+i-1] == turn) || // LEFT
                    (col+i+1 < WIDTH && state[(row+j)*WIDTH + col+i+1] == turn) // RIGHT
                ){
                    return false;
                }

                if(
                    !firstMove && !touchesSelfCorner && (
                        (row+j-1 >= 0 && col+i-1 >= 0 && state[(row+j-1)*WIDTH + col+i-1] == turn) || // UP-LEFT
                        (row+j+1 < HEIGHT && col+i-1 >= 0 && state[(row+j+1) * WIDTH + col+i-1] == turn) || // DOWN-LEFT
                        (row+j+1 < HEIGHT && col+i+1 < WIDTH && state[(row+j+1) * WIDTH + col+i+1] == turn) || // DOWN-RIGHT
                        (row+j-1 >= 0 && col+i+1 < WIDTH && state[(row+j-1) * WIDTH + col+i+1] == turn) // UP-RIGHT
                    )
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
    if(tileState == 1){
        return "[#]";
    } else if(tileState == -1){
        return "[O]";
    } else{
        return "[ ]";
    }
}

int BlokusBoard::getWidth(){
    return WIDTH;
}

int BlokusBoard::getHeight(){
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
            if (pieceBlockUsed && ( // is corner
                (boardRow == 0 && boardCol == 0) || 
                (boardRow == 0 && boardCol == WIDTH - 1) || 
                (boardRow == HEIGHT - 1 && boardCol == 0) || 
                (boardRow == HEIGHT - 1 && boardCol == WIDTH - 1)
            )){
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