#include <iostream>
#include <piece.h>

BlokusPiece::BlokusPiece(std::vector<std::vector<bool>>& myShape, bool isSymmetric, std::string myId) : shape(myShape){
    
    width = myShape[0].size();
    height = myShape.size();
    id = myId;
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

bool BlokusPiece::operator==(const BlokusPiece& other) const {
    return id == other.id;
}

std::string BlokusPiece::getId() const{
    return id;
}