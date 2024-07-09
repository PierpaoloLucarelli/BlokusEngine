#pragma once


#include <vector>

using Matrix = std::vector<std::vector<bool>>;

enum blokusShapeType {
    iShapeType, 
    smallCornerShapeType,
    BigCornerShapeType,
    singleShapeType,
    crossShapeType,
    tShapeType,
    zShapeType,
    oShapeType
};

extern Matrix iShape;

extern Matrix smallCornerShape;

extern Matrix BigCornerShape;

extern Matrix singleShape;

extern Matrix crossShape;

extern Matrix tShape;

extern Matrix zShape;

extern Matrix oShape;

