#include <iostream>
#include <match.h>
#include <pieceShapes.h>
#include <algorithm>

std::string PASSED = "TEST PASSED";
std::string FAILED = "TEST FAILED";

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

bool _canPlacePiece(int pieceId, int placeRow, int placeCol, int rotation, int turn){
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

bool testCanPlaceAllPieces(){
    int placeRow = 10;
    int placeCol = 10;
    int turn = 0;
    int rotation = 0;
    for(int pieceId = 0 ; pieceId < 21 ; pieceId++){
        if(!_canPlacePiece(pieceId, placeRow, placeCol, rotation, turn)){
            std::cout << pieceId << std::endl;
            return false;
        }
    }
    return true;
}



int main(){
    std::cout << "Running tests." << std::endl;
    runTest(testCanPlaceAllPieces, "TEST: Place all pieces with no rule checks.");
    return 0;

}