#include <iostream>

#include <board.h>

BlokusBoard::BlokusBoard(){
    height = HEIGHT;
    width = WIDTH;
    cpuTurn = true;
    BlokusBoard::reset();
}


void BlokusBoard::reset(){
    std::cout << "Resetting the board of size: (" << WIDTH << ", " << HEIGHT << ")"<<std::endl;

    for(int i = 0; i < WIDTH ; i++){
        for(int j = 0 ; j < HEIGHT ; j++){
            state[i][j] = false;
        }
    }
    printBoardState();
}


void BlokusBoard::printBoardState(){

    std::cout<< "*****************************************" << std::endl; 
    std::cout<< "****************BLOKUS*******************" << std::endl; 
    std::cout<< "*****************************************" << std::endl; 



    std::string strRepr;
    for(int i = 0; i < WIDTH ; i++){
        for(int j = 0 ; j < HEIGHT ; j++){
            bool filled = state[i][j];
            std::string x;
            if(filled){
                x = "[X]";
            } else{
                x = "[ ]";
            }
            strRepr += x + " ";
        }
        strRepr += "\n";
    }
    std::cout<<strRepr;
}

bool BlokusBoard::placePiece(std::unique_ptr<BlokusPiece>& p, int x, int y){
    if(x<0 || y <0 ){
        return false;
    }

    if(x + p->getWidth() > WIDTH || y + p->getHeight() > HEIGHT){
        return false;
    }

    for(int i = 0 ; i < p->getWidth() ; i++){
        for(int j = 0 ; j < p->getHeight(); j++){
            bool blockUsed = state[y+j][x+i];
            bool pieceBlockUsed = p->getXY(j, i);
            if(blockUsed && pieceBlockUsed){
                return false;
            }
            state[y+j][x+i] = pieceBlockUsed;
        }
    }
    return true;
}

int BlokusBoard::getWidth(){
    return width;
}

int BlokusBoard::getHeight(){
    return height;
}

bool BlokusBoard::isCpuTurn(){
    return cpuTurn;
}