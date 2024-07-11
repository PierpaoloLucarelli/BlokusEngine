#include <iostream>
#include <cstring>

#include <board.h>

BlokusBoard::BlokusBoard(){

}


BlokusBoard::BlokusBoard(BlokusBoard& otherBoard){
    std::memcpy(state, otherBoard.state, WIDTH * HEIGHT  * sizeof(uint8_t) );
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

    std::string strRepr;
    for(int i = 0; i < WIDTH * HEIGHT ; i++){
        strRepr += getStrReprForBlock(i) + " ";
        if((i+1) % WIDTH == 0){
            strRepr += "\n";
        }
    }
    std::cout<<strRepr;
}

bool BlokusBoard::placePiece(blokusShapeType p, int col, int row, uint8_t turn){

    auto it = piecesMap.find(p);
    
    if(it == piecesMap.end()){
        return false;
    }

    auto piece = it->second;

    if(col<0 || row <0 ){
        return false;
    }

    if(col + piece.getWidth() > WIDTH || row + piece.getHeight() > HEIGHT){
        return false;
    }

    for(int i = 0 ; i < piece.getWidth() ; i++){
        for(int j = 0 ; j < piece.getHeight(); j++){
            bool blockUsed = state[(row+j)*WIDTH + col+i] != 0;
            bool pieceBlockUsed = piece.getXY(j, i);
            if(blockUsed && pieceBlockUsed){
                return false;
            }
            if(pieceBlockUsed && (
                row+j-1 >= 0 && state[(row+j-1)*WIDTH + col+i] == turn || // UP
                row+j+1 < HEIGHT && state[(row+j+1) * WIDTH + col+i] == turn || // DOWN
                col+i-1 >= 0 && state[(row+j)*WIDTH + col+i-1] == turn || // LEFT
                col+i+1 < WIDTH && state[(row+j)*WIDTH + col+i+1] == turn // RIGHT
            )){
                return false;
            }
        }
    }
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

std::string BlokusBoard::getStrReprForBlock(int i){
    std::string strRep;
    uint8_t tileState = state[i];
    if(tileState == 1){
        strRep = "[X]";
    } else if(tileState == 2){
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

bool BlokusBoard::isInCorner(blokusShapeType p, int row, int col){
    bool usesCorner = false;
    auto it = piecesMap.find(p);
    if(it == piecesMap.end()){
        return false;
    }
    auto piece = it->second;
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

std::string BlokusBoard::hash(){
    std::string hash = "";
    for(int i = 0 ; i < WIDTH * HEIGHT; i++){
        hash += std::to_string(state[i]);
    }
    return hash;
}