#pragma once
#include <vector>


class BlokusPiece{
    private:
        std::vector<std::vector<bool>> shape;
        int width;
        int height;

    public:

        BlokusPiece(std::vector<std::vector<bool>>& myShape);
        void printPiece();
        int getWidth();
        int getHeight();
        bool getXY(int x, int y);
};