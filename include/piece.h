#pragma once
#include <vector>
#include <string>
#include <functional> 


using Matrix = std::vector<std::vector<bool>>;

class BlokusPiece{
    private:
        std::vector<Matrix> shape;
        bool symmetric;
        int size;
        std::string id;

    public:

        BlokusPiece(std::vector<Matrix> myShape, bool isSymmetric, std::string id, int pieceSize);

        BlokusPiece(const BlokusPiece& otherPiece);

        void printPiece();
        int getWidth();
        int getHeight();
        bool getXY(int x, int y);
        int getSize();
        bool isSymmetric();
        std::string getId() const;

        
        struct HashFunction{
            size_t operator()(const BlokusPiece& piece) const {
                return std::hash<std::string>()(piece.getId());
            }
        };
};