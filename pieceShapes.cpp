#include <pieceShapes.h>
#include <utility>

Matrix iShape = {
    {1,1,1,1,1}
};
BlokusPiece iPiece = BlokusPiece(iShape, false, "iPiece");

Matrix smallCornerShape = {
    {1,0},
    {1,1}
};
BlokusPiece smallCornerPiece = BlokusPiece(smallCornerShape, false, "smallCornerPiece");

Matrix bigCornerShape = {
    {1,0,0},
    {1,0,0},
    {1,1,1}
};
BlokusPiece bigCornerPiece = BlokusPiece(bigCornerShape, false, "bigCornerPiece");

Matrix singleShape = {
    {1}
};
BlokusPiece singlePiece = BlokusPiece(singleShape, false, "singlePiece");

Matrix crossShape = {
    {0,1,0},
    {1,1,1},
    {0,1,0}
};
BlokusPiece crossPiece = BlokusPiece(crossShape, false, "crossPiece");

Matrix tShape = {
    {0,1,0},
    {1,1,1}
};
BlokusPiece tPiece = BlokusPiece(tShape, false, "tPiece");

Matrix zShape = {
    {1,1,0},
    {0,1,1}
};
BlokusPiece zPiece = BlokusPiece(zShape, false, "zPiece");

Matrix oShape = {
    {1,1},
    {1,1}
};
BlokusPiece oPiece = BlokusPiece(oShape, false, "oPiece");

std::unordered_map<blokusShapeType, BlokusPiece> piecesMap; 
void initializePieceMap() {
    piecesMap.insert(std::make_pair(blokusShapeType::iShapeType, iPiece));
    piecesMap.insert(std::make_pair(blokusShapeType::smallCornerShapeType, smallCornerPiece));
    piecesMap.insert(std::make_pair(blokusShapeType::bigCornerShapeType,  bigCornerPiece));
    piecesMap.insert(std::make_pair(blokusShapeType::singleShapeType, singlePiece));
    piecesMap.insert(std::make_pair(blokusShapeType::crossShapeType, crossPiece));
    piecesMap.insert(std::make_pair(blokusShapeType::tShapeType, tPiece));
    piecesMap.insert(std::make_pair(blokusShapeType::zShapeType, zPiece));
    piecesMap.insert(std::make_pair(blokusShapeType::oShapeType, oPiece));
}