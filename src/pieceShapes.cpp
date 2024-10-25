#include <pieceShapes.h>
#include <utility>
#include <bitset>
#include <iostream>
#include <fstream> 

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

Matrix snakeShape = {
    {1,1,0},
    {0,1,0},
    {0,1,1}
};
std::vector<std::tuple<int, int>> snakeCornerBlocks = {
    std::tuple<int, int>(0,0),
    std::tuple<int, int>(2,2)
};
BlokusPiece snakePiece = BlokusPiece(snakeShape, false, "snakePiece", 5, snakeCornerBlocks);

Matrix dinoShape = { // 9
    {1,1,0},
    {0,1,1},
    {0,1,0}
};

std::vector<std::tuple<int, int>> dinoCornerBlocks = {
    std::tuple<int, int>(0,0),
    std::tuple<int, int>(1,2),
    std::tuple<int, int>(2,1)
};
BlokusPiece dinoPiece = BlokusPiece(dinoShape, false, "dinoPiece", 5, dinoCornerBlocks);

Matrix submarineShape = { //10
    {1,0},
    {1,1},
    {1,0},
    {1,0}
};
std::vector<std::tuple<int, int>> submarineCornerBlocks = {
    std::tuple<int, int>(0,0),
    std::tuple<int, int>(1,1),
    std::tuple<int, int>(3,0)
};
BlokusPiece submarinePiece = BlokusPiece(submarineShape, false, "submarinePiece", 5, submarineCornerBlocks);

Matrix zigzagShape = { // 11
    {1,0,0},
    {1,1,0},
    {0,1,1}
};
std::vector<std::tuple<int, int>> zigzagCornerBlocks = {
    std::tuple<int, int>(0,0),
    std::tuple<int, int>(1,0),
    std::tuple<int, int>(2,1),
    std::tuple<int, int>(2,2)
};
BlokusPiece zigzagPiece = BlokusPiece(zigzagShape, false, "zigzagPiece", 5, zigzagCornerBlocks);

Matrix bigtShape = { //12
    {1,1,1},
    {0,1,0},
    {0,1,0}
};
std::vector<std::tuple<int, int>> bigtCornerBlocks = {
    std::tuple<int, int>(0,0),
    std::tuple<int, int>(0,2),
    std::tuple<int, int>(2,1)
};
BlokusPiece bigtPiece = BlokusPiece(bigtShape, false, "bigtPiece", 5, bigtCornerBlocks);


Matrix uShape = { // 13
    {1,0,1},
    {1,1,1}
};
std::vector<std::tuple<int, int>> uCornerBlocks = {
    std::tuple<int, int>(0,0),
    std::tuple<int, int>(0,2),
    std::tuple<int, int>(1,0),
    std::tuple<int, int>(1,2)
};

BlokusPiece uPiece = BlokusPiece(uShape, false, "uPiece", 5, uCornerBlocks);


Matrix longlShape = { // 14
    {1,0},
    {1,0},
    {1,0},
    {1,1}
};
std::vector<std::tuple<int, int>> longlCornerBlocks = {
    std::tuple<int, int>(0,0),
    std::tuple<int, int>(3,0),
    std::tuple<int, int>(3,1)
};

BlokusPiece longlPiece = BlokusPiece(longlShape, false, "longlPiece", 5, longlCornerBlocks);


Matrix diggerShape = { //15
    {0,1},
    {0,1},
    {1,1},
    {1,0}
};
std::vector<std::tuple<int, int>> diggerCornerBlocks = {
    std::tuple<int, int>(0,1),
    std::tuple<int, int>(2,0),
    std::tuple<int, int>(2,1),
    std::tuple<int, int>(3,0)
};

BlokusPiece diggerPiece = BlokusPiece(diggerShape, false, "diggerPiece", 5, diggerCornerBlocks);

Matrix sixShape = { // 16
    {0,1},
    {1,1},
    {1,1}
};
std::vector<std::tuple<int, int>> sixCornerBlocks = {
    std::tuple<int, int>(0,1),
    std::tuple<int, int>(1,0),
    std::tuple<int, int>(2,0),
    std::tuple<int, int>(2,1)
};

