#pragma once


#include <vector>
#include <unordered_map>
#include <piece.h>

using Matrix = std::vector<std::vector<bool>>;

enum blokusShapeType {
    iShapeType, // 0
    smallCornerShapeType, // 1
    bigCornerShapeType, //2
    singleShapeType, // 3
    crossShapeType, //4
    tShapeType, //5
    zShapeType, //6
    oShapeType,//7
    snakeShapeType,//8
    dinoShapeType,//9
    submarineShapeType,//10
    zigzagShapeType,//11
    bigtShapeType,//12
    uShapeType,//13
    longlShapeType,//14
    diggerShapeType,//15
    sixShapeType,//16
    mediumlShapeType,//17
    threeShapeType,//18
    twoShapeType//19
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


extern std::unordered_map<blokusShapeType, BlokusPiece> piecesMap;

void initializePieceMap();

