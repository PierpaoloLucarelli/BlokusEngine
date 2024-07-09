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

Matrix iShape = {
    {1,1,1,1,1}
};

Matrix smallCornerShape = {
    {1,0},
    {1,1}
};

Matrix BigCornerShape = {
    {1,0,0},
    {1,0,0},
    {1,1,1}
};

Matrix singleShape = {
    {1}
};

Matrix crossShape = {
    {0,1,0},
    {1,1,1},
    {0,1,0}
};

Matrix tShape = {
    {0,1,0},
    {1,1,1}
};

Matrix zShape = {
    {1,1,0},
    {0,1,1}
};

Matrix oShape = {
    {1,1},
    {1,1}
};

