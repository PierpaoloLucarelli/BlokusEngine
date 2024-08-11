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
std::vector<std::tuple<int, int>> iCornerBlocks = {
    std::tuple<int, int>(0,0),
    std::tuple<int, int>(0,4)
};
BlokusPiece iPiece = BlokusPiece(iShape, false, "iPiece", 5, iCornerBlocks);

Matrix bigCornerShape = { //2
    {1,0,0},
    {1,0,0},
    {1,1,1}
};

std::vector<std::tuple<int, int>> bigCornerCornerBlocks = {
    std::tuple<int, int>(0,0),
    std::tuple<int, int>(0,2),
    std::tuple<int, int>(2,2)
};

BlokusPiece bigCornerPiece = BlokusPiece(bigCornerShape, false, "bigCornerPiece", 5, bigCornerCornerBlocks);

Matrix crossShape = { //4
    {0,1,0},
    {1,1,1},
    {0,1,0}
};
std::vector<std::tuple<int, int>> crossCornerBlocks = {
    std::tuple<int, int>(0,1),
    std::tuple<int, int>(1,0),
    std::tuple<int, int>(1,2),
    std::tuple<int, int>(2,1),
};
BlokusPiece crossPiece = BlokusPiece(crossShape, false, "crossPiece", 5, crossCornerBlocks);

// Matrix snakeShape = {
//     {1,1,0},
//     {0,1,0},
//     {0,1,1}
// };
// BlokusPiece snakePiece = BlokusPiece(snakeShape, false, "snakePiece", 5);

// Matrix dinoShape = { // 9
//     {1,1,0},
//     {0,1,1},
//     {0,1,0}
// };
// BlokusPiece dinoPiece = BlokusPiece(dinoShape, false, "dinoPiece", 5);

// Matrix submarineShape = { //10
//     {1,0},
//     {1,1},
//     {1,0},
//     {1,0}
// };
// BlokusPiece submarinePiece = BlokusPiece(submarineShape, false, "submarinePiece", 5);

// Matrix zigzagShape = { // 11
//     {1,0,0},
//     {1,1,0},
//     {0,1,1}
// };
// BlokusPiece zigzagPiece = BlokusPiece(zigzagShape, false, "zigzagPiece", 5);

// Matrix bigtShape = { //12
//     {1,1,1},
//     {0,1,0},
//     {0,1,0}
// };
// BlokusPiece bigtPiece = BlokusPiece(bigtShape, false, "bigtPiece", 5);


// Matrix uShape = { // 13
//     {1,0,1},
//     {1,1,1}
// };
// BlokusPiece uPiece = BlokusPiece(uShape, false, "uPiece", 5);


// Matrix longlShape = { // 14
//     {1,0},
//     {1,0},
//     {1,0},
//     {1,1}
// };
// BlokusPiece longlPiece = BlokusPiece(longlShape, false, "longlPiece", 5);


// Matrix diggerShape = { //15
//     {0,1},
//     {0,1},
//     {1,1},
//     {1,0}
// };
// BlokusPiece diggerPiece = BlokusPiece(diggerShape, false, "diggerPiece", 5);

// Matrix sixShape = { // 16
//     {0,1},
//     {1,1},
//     {1,1}
// };
// BlokusPiece sixPiece = BlokusPiece(sixShape, false, "sixPiece", 5);


// Matrix tShape = { //5
//     {0,1,0},
//     {1,1,1}
// };
// BlokusPiece tPiece = BlokusPiece(tShape, false, "tPiece", 4);

// Matrix zShape = { // 6
//     {1,1,0},
//     {0,1,1}
// };
// BlokusPiece zPiece = BlokusPiece(zShape, false, "zPiece", 4);

// Matrix oShape = { // 7
//     {1,1},
//     {1,1}
// };
// BlokusPiece oPiece = BlokusPiece(oShape, false, "oPiece", 4);

// Matrix mediumlShape = { // 17
//     {1,0},
//     {1,0},
//     {1,1}
// };
// BlokusPiece mediumlPiece = BlokusPiece(mediumlShape, false, "mediumlPiece", 4);


// Matrix smallCornerShape = { // 1
//     {1,0},
//     {1,1}
// };
// BlokusPiece smallCornerPiece = BlokusPiece(smallCornerShape, false, "smallCornerPiece", 3);

// Matrix threeShape = { // 18
//     {1,1,1}
// };
// BlokusPiece threePiece = BlokusPiece(threeShape, false, "threePiece", 3);

// Matrix twoShape = {
//     {1,1}
// };
// BlokusPiece twoPiece = BlokusPiece(twoShape, false, "twoPiece", 2);

// Matrix singleShape = {
//     {1}
// };
// BlokusPiece singlePiece = BlokusPiece(singleShape, false, "singlePiece", 1);

// Matrix passShape = {
// {1}
// };
// BlokusPiece passPiece = BlokusPiece(passShape, false, "passPiece", 1);


std::unordered_map<blokusShapeType, BlokusPiece> piecesMap; 

void initializePieceMap() {
    piecesMap.insert(std::make_pair(blokusShapeType::iShapeType, iPiece));
    piecesMap.insert(std::make_pair(blokusShapeType::crossShapeType, crossPiece));
    piecesMap.insert(std::make_pair(blokusShapeType::bigCornerShapeType,  bigCornerPiece));
//     piecesMap.insert(std::make_pair(blokusShapeType::smallCornerShapeType, smallCornerPiece));
//     piecesMap.insert(std::make_pair(blokusShapeType::singleShapeType, singlePiece));
//     piecesMap.insert(std::make_pair(blokusShapeType::tShapeType, tPiece));
//     piecesMap.insert(std::make_pair(blokusShapeType::zShapeType, zPiece));
//     piecesMap.insert(std::make_pair(blokusShapeType::oShapeType, oPiece));
//     piecesMap.insert(std::make_pair(blokusShapeType::snakeShapeType, snakePiece));
//     piecesMap.insert(std::make_pair(blokusShapeType::dinoShapeType, dinoPiece));
//     piecesMap.insert(std::make_pair(blokusShapeType::submarineShapeType, submarinePiece));
//     piecesMap.insert(std::make_pair(blokusShapeType::zigzagShapeType, zigzagPiece));
//     piecesMap.insert(std::make_pair(blokusShapeType::bigtShapeType, bigtPiece));
//     piecesMap.insert(std::make_pair(blokusShapeType::uShapeType, uPiece));
//     piecesMap.insert(std::make_pair(blokusShapeType::longlShapeType, longlPiece));
//     piecesMap.insert(std::make_pair(blokusShapeType::diggerShapeType, diggerPiece));
//     piecesMap.insert(std::make_pair(blokusShapeType::mediumlShapeType, mediumlPiece));
//     piecesMap.insert(std::make_pair(blokusShapeType::threeShapeType, threePiece));
//     piecesMap.insert(std::make_pair(blokusShapeType::twoShapeType, twoPiece));
//     piecesMap.insert(std::make_pair(blokusShapeType::sixShapeType, sixPiece));
//     piecesMap.insert(std::make_pair(blokusShapeType::passShapeType, passPiece));
}