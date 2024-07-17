#include <iostream>
#include <cstring>

#include <board.h>

BlokusBoard::BlokusBoard(){

}


BlokusBoard::BlokusBoard(BlokusBoard& otherBoard){
    std::memcpy(state, otherBoard.state, WIDTH * HEIGHT  * sizeof(int8_t) );
}


void BlokusBoard::reset(){
    std::cout << "Resetting the board of size: (" << WIDTH << ", " << HEIGHT << ")"<<std::endl;
    for(int i = 0; i < WIDTH*HEIGHT ; i++){
        state[i] = 0;
    }
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
        strRepr += getStrReprForBlock(i) + " ";
        if((i+1) % WIDTH == 0){
            strRepr += std::to_string(i/WIDTH) + " \n";
        }
    }
    std::cout<<strRepr;
}

bool BlokusBoard::placePiece(BlokusPiece& piece, int row, int col, int8_t turn){
    for(int i = 0 ; i < piece.getWidth() ; i++){
            for(int j = 0 ; j < piece.getHeight(); j++){
                bool pieceBlockUsed = piece.getXY(j, i);
                if(pieceBlockUsed){
                    state[(row+j)*WIDTH + col+i] = turn;
                }
            }
        }
    return true;
}


bool BlokusBoard::canPlacePiece(BlokusPiece& piece, int row, int col, int8_t turn, bool firstMove){
    if(col<0 || row <0){
        return false;
    }

    if(row + piece.getHeight() > HEIGHT || col + piece.getWidth() > WIDTH){
        return false;
    }

    bool touchesSelfCorner = firstMove;

    for(int i = 0 ; i < piece.getWidth() ; i++){
        for(int j = 0 ; j < piece.getHeight(); j++){
            bool blockUsed = state[(row+j)*WIDTH + col+i] != 0;
            bool pieceBlockUsed = piece.getXY(j, i);
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

std::string BlokusBoard::getStrReprForBlock(int i){
    std::string strRep;
    int8_t tileState = state[i];
    if(tileState == 1){
        strRep = "[X]";
    } else if(tileState == -1){
        strRep = "[O]";
    } else{
        strRep = "[ ]";
    }
    return strRep;
}

int BlokusBoard::getWidth(){
    return WIDTH;
}

int BlokusBoard::getHeight(){
    return HEIGHT;
}

bool BlokusBoard::isInCorner(BlokusPiece& piece, int row, int col){
    for(int i = 0 ; i < piece.getWidth() ; i++){
        for(int j = 0 ; j < piece.getHeight(); j++){
            bool pieceBlockUsed = piece.getXY(j, i);
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

void BlokusBoard::removePiece(BlokusPiece& piece, int row, int col){
    for(int i = 0 ; i < piece.getWidth() ; i++){
        for(int j = 0 ; j < piece.getHeight(); j++){
            bool pieceBlockUsed = piece.getXY(j, i);
            if(pieceBlockUsed){
                state[(row+j)*WIDTH + col+i] = 0;
            }
        }
    }
}