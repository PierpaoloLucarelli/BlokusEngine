#pragma once


#include <vector>
#include <unordered_map>
#include <piece.h>

using Matrix = std::vector<std::vector<bool>>;

enum blokusShapeType {
    iShapeType, 
    smallCornerShapeType,
    bigCornerShapeType,
    singleShapeType,
    crossShapeType,
    tShapeType,
    zShapeType,
    oShapeType,
    snakeShapeType,
    dinoShapeType,
    submarineShapeType,
    zigzagShapeType,
    bigtShapeType
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

extern std::unordered_map<blokusShapeType, BlokusPiece> piecesMap;

void initializePieceMap();

