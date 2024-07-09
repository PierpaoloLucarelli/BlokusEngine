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
        std::string id;

    public:

        BlokusPiece(std::vector<std::vector<bool>>& myShape, bool isSymmetric, std::string id);
        void printPiece();
        int getWidth();
        int getHeight();
        bool getXY(int x, int y);
        bool isSymmetric();
        std::string getId() const;
        bool operator==(const BlokusPiece& other) const;
        
        struct HashFunction{
            size_t operator()(const BlokusPiece& piece) const {
                return std::hash<std::string>()(piece.getId());
            }
        };
};