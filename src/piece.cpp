#include <iostream>
#include <piece.h>

BlokusPiece::BlokusPiece(
        std::vector<std::vector<bool>> myShape, 
        bool isSymmetric,
        std::string myId,
        int pieceSize,
        std::vector<std::tuple<int, int>> pieceCorners
    ) : shape(myShape), cornerBlocks(pieceCorners){
    
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
    // std::cout<<strRepr;
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

std::vector<std::tuple<int, int>> BlokusPiece::getCornerBlocks(uint8_t rotation){
    if(rotation == 0){
        return cornerBlocks;
    }

    std::vector<std::tuple<int, int>> rotatedCorners;
    for(auto corner : cornerBlocks){
        rotatedCorners.push_back(std::make_tuple(std::get<1>(corner), shape.size() - 1 - std::get<0>(corner)));
    }
    return cornerBlocks;
}

std::vector<std::vector<bool>> rotateShape(std::vector<std::vector<bool>>& shapeToRot){
    std::vector<std::vector<bool>> rotatedShape(shapeToRot[0].size(), std::vector<bool>(shapeToRot.size()));
    for(size_t row = 0; row < shapeToRot.size(); row++){
        for(size_t col = 0; col < shapeToRot[0].size() ; col++){
            rotatedShape[col][shapeToRot.size() -1 - row] = shapeToRot[row][col];
        }
    }
    return rotatedShape;
}

std::vector<std::vector<bool>> BlokusPiece::rotate(uint8_t rotation){

    if(rotation == 0){
        return shape;
    }
    std::vector<std::vector<bool>> rotatedShape(shape.size(), std::vector<bool>(shape[0].size()));

    for(size_t row = 0 ; row < shape.size() ; row++){
        for(size_t col = 0 ; col < shape[0].size() ; col++){
            rotatedShape[row][col] = shape[row][col];
        }
    }

    for(int i = 0 ; i < rotation ; i++){
        rotatedShape = rotateShape(rotatedShape);
    }

    // std::vector<std::vector<bool>> rotatedShape(shape[0].size(), std::vector<bool>(shape.size()));
    // for(size_t row = 0; row < shape.size(); row++){
    //     for(size_t col = 0; col < shape[0].size() ; col++){
    //         rotatedShape[col][shape.size() -1 - row] = shape[row][col];
    //     }
    // }
    return rotatedShape;
}