BlokusPiece sixPiece = BlokusPiece(sixShape, false, "sixPiece", 5, sixCornerBlocks);


Matrix tShape = { //5
    {0,1,0},
    {1,1,1}
};

std::vector<std::tuple<int, int>> tCornerBlocks = {
    std::tuple<int, int>(0,1),
    std::tuple<int, int>(1,0),
    std::tuple<int, int>(1,2),
};
BlokusPiece tPiece = BlokusPiece(tShape, false, "tPiece", 4, tCornerBlocks);

Matrix zShape = { // 6
    {1,1,0},
    {0,1,1}
};
std::vector<std::tuple<int, int>> zCornerBlocks = {
    std::tuple<int, int>(0,1),
    std::tuple<int, int>(0,1),
    std::tuple<int, int>(1,1),
    std::tuple<int, int>(1,2)
};
BlokusPiece zPiece = BlokusPiece(zShape, false, "zPiece", 4, zCornerBlocks);

Matrix oShape = { // 7
    {1,1},
    {1,1}
};
std::vector<std::tuple<int, int>> oCornerBlocks = {
    std::tuple<int, int>(0,0),
    std::tuple<int, int>(0,1),
    std::tuple<int, int>(1,0),
    std::tuple<int, int>(1,1)
};
BlokusPiece oPiece = BlokusPiece(oShape, false, "oPiece", 4, oCornerBlocks);

Matrix mediumlShape = { // 17
    {1,0},
    {1,0},
    {1,1}
};
std::vector<std::tuple<int, int>> mediumlCornerBlocks = {
    std::tuple<int, int>(0,0),
    std::tuple<int, int>(2,0),
    std::tuple<int, int>(2,1)
};
BlokusPiece mediumlPiece = BlokusPiece(mediumlShape, false, "mediumlPiece", 4, mediumlCornerBlocks);


Matrix smallCornerShape = { // 1
    {1,0},
    {1,1}
};
std::vector<std::tuple<int, int>> smallCornerBlocks = {
    std::tuple<int, int>(0,0),
    std::tuple<int, int>(1,0),
    std::tuple<int, int>(1,1)
};
BlokusPiece smallCornerPiece = BlokusPiece(smallCornerShape, false, "smallCornerPiece", 3, smallCornerBlocks);

Matrix threeShape = { // 18
    {1,1,1}
};
std::vector<std::tuple<int, int>> threeCornerBlocks = {
    std::tuple<int, int>(0,0),
    std::tuple<int, int>(0,2)
};
BlokusPiece threePiece = BlokusPiece(threeShape, false, "threePiece", 3, threeCornerBlocks);

Matrix twoShape = {
    {1,1}
};
std::vector<std::tuple<int, int>> twoCornerBlocks = {
    std::tuple<int, int>(0,0),
    std::tuple<int, int>(0,1)
};
BlokusPiece twoPiece = BlokusPiece(twoShape, false, "twoPiece", 2, twoCornerBlocks);

Matrix singleShape = {
    {1}
};
std::vector<std::tuple<int, int>> singleCornerBlocks = {
    std::tuple<int, int>(0,0)
};
BlokusPiece singlePiece = BlokusPiece(singleShape, false, "singlePiece", 1, singleCornerBlocks);

Matrix passShape = {
{1}
};
std::vector<std::tuple<int, int>> passCornerBlocks = {
    std::tuple<int, int>(0,0)
};
BlokusPiece passPiece = BlokusPiece(passShape, false, "passPiece", 1, passCornerBlocks);


std::unordered_map<blokusShapeType, BlokusPiece> piecesMap; 

