#pragma once
#include <vector>




class BlokusPiece{
    private:
        std::vector<std::vector<bool>> shape;
        int width;
        int height;
        bool symmetric;

    public:

        BlokusPiece(std::vector<std::vector<bool>>& myShape, bool isSymmetric);
        void printPiece();
        int getWidth();
        int getHeight();
        bool getXY(int x, int y);
        bool isSymmetric();
};