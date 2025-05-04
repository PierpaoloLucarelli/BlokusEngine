#include <iostream>
#include <match.h>
#include <pieceShapes.h>
#include <algorithm>

std::string PASSED = "TEST PASSED ✅";
std::string FAILED = "TEST FAILED ❌";

void runTest(bool (*testFunc)(), std::string name){
    if(testFunc()){
        std::cout << name + ": " + PASSED << std::endl;
    } else{
        std::cout << name + ": " +FAILED << std::endl;
    }
}

int rowColToFlat(int row, int col, int width){
    return (row*width) + col;
}

bool _placePiece(int pieceId, int placeRow, int placeCol, int rotation, int turn){
    BlokusBoard board;
    board.reset();
    const Block& piecePlayed = rotatedPieces[pieceId];
    board.placePiece(piecePlayed, placeRow, placeCol, rotation, turn);
    std::vector<int> occupiedIndeces;
    std::vector<std::pair<int, int>> coords = piecePlayed.coords[rotation];
    for(auto coord : coords){
        occupiedIndeces.push_back(rowColToFlat(placeRow+coord.second, placeCol+coord.first, board.getWidth()));
    }
    for(int i = 0 ; i < board.getWidth() * board.getHeight() ; i++){
        if (std::find(occupiedIndeces.begin(), occupiedIndeces.end(), i) != occupiedIndeces.end()) {
            if(board.getState()[i] != turn){
                return false;
            }
        } else {
            if(board.getState()[i] != EMPTYCELL){
                return false;
            }
        }
    }
    return true;
}

bool _canPlacePiece(int pieceId, int placeRow, int placeCol, int rotation, int turn, bool firstMove){
    BlokusBoard board;
    board.reset();
    const Block& piecePlayed = rotatedPieces[pieceId];
    return board.canPlacePiece(piecePlayed, placeRow, placeCol, rotation, turn, firstMove);
}

bool testPlaceAllPieces(){
    int placeRow = 10;
    int placeCol = 10;
    int turn = 0;
    int rotation = 0;
    for(int pieceId = 0 ; pieceId < 21 ; pieceId++){
        if(!_placePiece(pieceId, placeRow, placeCol, rotation, turn)){
            std::cout << pieceId << std::endl;
            return false;
        }
    }
    return true;
}

bool testFailToPlacePieceNegative(){
    int placeRow = -1;
    int placeCol = -1;
    int turn = 0;
    int rotation = 0;
    for(int pieceId = 0 ; pieceId < 21 ; pieceId++){
        if(_canPlacePiece(pieceId, placeRow, placeCol, rotation, turn, false)){
            std::cout << pieceId << std::endl;
            return false;
        }
    }
    return true;
}

bool testCanPlacePieceInsideOfBoundsOnEdge(){
    return (
        _canPlacePiece(4, 1, 0, 0, 0, true) && // long 4 piece. 
        _canPlacePiece(18, 1, 1, 0, 0, true) && // S shape.
        _canPlacePiece(4, 1, 19, 0, 0, true)  && // long 4 piece. top right corner
        _canPlacePiece(18, 18, 18, 0, 0, true) &&  // S shape. bottom right corner.
        _canPlacePiece(16, 19, 0, 0, 0, true) // L shape bottom left corner.
    );
}

bool testCantPlacePieceOutsideOfBoundsOnEdge(){
    return (
        !_canPlacePiece(4, 0, 0, 0, 0, true) &&  // long 4 piece. OOB on top.
        !_canPlacePiece(18, 1, 0, 0, 0, true) && // S shape. OOB in  the left.
        !_canPlacePiece(4, 0, 19, 0, 0, true) &&  // long 4 piece. OOB top right corner
        !_canPlacePiece(18, 18, 19, 0, 0, true) && // S shape. OOB bottom right corner.
        !_canPlacePiece(15, 19, 0, 0, 0, true) && // T shape. OOB bottom left corner.
        !_canPlacePiece(11, 2, 0, 0, 0, true) // cant OOB on the left.
    );
}

