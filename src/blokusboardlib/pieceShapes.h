#pragma once


#include <vector>
#include <unordered_map>
#include <piece.h>

using Matrix = std::vector<std::vector<bool>>;

enum blokusShapeType {
    iShapeType, // 0 (5)
    bigCornerShapeType, //1 (5)
    crossShapeType, //2 (5)
    snakeShapeType,//3 (5)
    dinoShapeType,//4 (5)
    submarineShapeType,//5 (5)
    zigzagShapeType,//6 (5)
    bigtShapeType,//7 (5)
    uShapeType,//8 (5)
    longlShapeType,//9 (5)
    diggerShapeType,//10 (5)
    sixShapeType,//11 (5)
    zShapeType, //12 (4)
    oShapeType,//13 (4)
    tShapeType, //14 (5)
    mediumlShapeType,//15 (4)
    threeShapeType,//16 (3)
    smallCornerShapeType, // 17 (3)
    twoShapeType,//18 (2)
    singleShapeType, // 19 (1)
    passShapeType
};

extern const char* blokusShapeTypeNames[];

extern Matrix iShape;
extern BlokusPiece iPiece;

extern Matrix smallCornerShape;
extern BlokusPiece smallCornerPiece;

extern Matrix bigCornerShape;
extern BlokusPiece bigCornerPiece;

extern Matrix singleShape;
extern BlokusPiece singlePiece;

extern Matrix crossShape;
extern BlokusPiece crossPiece;

extern Matrix tShape;
extern BlokusPiece tPiece;

extern Matrix zShape;
extern BlokusPiece izPiece;

extern Matrix oShape;
extern BlokusPiece oPiece;

extern Matrix snakeShape;
extern BlokusPiece snakePiece;

extern Matrix dinoShape;
extern BlokusPiece dinoPiece;

extern Matrix submarineShape;
extern BlokusPiece submarinePiece;

extern Matrix zigzagShape;
extern BlokusPiece zigzagPiece;

extern Matrix bigtShape;
extern BlokusPiece bigtPiece;

extern Matrix uShape;
extern BlokusPiece uPiece;

extern Matrix longlShape;
extern BlokusPiece longlPiece;

extern Matrix diggerShape;
extern BlokusPiece diggerPiece;

extern Matrix sixShape;
extern BlokusPiece sixPiece;

extern Matrix mediumlShape;
extern BlokusPiece mediumlPiece;

extern Matrix threeShape;
extern BlokusPiece threePiece;

extern Matrix twoShape;
extern BlokusPiece twoPiece;

extern Matrix passShape;
extern BlokusPiece passPiece;


extern std::unordered_map<blokusShapeType, BlokusPiece> piecesMap;

void initializePieceMap();

void generateRotationsCached(std::unordered_map<blokusShapeType, BlokusPiece>& piecesMap);

struct Block {
    char name;
    int width;
    int height;
    std::vector<std::vector<std::pair<int, int>>> coords;

    Block(char name, int width, int height, const std::vector<std::vector<std::pair<int, int>>> & coords)
        : name(name), width(width), height(height), coords(coords) {}
};

extern const Block rotatedPieces[21];