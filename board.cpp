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

bool BlokusBoard::placePiece(blokusShapeType p, int x, int y, uint8_t turn){

    auto it = piecesMap.find(p);
    
    if(it == piecesMap.end()){
        return false;
    }

    auto piece = it->second;

    if(x<0 || y <0 ){
        return false;
    }

    if(x + piece.getWidth() > WIDTH || y + piece.getHeight() > HEIGHT){
        return false;
    }

    for(int i = 0 ; i < piece.getWidth() ; i++){
        for(int j = 0 ; j < piece.getHeight(); j++){
            bool blockUsed = state[y+j][x+i] != 0;
            bool pieceBlockUsed = piece.getXY(j, i);
            if(blockUsed && pieceBlockUsed){
                return false;
            }
            if(pieceBlockUsed && (
                y-1 >= 0 && state[y+j-1][x+i] == turn || // UP
                y+1 < HEIGHT && state[y+j+1][x+i] == turn || // DOWN
                x-1 >= 0 && state[y+j][x+i-1] == turn || // LEFT
                x+1 < WIDTH && state[y+j][x+i+1] == turn // RIGHT
            )){
                return false;
            }
        }
    }
    for(int i = 0 ; i < piece.getWidth() ; i++){
        for(int j = 0 ; j < piece.getHeight(); j++){
            bool pieceBlockUsed = piece.getXY(j, i);
            if(pieceBlockUsed){
                state[y+j][x+i] = turn;
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