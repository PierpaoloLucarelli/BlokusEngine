#include <iostream>
#include "piece.h"


BlokusPiece::BlokusPiece(std::vector<std::vector<bool>>& myShape, bool isSymmetric) : shape(myShape){
    
    width = myShape[0].size();
    height = myShape.size();
    symmetric = isSymmetric;
}

void BlokusPiece::printPiece(){
    std::string strRepr;
    for(int i = 0 ; i < width ; i++){
        for(int j = 0 ; j < height ; j++){
            bool filled = shape[i][j];
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

int BlokusPiece::getWidth(){
    return width;
}

int BlokusPiece::getHeight(){
    return height;
}

bool BlokusPiece::getXY(int x, int y){
    return shape[x][y];
}

bool BlokusPiece::isSymmetric(){
    return symmetric;
}