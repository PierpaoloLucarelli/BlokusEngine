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

bool testGetMovesFromPos(){
    BlokusMatch match(4);
    match.newGame();
    bool success = true;
    success = success && match.playMove(16, 2, 0, 0, 0); // p0 puts L in corner
    success = success && match.playMove(16, 17, 0, 1, 1); // p1 puts L in corner
    success = success && match.playMove(16, 17, 19, 2, 2); // p3 puts L in bottom right.
    success = success && match.playMove(16, 0, 17, 1, 3); // p4 puts L in top right.
    for(int p = 0 ; p < 4 ; p++){
        std::unordered_set<int> pieces = {0, 1};
        match.setPlayerPieces(pieces, p);
        std::vector<BlokusMove> movesForP = match.getMovesFromPos(p);
        if(movesForP.size() != 2 * 2 * 8) { // two corners and 8 rotations for each piece
            return false;
        }
    }
    return success;
}

bool testGetTurn(){
    BlokusMatch match(4);
    match.newGame();
    if (match.getTurn() != 0){
        return false;
    }
    match.playMove(0, 4, 4, 0, 0); // Single piece not touching any corner. Cant  
    if (match.getTurn() != 0){\
        return false;
    }
    bool success = success && match.playMove(16, 2, 0, 0, 0); // L shape top left corner -> Creates two free corners. Can
    if(match.getTurn() != 1){
        return false;
    }
    success = success && match.playMove(16, 17, 0, 1, 1); // p1 puts L in corner
    if(match.getTurn() != 2){
        return false;
    }
    success = success && match.playMove(16, 17, 19, 2, 2); // p2 puts L in bottom right.
    if(match.getTurn() != 3){
        return false;
    }
    success = success && match.playMove(16, 0, 17, 1, 3); // p3 puts L in top right.
    if(match.getTurn() != 0){
        return false;
    }
    return success;
}

bool testPlayerResigned(){
    BlokusMatch match(4);
    match.newGame();
    bool success = match.playMove(16, 2, 0, 0, 0); // L shape top left corner -> Creates two free corners. Can
    success = success && match.playMove(22, 0, 0, 0, 1); // p1 resigns while its their turn.
    if(match.getTurn() != 2){
        return false;
    }
    success = success && match.playMove(16, 17, 19, 2, 2); // p2 puts L in bottom right.
    if(match.getTurn() != 3){
        return false;
    }
    success = success && match.playMove(22, 0, 0, 0, 0); // p0 resigns while its not their turn.
    if(match.getTurn() != 3){ // still p3s turn
        return false;
    }
    success = success && match.playMove(16, 0, 17, 1, 3); // p3 puts L in top right.
    if(match.getTurn() != 2){ // p0 and p1 have resigned so it should be p2s turn.
        return false;
    }
    success = success && match.playMove(0, 16, 16, 0, 2); // p2 puts Single in available corner.
    std::array<bool, 4> playersPassed = match.getPlayersPassed();
    success && (
        playersPassed[0] &&
        playersPassed[1] &&
       !playersPassed[2] &&
       !playersPassed[3]
    );
    success = success && match.playMove(22, 0, 0, 0, 2); // p2 resigns while its not their turn.
    success = success && match.playMove(22, 0, 0, 0, 3); // p3 resigns while its not their turn.

    if(!match.getGameOver()){
        return false;
    }

    std::array<int, 4> ranks = match.getFinalRanking();

    return success && (
        ranks[2] == 1 && ranks[0] == 2 && ranks[3] == 2 && ranks[1] == 3
    );
}

bool testEvaluatePlayerBlocks(){
    int totalBlocks = 0;
    for(const Block& b : rotatedPieces){
        totalBlocks += b.size;
    }
    BlokusMatch match(4);
    match.newGame();
    int playedPieceId = 16;
    const Block& playerPiece = rotatedPieces[playedPieceId];
    bool success = match.playMove(playedPieceId, 2, 0, 0, 0); // L shape top left corner -> Creates two free corners. Can
    if(match.evaluatePlayerBlocks(0) != totalBlocks - playerPiece.size){
        return false;
    }
    if(match.evaluatePlayerBlocks(1) != totalBlocks){
        return false;
    }
    return success;
}

bool testGamOver(){
    BlokusMatch match(4);
    match.newGame();
    bool success = match.playMove(22, 0, 0, 0, 0); // p0 resigns while its their turn.
    success = success &&  match.playMove(22, 0, 0, 0, 1); // p1 resigns while its their turn.
    if(match.getGameOver()){
        return false;
    }
    success = success &&  match.playMove(22, 0, 0, 0, 2); // p2 resigns while its their turn.
    success = success &&  match.playMove(22, 0, 0, 0, 3); // p3 resigns while its their turn.
    return match.getGameOver();
}

bool testGamOverMinusOnePlayer(){
    BlokusMatch match(4);
    match.newGame();
    bool success = match.playMove(22, 0, 0, 0, 0); // p0 resigns while its their turn.
    success = success &&  match.playMove(22, 0, 0, 0, 1); // p1 resigns while its their turn.
    if(match.getGameOver()){
        return false;
    }
    success = success &&  match.playMove(22, 0, 0, 0, 2); // p2 resigns while its their turn.
    match.playMove(16, 2, 0, 0, 3); // L shape top left corner. Can
    if(match.getTurn() != 3){ // 3s turn again.
        return false;
    }
    success = success && match.playMove(0, 3, 3, 0, 3); // single piece in corner.
    return success && !match.getGameOver() && match.getTurn() == 3;
}

bool testCopyConstructor(){
    BlokusMatch match(4);
    match.newGame();

    BlokusMatch copyMatch = match.copy();
    bool success = match.playMove(22, 0, 0, 0, 0); // p0 resigns while its their turn.

    std::array<bool, 4> playersPassedCopy = copyMatch.getPlayersPassed();
    std::array<bool, 4> playersPassed = match.getPlayersPassed();
    success = success && playersPassedCopy[0] == 0;
    return success && playersPassed[0] == 1;
}

bool testGetPlacedCoords(){
    BlokusMatch match(4);
    match.newGame();
    std::tuple<bool, std::vector<std::string>> res = match.playMoveExternal(0, 0, 0, 0, 0);
    if (!std::get<0>(res)){
      return false;
    }
    const auto& coords = std::get<1>(res);
    return coords.size() == 1 && coords[0] == "a20";;
}

bool testResignExternal(){
    BlokusMatch match(4);
    match.newGame();
    std::tuple<bool, std::vector<std::string>> res = match.playMoveExternal(22, 0, 0, 0, 0);
    if (!std::get<0>(res)){
      return false;
    }
    const auto& coords = std::get<1>(res);
    return coords.size() == 0;
}


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
    runTest(testGetMovesFromPos, "TEST: Check if get moves from pos returns correct.");
    runTest(testGetTurn, "TEST: test if turn is correctly changing.");
    runTest(testPlayerResigned, "TEST: if player resigning works correct on getTurn().");
    runTest(testEvaluatePlayerBlocks, "TEST: if count of player blocks is correct.");
    runTest(testGamOver, "TEST: if all players resign that the game over flag is true.");
    runTest(testGamOverMinusOnePlayer, "TEST: if all players -1 resign, the active player can still play.");
    runTest(testCopyConstructor, "TEST: if modifying the copied keeps the copy unchanged..");
    runTest(testGetPlacedCoords, "TEST: if getPlacedCoords returns the correct coords and correct format.");
    runTest(testResignExternal, "TEST: Check if resigning fails the external move player.");
    return 0;
}