bool testCanPlaceRotatedPieceInsideOfBoundsOnEdge(){
    return (
        _canPlacePiece(17, 18, 1, 1, 0, true) && // S piece. Bottom left corner rotated once. Can
        !_canPlacePiece(17, 18, 1, 0, 0, true) &&// Same piece but not rotated. Cant
        _canPlacePiece(15, 1, 1, 2, 0, true) && // T piece rotated twice in top left corner. Can
        !_canPlacePiece(15, 1, 1, 0, 0, true) && // Same piece but not rotated. Cant
        _canPlacePiece(11, 2, 0, 4, 0, true) && // Can.
        !_canPlacePiece(11, 2, 0, 0, 0, true) // Cant.
    );
}

bool testCanPlayPieceTouchingSelfCorner(){
    BlokusMatch match(4);
    match.newGame();
    bool success = match.playMove(16, 2, 0, 0, 0); // L shape top left corner -> Creates two free corners.
    if(!success){
        return false;
    }

    std::vector<std::tuple<int, int>> corners = match.getCornersFromPos(0);
    if(corners.size() != 2){
        return false;
    }
    return (
        match.canPlayMove(0, 3, 3, 0, 0) && // Single shape on bottom corner. Can
        match.canPlayMove(0, 1, 3, 0, 0) && // Single shape on top corner. Can
        !match.canPlayMove(0, 4, 4, 0, 0) && // Single piece not touching any corner. Cant
        !match.canPlayMove(0, 1, 2, 0, 0) && // Single piece touching corner but also adjacent. Cant 
        !match.canPlayMove(0, 2, 2, 0, 0) // Single piece trying to replace the corner block. Cant.
    );
}

bool testCantPlayTwoMovesInARow(){
    BlokusMatch match(4);
    match.newGame();
    return (
        match.playMove(16, 2, 0, 0, 0) && // L shape top left corner -> Creates two free corners.
        !match.playMove(0, 3, 3, 0, 0) &&// Single shape on bottom corner. Legal move but not ps turn.
        match.playMove(0, 19, 19, 0, 1) && // Single piece on bottom right but for p1.
        !match.playMove(1, 0, 19, 0, 1) // double piece in top right corner. Cant bcs not p1 turn.
    );
}

bool test2PlayerGameAlternatingTurns(){
    BlokusMatch match(2);
    match.newGame();
    return (
        match.playMove(0, 0, 0, 0, 0) && // p0 single in top right. Can
        match.playMove(0, 19, 19, 0, 1) && // p1 single in bottom right corner. Can
        match.playMove(1, 1, 1, 0, 0) && // p0 double touching corner of single. Can
        match.playMove(1, 17, 18, 0, 1) // p1 touching corner of single in bottom right. Can.
    );
}

bool testCantPlaySamePiece(){
    BlokusMatch match(2);
    match.newGame();
    return (
        match.playMove(0, 0, 0, 0, 0) && // p0 single in top right. Can
        match.playMove(0, 19, 19, 0, 1) && // p1 single in bottom right corner. Can
        !match.playMove(0, 1, 1, 0, 0) && // p0 single touching corner of single. Cant
        !match.playMove(0, 18, 18, 0, 1) // p1 single corner of single in bottom right. Can.
    );
}

// bool testGetMovesFromPos(){
//     BlokusMatch match(2);
//     match.newGame();
//     bool success = true;
//     success = success && match.playMove(16, 2, 0, 0, 0); // p0 puts L in corner
//     success = success && match.playMove(16, 2, 0, 0, 0); // p0 puts L in corner
// }

int main(){
    std::cout << "Running tests." << std::endl;
    runTest(testPlaceAllPieces, "TEST: Place all pieces with no rule checks.");
    runTest(testFailToPlacePieceNegative, "TEST: Cant place all pieces negative coords.");
    runTest(testCanPlacePieceInsideOfBoundsOnEdge, "TEST: Can place piece within bounds (on the edge).");
    runTest(testCantPlacePieceOutsideOfBoundsOnEdge, "TEST: Cant place piece outside bounds (on the edge).");
    runTest(testCanPlayPieceTouchingSelfCorner, "TEST: Can place piece first in corner, then touching self corners.");
    runTest(testCantPlayTwoMovesInARow, "TEST: Cannot play two moves in a row.");
    runTest(test2PlayerGameAlternatingTurns, "TEST: Can play alternating in two player game.");
    runTest(testCantPlaySamePiece, "TEST: Cant playsame piece twice even tho its legal move.");
    runTest(testCanPlaceRotatedPieceInsideOfBoundsOnEdge, "TEST: Can place rotated pieces in corner.");
    return 0;
}