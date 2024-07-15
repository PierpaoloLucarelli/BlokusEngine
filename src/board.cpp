#include <iostream>
#include <cstring>

#include <board.h>

namespace {
    BlokusPiece& getPiece(blokusShapeType p){
        auto it = piecesMap.find(p);
        if(it == piecesMap.end()){
            throw std::runtime_error("Piece not found in piece map");
        }
        return it->second;
    }
}

BlokusBoard::BlokusBoard(){

}

BlokusBoard::BlokusBoard(BlokusBoard& otherBoard){
    p1State = otherBoard.p1State;
    p2State = otherBoard.p2State;
}


void BlokusBoard::reset(){
    std::cout << "Resetting the board of size: (" << WIDTH << ", " << HEIGHT << ")"<<std::endl;
    p1State.reset();
    p2State.reset();
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

bool BlokusBoard::placePiece(blokusShapeType p,  int row, int col, int8_t turn){
    BlokusPiece& piece = getPiece(p);
    std::bitset<BOARDSIZE>& playerState = turn ? p1State : p2State;
    for(int i = 0 ; i < piece.getWidth() ; i++){
            for(int j = 0 ; j < piece.getHeight(); j++){
                bool pieceBlockUsed = piece.getXY(j, i);
                if(pieceBlockUsed){
                    playerState.set((row+j)*WIDTH + col+i);
                }
            }
        }
    return true;
}


bool BlokusBoard::canPlacePiece(blokusShapeType p, int row, int col, int8_t turn, bool firstMove){
    BlokusPiece& piece = getPiece(p);
    if(col<0 || row <0){
        return false;
    }

    if(row + piece.getHeight() > HEIGHT || col + piece.getWidth() > WIDTH){
        return false;
    }

    bool touchesSelfCorner = firstMove;
    std::bitset<BOARDSIZE>& playerState = turn ? p1State : p2State;
    for(int i = 0 ; i < piece.getWidth() ; i++){
        for(int j = 0 ; j < piece.getHeight(); j++){
            bool blockUsed = p1State.test((row+j)*WIDTH + col+i) || p2State.test((row+j)*WIDTH + col+i);
            bool pieceBlockUsed = piece.getXY(j, i);
            if(blockUsed && pieceBlockUsed){
                return false;
            }
            if(pieceBlockUsed) {  
                if( // touches own piece
                    (row+j-1 >= 0 && playerState.test((row+j-1)*WIDTH + col+i)) || // UP
                    (row+j+1 < HEIGHT && playerState.test((row+j+1) * WIDTH + col+i)) || // DOWN
                    (col+i-1 >= 0 && playerState.test((row+j)*WIDTH + col+i-1)) || // LEFT
                    (col+i+1 < WIDTH && playerState.test((row+j)*WIDTH + col+i+1)) // RIGHT
                ){
                    // std::cout<<"Touches own piece"<<std::endl;
                    return false;
                }

                if(
                    !firstMove && !touchesSelfCorner && (
                        (row+j-1 >= 0 && col+i-1 >= 0 && playerState.test((row+j-1)*WIDTH + col+i-1)) || // UP-LEFT
                        (row+j+1 < HEIGHT && col+i-1 >= 0 && playerState.test((row+j+1) * WIDTH + col+i-1)) || // DOWN-LEFT
                        (row+j+1 < HEIGHT && col+i+1 < WIDTH && playerState.test((row+j+1) * WIDTH + col+i+1)) || // DOWN-RIGHT
                        (row+j-1 >= 0 && col+i+1 < WIDTH && playerState.test((row+j-1) * WIDTH + col+i+1)) // UP-RIGHT
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
    bool p1PosState = p1State.test(i);
    if (p1PosState){
        return "[X]";
    } else {
        bool p2PosState = p2State.test(i);
        if(p2PosState){
            return "[O]";
        } else{
            return "[ ]";
        }
    }
}

int BlokusBoard::getWidth(){
    return WIDTH;
}

int BlokusBoard::getHeight(){
    return HEIGHT;
}

bool BlokusBoard::isInCorner(blokusShapeType p, int row, int col){
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

// std::string BlokusBoard::hash(){
//     std::string hash = "";
//     for(int i = 0 ; i < WIDTH * HEIGHT; i++){
//         hash += std::to_string(state[i]);
//     }
//     return hash;
// }