void initializePieceMap() {
    piecesMap.insert(std::make_pair(blokusShapeType::iShapeType, iPiece));
    piecesMap.insert(std::make_pair(blokusShapeType::crossShapeType, crossPiece));
    piecesMap.insert(std::make_pair(blokusShapeType::bigCornerShapeType,  bigCornerPiece));
    piecesMap.insert(std::make_pair(blokusShapeType::smallCornerShapeType, smallCornerPiece));
    piecesMap.insert(std::make_pair(blokusShapeType::singleShapeType, singlePiece));
    piecesMap.insert(std::make_pair(blokusShapeType::tShapeType, tPiece));
    piecesMap.insert(std::make_pair(blokusShapeType::zShapeType, zPiece));
    piecesMap.insert(std::make_pair(blokusShapeType::oShapeType, oPiece));
    piecesMap.insert(std::make_pair(blokusShapeType::snakeShapeType, snakePiece));
    piecesMap.insert(std::make_pair(blokusShapeType::dinoShapeType, dinoPiece));
    piecesMap.insert(std::make_pair(blokusShapeType::submarineShapeType, submarinePiece));
    piecesMap.insert(std::make_pair(blokusShapeType::zigzagShapeType, zigzagPiece));
    piecesMap.insert(std::make_pair(blokusShapeType::bigtShapeType, bigtPiece));
    piecesMap.insert(std::make_pair(blokusShapeType::uShapeType, uPiece));
    piecesMap.insert(std::make_pair(blokusShapeType::longlShapeType, longlPiece));
    piecesMap.insert(std::make_pair(blokusShapeType::diggerShapeType, diggerPiece));
    piecesMap.insert(std::make_pair(blokusShapeType::mediumlShapeType, mediumlPiece));
    piecesMap.insert(std::make_pair(blokusShapeType::threeShapeType, threePiece));
    piecesMap.insert(std::make_pair(blokusShapeType::twoShapeType, twoPiece));
    piecesMap.insert(std::make_pair(blokusShapeType::sixShapeType, sixPiece));
    piecesMap.insert(std::make_pair(blokusShapeType::passShapeType, passPiece));
}



void generateRotationsCached(std::unordered_map<blokusShapeType, BlokusPiece>& piecesMap){
    std::string fileContent = "#include <vector>\n";
    fileContent += "#include <tuple>\n";
    fileContent += "using Matrix = std::vector<std::vector<bool>>;\n\n";

    for (const auto& pair : piecesMap) {
        BlokusPiece piece = pair.second;


        for(int rot = 0 ; rot < 4 ; rot++){
            fileContent += "std::vector<std::tuple<int, int>> "+piece.getId()+"Corners = {\n";
            std::vector<std::tuple<int, int>> rotatedCorners = piece.getCornerBlocks(rot);
            for(auto pieceCorner : rotatedCorners){
                fileContent += "\tstd::tuple<int, int>(" + std::to_string(std::get<0>(pieceCorner)) + ","+std::to_string(std::get<1>(pieceCorner))+"),\n";
            }
            fileContent += "};\n";
        }

        fileContent += "std::vector<Matrix> " + piece.getId() + + " = {\n\n";
       

        for(int rot = 0 ; rot < 4 ; rot++){
            fileContent += "\t{\n";
            std::vector<std::vector<bool>> rotated = piece.rotate(rot);

            int w = static_cast<int>(rotated[0].size());
            int h = static_cast<int>(rotated.size());
            for(int row = 0 ; row < h ; row++){
                fileContent += "\t\t{";
                for(int col = 0 ; col < w; col++){
                    fileContent +=  std::to_string(rotated[row][col]);
                    if(col != w-1){
                        fileContent += ",";
                    }
                }
                fileContent += "}";

                if(row == h-1){
                    fileContent+="\n";
                } else{
                    fileContent += ",\n";
                }
            }

            if(rot == 3){
                fileContent += "\t}\n";
            } else {
                fileContent += "\t},\n";
            }

        }

        fileContent += "};\n\n";
    }


    std::ofstream outFile("pieces.cpp");

    if (outFile.is_open()) {
        outFile << fileContent;
        outFile.close();
        std::cout << "String successfully written to file." << std::endl;
    } else {
        std::cout << "Error: could not open the file." << std::endl;
    }
}