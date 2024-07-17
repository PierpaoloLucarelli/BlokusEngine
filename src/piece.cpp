#include <iostream>
#include <piece.h>

BlokusPiece::BlokusPiece(std::vector<std::vector<bool>> myShape, bool isSymmetric, std::string myId, int pieceSize) : shape(myShape){
    
    width = myShape[0].size();
    height = myShape.size();
    id = myId;
    size = pieceSize;
    symmetric = isSymmetric;
}

void BlokusPiece::printPiece(){
    std::string strRepr;
    for(size_t i = 0 ; i < shape[0].size() ; i++){
        for(size_t j = 0 ; j < shape.size() ; j++){
            bool filled = shape[i][j];
            std::string x;
            if(filled){
                x = "[X]";
            } else {
                x = "[ ]";
            }
            strRepr += x + " ";
        }
        strRepr += "\n";
    }
    std::cout<<strRepr;
}

int BlokusPiece::getWidth(){
    return shape[0].size();
}

int BlokusPiece::getHeight(){
    return shape.size();
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

int BlokusPiece::getSize(){
    return size;
}

std::vector<std::vector<bool>> BlokusPiece::rotate(uint8_t rotation){

    if(rotation == 0){
        return shape;
    }
    std::vector<std::vector<bool>> rotatedShape(shape[0].size(), std::vector<bool>(shape.size()));
    for(size_t row = 0; row < shape.size(); row++){
        for(size_t col = 0; col < shape[0].size() ; col++){
            rotatedShape[col][shape.size() -1 - row] = shape[row][col];
        }
    }
    return rotatedShape;
}