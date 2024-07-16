#include <pieceShapes.h>
#include <utility>
#include <bitset>

const char* blokusShapeTypeNames[] = {
    "iShapeType", 
    "bigCornerShapeType",
    "crossShapeType",
    "tShapeType",
    "zShapeType",
    "oShapeType"
    "smallCornerShapeType",
    "singleShapeType",
    "snakeShapeType",
    "dinoShapeType",
    "submarineShapeType",
    "zigzagShapeType",
    "bigtShapeType"
};

Matrix iShape = {
    {1,1,1,1,1}
};
BlokusPiece iPiece = BlokusPiece(iShape, false, "iPiece", 5);

Matrix bigCornerShape = { //2
    {1,0,0},
    {1,0,0},
    {1,1,1}
};

BlokusPiece bigCornerPiece = BlokusPiece(bigCornerShape, false, "bigCornerPiece", 5);

Matrix crossShape = { //4
    {0,1,0},
    {1,1,1},
    {0,1,0}
};
BlokusPiece crossPiece = BlokusPiece(crossShape, false, "crossPiece", 5);

Matrix snakeShape = {
    {1,1,0},
    {0,1,0},
    {0,1,1}
};
BlokusPiece snakePiece = BlokusPiece(snakeShape, false, "snakePiece", 5);

Matrix dinoShape = { // 9
    {1,1,0},
    {0,1,1},
    {0,1,0}
};
BlokusPiece dinoPiece = BlokusPiece(dinoShape, false, "dinoPiece", 5);

Matrix submarineShape = { //10
    {1,0},
    {1,1},
    {1,0},
    {1,0}
};
BlokusPiece submarinePiece = BlokusPiece(submarineShape, false, "submarinePiece", 5);

Matrix zigzagShape = { // 11
    {1,0,0},
    {1,1,0},
    {0,1,1}
};
BlokusPiece zigzagPiece = BlokusPiece(zigzagShape, false, "zigzagPiece", 5);

Matrix bigtShape = { //12
    {1,1,1},
    {0,1,0},
    {0,1,0}
};
BlokusPiece bigtPiece = BlokusPiece(bigtShape, false, "bigtPiece", 5);


Matrix uShape = { // 13
    {1,0,1},
    {1,1,1}
};
BlokusPiece uPiece = BlokusPiece(uShape, false, "uPiece", 5);


Matrix longlShape = { // 14
    {1,0},
    {1,0},
    {1,0},
    {1,1}
};
BlokusPiece longlPiece = BlokusPiece(longlShape, false, "longlPiece", 5);


Matrix diggerShape = { //15
    {0,1},
    {0,1},
    {1,1},
    {1,0}
};
BlokusPiece diggerPiece = BlokusPiece(diggerShape, false, "diggerPiece", 5);

Matrix sixShape = { // 16
    {0,1},
    {1,1},
    {1,1}
};
BlokusPiece sixPiece = BlokusPiece(sixShape, false, "sixPiece", 5);


Matrix tShape = { //5
    {0,1,0},
    {1,1,1}
};
BlokusPiece tPiece = BlokusPiece(tShape, false, "tPiece", 4);

Matrix zShape = { // 6
    {1,1,0},
    {0,1,1}
};
BlokusPiece zPiece = BlokusPiece(zShape, false, "zPiece", 4);

Matrix oShape = { // 7
    {1,1},
    {1,1}
};
BlokusPiece oPiece = BlokusPiece(oShape, false, "oPiece", 4);

Matrix mediumlShape = { // 17
    {1,0},
    {1,0},
    {1,1}
};
BlokusPiece mediumlPiece = BlokusPiece(mediumlShape, false, "mediumlPiece", 4);


Matrix smallCornerShape = { // 1
    {1,0},
    {1,1}
};
BlokusPiece smallCornerPiece = BlokusPiece(smallCornerShape, false, "smallCornerPiece", 3);

Matrix threeShape = { // 18
    {1,1,1}
};
BlokusPiece threePiece = BlokusPiece(threeShape, false, "threePiece", 3);

Matrix twoShape = {
    {1,1}
};
BlokusPiece twoPiece = BlokusPiece(twoShape, false, "twoPiece", 2);

Matrix singleShape = {
    {1}
};
BlokusPiece singlePiece = BlokusPiece(singleShape, false, "singlePiece", 1);


std::unordered_map<blokusShapeType, std::vector<BlokusPiece>> piecesMap; 

std::vector<BlokusPiece> getRotations(BlokusPiece p){
    std::vector<BlokusPiece> rotations;
    for(int i = 0 ; i < 4 ; i++){
        rotations.push_back(p);
    }
    return rotations;
}

void initializePieceMap() {
    piecesMap.insert(std::make_pair(blokusShapeType::iShapeType, getRotations(iPiece)));
    piecesMap.insert(std::make_pair(blokusShapeType::smallCornerShapeType, getRotations(smallCornerPiece)));
    piecesMap.insert(std::make_pair(blokusShapeType::bigCornerShapeType,  getRotations(bigCornerPiece)));
    piecesMap.insert(std::make_pair(blokusShapeType::singleShapeType, getRotations(singlePiece)));
    piecesMap.insert(std::make_pair(blokusShapeType::crossShapeType, getRotations(crossPiece)));
    piecesMap.insert(std::make_pair(blokusShapeType::tShapeType, getRotations(tPiece)));
    piecesMap.insert(std::make_pair(blokusShapeType::zShapeType, getRotations(zPiece)));
    piecesMap.insert(std::make_pair(blokusShapeType::oShapeType, getRotations(oPiece)));
    piecesMap.insert(std::make_pair(blokusShapeType::snakeShapeType, getRotations(snakePiece)));
    piecesMap.insert(std::make_pair(blokusShapeType::dinoShapeType, getRotations(dinoPiece)));
    piecesMap.insert(std::make_pair(blokusShapeType::submarineShapeType, getRotations(submarinePiece)));
    piecesMap.insert(std::make_pair(blokusShapeType::zigzagShapeType, getRotations(zigzagPiece)));
    piecesMap.insert(std::make_pair(blokusShapeType::bigtShapeType, getRotations(bigtPiece)));
    piecesMap.insert(std::make_pair(blokusShapeType::uShapeType, getRotations(uPiece)));
    piecesMap.insert(std::make_pair(blokusShapeType::longlShapeType, getRotations(longlPiece)));
    piecesMap.insert(std::make_pair(blokusShapeType::diggerShapeType, getRotations(diggerPiece)));
    piecesMap.insert(std::make_pair(blokusShapeType::mediumlShapeType, getRotations(mediumlPiece)));
    piecesMap.insert(std::make_pair(blokusShapeType::threeShapeType, getRotations(threePiece)));
    piecesMap.insert(std::make_pair(blokusShapeType::twoShapeType, getRotations(twoPiece)));
    piecesMap.insert(std::make_pair(blokusShapeType::sixShapeType, getRotations(sixPiece)));
}




