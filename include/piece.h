#pragma once
#include <vector>
#include <string>
#include <functional> 




class BlokusPiece{
    private:
        std::vector<std::vector<bool>> shape;
        int width;
        int height;
        bool symmetric;
        int size;
        std::string id;

    public:

        BlokusPiece(std::vector<std::vector<bool>>& myShape, bool isSymmetric, std::string id, int pieceSize);
        void printPiece();
        int getWidth();
        int getHeight();
        bool getXY(int x, int y);
        int getSize();
        bool isSymmetric();
        std::string getId() const;
        bool operator==(const BlokusPiece& other) const;
        void rotate();

        
        struct HashFunction{
            size_t operator()(const BlokusPiece& piece) const {
                return std::hash<std::string>()(piece.getId());
            }
        };
};