#include <iostream>

#include <board.h>

BlokusBoard::BlokusBoard(){
    height = HEIGHT;
    width = WIDTH;
}


void BlokusBoard::reset(){
    std::cout << "Resetting the board of size: (" << WIDTH << ", " << HEIGHT << ")"<<std::endl;

    for(int i = 0; i < WIDTH ; i++){
        for(int j = 0 ; j < HEIGHT ; j++){
            state[i][j] = 0;
        }
    }
}


void BlokusBoard::printBoardState(){

    std::cout<< "*****************************************" << std::endl; 
    std::cout<< "****************BLOKUS*******************" << std::endl; 
    std::cout<< "*****************************************" << std::endl; 

    std::string strRepr;
    for(int i = 0; i < WIDTH ; i++){
        for(int j = 0 ; j < HEIGHT ; j++){
            strRepr += getstrReprForBlock(i, j) + " ";
        }
        strRepr += "\n";
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
            bool blockUsed = state[row+j][col+i] != 0;
            bool pieceBlockUsed = piece.getXY(j, i);
            if(blockUsed && pieceBlockUsed){
                return false;
            }
            if(pieceBlockUsed && (
                row+j-1 >= 0 && state[row+j-1][col+i] == turn || // UP
                row+j+1 < HEIGHT && state[row+j+1][col+i] == turn || // DOWN
                col+i-1 >= 0 && state[row+j][col+i-1] == turn || // LEFT
                col+i+1 < WIDTH && state[row+j][col+i+1] == turn // RIGHT
            )){
                return false;
            }
        }
    }
    for(int i = 0 ; i < piece.getWidth() ; i++){
        for(int j = 0 ; j < piece.getHeight(); j++){
            bool pieceBlockUsed = piece.getXY(j, i);
            if(pieceBlockUsed){
                state[row+j][col+i] = turn;
            }
        }
    }
    return true;
}

std::string BlokusBoard::getstrReprForBlock(int row, int col){
    std::string strRep;
    uint8_t tileState = state[row][col];
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
    return width;
}

int BlokusBoard::getHeight(){
    return height;
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
    for(int i = 0 ; i < WIDTH ; i++){
        for(int j = 0 ; j < HEIGHT; j++){
            hash += std::to_string(state[i][j]);
        }
    }
    return hash;
}