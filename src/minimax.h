#pragma once
#include <vector>
#include <match.h>
#include <pieceShapes.h>

// using BlokusMove = std::tuple<blokusShapeType, int, int>;

int minimax(BlokusMatch& match, int depth, int alpha, int beta, bool maximising); 
BlokusMove getNextMove(BlokusMatch& match, int maxDepth, bool maximising);
int evaluatePosition(BlokusMatch& match);