#include <iostream>
#include <piece.h>

BlokusPiece::BlokusPiece(std::vector<std::vector<bool>> myShape, bool isSymmetric, std::string myId, int pieceSize) : shape(myShape){
    id = myId;
    size = pieceSize;
    symmetric = isSymmetric;
}

BlokusPiece::BlokusPiece(const BlokusPiece& otherPiece): shape(otherPiece.shape){
    id = otherPiece.id;
    size = otherPiece.size;
    symmetric = otherPiece.symmetric;
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
     std::cout<<"getting"<<std::endl;
            std::cout<<shape.size()<<std::endl;
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

BlokusPiece BlokusPiece::rotate(uint8_t rotation){

    if(rotation > 3){
        throw std::runtime_error("Invalid rotation");
    }

    if(rotation==0){
        return BlokusPiece(shape, symmetric, id, size);
    }

    if(rotation == 1 || rotation == 3){
        std::vector<std::vector<bool>> rotatedShape(shape[0].size(), std::vector<bool>(shape.size()));
    } else{
        std::vector<std::vector<bool>> rotatedShape(shape.size(), std::vector<bool>(shape[0].size()));
    }
    std::vector<std::vector<bool>> rotatedShape;
    for(size_t row = 0; row < shape.size(); row++){
        for(size_t col = 0; col < shape[0].size() ; col++){
            if(rotation==1){
                rotatedShape[col][shape.size() -1 - row] = shape[row][col];
            } else if(rotation==3){
                rotatedShape[shape.size() -1 - col][row] = shape[row][col];
            } else if(rotation==2){
                rotatedShape[col][row] = shape[row][col];
            }
        }
    }
    return BlokusPiece(rotatedShape, symmetric, id, size);
}