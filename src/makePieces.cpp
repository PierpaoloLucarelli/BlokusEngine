#include <iostream>
#include <pieceShapes.h>

int main(){

    initializePieceMap();
    generateRotationsCached(piecesMap);

    return 0;
}