#include <iostream>
#include <piece.h>

BlokusPiece::BlokusPiece(std::vector<Matrix> myShape, bool isSymmetric, std::string myId, int pieceSize) : shape(myShape){
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
    for(size_t i = 0 ; i < shape[0][0].size() ; i++){
        for(size_t j = 0 ; j < shape[0].size() ; j++){
            bool filled = shape[0][i][j];
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

    return shape[0][0].size();
}

int BlokusPiece::getHeight(){
    return shape[0].size();
}

bool BlokusPiece::getXY(int x, int y){
    return shape[0][x][y];
}

bool BlokusPiece::isSymmetric(){
    return symmetric;
}

// bool BlokusPiece::operator==(const BlokusPiece& other) const {
//     return id == other.id;
// }

std::string BlokusPiece::getId() const{
    return id;
}

int BlokusPiece::getSize(){
    return size;
}
