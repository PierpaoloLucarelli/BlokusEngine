#pragma once
#include <vector>
#include <match.h>
#include <pieceShapes.h>

// using BlokusMove = std::tuple<blokusShapeType, int, int>;

int minimax(BlokusMatch& match, int depth, bool maximising); 
BlokusMove getNextMove(BlokusMatch& match, int maxDepth);