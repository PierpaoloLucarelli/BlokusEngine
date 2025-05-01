// #include <iostream>
// #include <piece.h>
// #include <cstdint> 

// BlokusPiece::BlokusPiece(
//         std::vector<Matrix> myShape,
//         bool isSymmetric,
//         std::string myId,
//         int pieceSize,
//         std::vector<MatrixCorner> pieceCorners
//     ) : shape(myShape), cornerBlocks(pieceCorners){

//     width = myShape[0].size();
//     height = myShape.size();
//     id = myId;
//     size = pieceSize;
//     symmetric = isSymmetric;
// }

// void BlokusPiece::printPiece(){
//     std::string strRepr;
//     for(size_t i = 0 ; i < shape[0][0].size() ; i++){
//         for(size_t j = 0 ; j < shape[0].size() ; j++){
//             bool filled = shape[0][i][j];
//             std::string x;
//             if(filled){
//                 x = "[X]";
//             } else {
//                 x = "[ ]";
//             }
//             strRepr += x + " ";
//         }
//         strRepr += "\n";
//     }
//     // std::cout<<strRepr;
// }

// int BlokusPiece::getWidth(){
//     return shape[0][0].size();
// }

// int BlokusPiece::getHeight(){
//     return shape[0].size();
// }

// bool BlokusPiece::getXY(int x, int y){
//     return shape[0][x][y];
// }

// bool BlokusPiece::isSymmetric(){
//     return symmetric;
// }

// bool BlokusPiece::operator==(const BlokusPiece& other) const {
//     return id == other.id;
// }

// std::string BlokusPiece::getId() const{
//     return id;
// }

// int BlokusPiece::getSize(){
//     return size;
// }

// std::vector<std::tuple<int, int>> BlokusPiece::rotateCorners(std::vector<std::tuple<int, int>>& cornersToRot, int pieceWidth){
//     std::vector<std::tuple<int, int>> rotatedCorners;

//     for(auto corner : cornersToRot){
//         rotatedCorners.push_back(std::make_tuple(std::get<1>(corner), pieceWidth - 1 - std::get<0>(corner)));
//     }
//     return rotatedCorners;
// }

// std::vector<std::vector<bool>> rotateShape(std::vector<std::vector<bool>>& shapeToRot){
//     std::vector<std::vector<bool>> rotatedShape(shapeToRot[0].size(), std::vector<bool>(shapeToRot.size()));
//     for(size_t row = 0; row < shapeToRot.size(); row++){
//         for(size_t col = 0; col < shapeToRot[0].size() ; col++){
//             rotatedShape[col][shapeToRot.size() -1 - row] = shapeToRot[row][col];
//         }
//     }
//     return rotatedShape;
// }

// std::vector<std::tuple<int, int>> BlokusPiece::getCornerBlocks(uint8_t rotation){
//     // if(rotation == 0){
//     //     return cornerBlocks;
//     // }

//     // std::vector<std::vector<bool>> rotatedShape(shape.size(), std::vector<bool>(shape[0].size()));

//     // for(size_t row = 0 ; row < shape.size() ; row++){
//     //     for(size_t col = 0 ; col < shape[0].size() ; col++){
//     //         rotatedShape[row][col] = shape[row][col];
//     //     }
//     // }

//     // std::vector<std::tuple<int, int>> rotatedCorners(cornerBlocks.size());

//     // for(size_t i = 0 ; i < cornerBlocks.size() ; i++){
//     //     rotatedCorners[i] = std::make_tuple(std::get<0>(cornerBlocks[i]), std::get<1>(cornerBlocks[i]));
//     // }

//     // for(int i = 0 ; i < rotation ; i++){
//     //     rotatedShape = rotateShape(rotatedShape);
//     //     rotatedCorners = rotateCorners(rotatedCorners, rotatedShape[0].size());
//     // }
//     // return rotatedCorners;
//     return cornerBlocks[rotation];
// }

// std::vector<std::vector<bool>> BlokusPiece::rotate(uint8_t rotation){

//     // if(rotation == 0){
//     //     return shape;
//     // }
//     // std::vector<std::vector<bool>> rotatedShape(shape.size(), std::vector<bool>(shape[0].size()));

//     // for(size_t row = 0 ; row < shape.size() ; row++){
//     //     for(size_t col = 0 ; col < shape[0].size() ; col++){
//     //         rotatedShape[row][col] = shape[row][col];
//     //     }
//     // }

//     // for(int i = 0 ; i < rotation ; i++){
//     //     rotatedShape = rotateShape(rotatedShape);
//     // }

//     // return rotatedShape;
//     return shape[rotation];
// }
