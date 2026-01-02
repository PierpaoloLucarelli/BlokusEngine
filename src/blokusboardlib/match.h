#pragma once

#include <memory>
#include <unordered_set>
#include <array>
#include <board.h>
#include <pieceShapes.h>
#include <cstdint>


using BlokusMove = std::tuple<int, int, int, uint8_t>;

class BlokusMatch{
    private:
        BlokusBoard board;
        std::vector<std::unordered_set<int>> playerPieces;
        bool playersPlayed[4];
        bool playersPassed[4];
        int moveNum;
        int nPlayers;
        uint8_t turnTracker;
        bool gameOver;

    public:
        BlokusMatch(int nPlayers);
        BlokusMatch(const BlokusMatch& otherMatch);
        BlokusMatch copy() const;



        void newGame();
        bool playMove(int piece_id, int row, int col, uint8_t rotation, uint8_t turn);
        bool play_move_(BlokusMove& move, uint8_t turn);
        std::vector<std::string> playMoveExternal(int piece_id, int row, int col, uint8_t rotation, uint8_t turn);
        bool applyMove(int piece_id, int row, int col, uint8_t rotation, uint8_t turn);
        void removeMove(int piece_id, int row, int col, uint8_t rotation, uint8_t turn);
        bool canPlayMove(int piece_id, int row, int col, uint8_t rotation, uint8_t turn);
        const BlokusBoard& getBoard() const;
        std::vector<uint8_t> getState();
        std::unordered_set<int>& getPiecesForPlayer(uint8_t turn);
        std::vector<std::vector<bool>> getPlayerPieces();
        std::vector<BlokusMove> getMovesFromPos(uint8_t turn);
        bool hasMoves(uint8_t turn);
        void printGame();
        std::vector<std::tuple<int, int>> getCornersFromPos(uint8_t turn);
        std::tuple<int, int> getOffsetForCorner(std::tuple<int,int> boardCorner, std::pair<int,int> pieceCorner);
        const Block& getPiece(int piece_id);
        void setPlayerPieces(std::unordered_set<int> pieces, uint8_t turn);
        uint8_t getTurn();
        std::array<bool, 4> getFirstTurns();
        std::array<bool, 4> getPlayersPassed();
        int8_t getNextTurn();
        bool getGameOver();
        int evaluatePlayerBlocks(uint8_t turn);
        std::array<int, 4> getFinalRanking();
        std::array<int, 4> getPlayerScores();

};
