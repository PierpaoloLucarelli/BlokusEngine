// #pragma once
// #include <vector>
// #include <string>
// #include <functional>
// #include <cstdint> 

// using Matrix = std::vector<std::vector<bool>>;
// using MatrixCorner = std::vector<std::tuple<int, int>>;


// class BlokusPiece{
//     private:
//         std::vector<Matrix> shape;
//         int width;
//         int height;
//         bool symmetric;
//         int size;
//         std::string id;
//         std::vector<MatrixCorner> cornerBlocks;

//     public:

//         BlokusPiece(std::vector<Matrix> myShape, bool isSymmetric, std::string id, int pieceSize, std::vector<MatrixCorner> pieceCorners);
//         void printPiece();
//         int getWidth();
//         int getHeight();
//         bool getXY(int x, int y);
//         int getSize();
//         bool isSymmetric();
//         std::string getId() const;
//         bool operator==(const BlokusPiece& other) const;
//         std::vector<std::vector<bool>> rotate(uint8_t rotation);
//         std::vector<std::tuple<int, int>> rotateCorners(std::vector<std::tuple<int, int>>& cornersToRot, int pieceWidth);
//         std::vector<std::tuple<int, int>> getCornerBlocks(uint8_t rotation);


//         struct HashFunction{
//             size_t operator()(const BlokusPiece& piece) const {
//                 return std::hash<std::string>()(piece.getId());
//             }
//         };
// };
