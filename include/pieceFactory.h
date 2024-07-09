#pragma once

#include <memory>
#include <unordered_set>
#include "pieceShapes.h"

class PieceFactory{

    public:
        std::unique_ptr<BlokusPiece> getPiece(blokusShapeType shape){
            switch(shape){
                case blokusShapeType::iShapeType:
                    return std::make_unique<BlokusPiece>(iShape, false, "iShape");
                case blokusShapeType::smallCornerShapeType:
                    return std::make_unique<BlokusPiece>(smallCornerShape, false, "smallCorner");
                case blokusShapeType::BigCornerShapeType:
                    return std::make_unique<BlokusPiece>(BigCornerShape, false, "BigCorner");
                case blokusShapeType::singleShapeType:
                    return std::make_unique<BlokusPiece>(singleShape, false, "single");
                case blokusShapeType::crossShapeType:
                    return std::make_unique<BlokusPiece>(crossShape, false, "cross");
                case blokusShapeType::tShapeType:
                    return std::make_unique<BlokusPiece>(tShape, false, "t");
                case blokusShapeType::zShapeType:
                    return std::make_unique<BlokusPiece>(zShape, false,"z");
                case blokusShapeType::oShapeType:
                    return std::make_unique<BlokusPiece>(oShape, false, "o");
                default:
                    return nullptr;
            }
        }

        void fillPieceSet(std::unordered_set<BlokusPiece, BlokusPiece::HashFunction>& pieceSet){
            for(int piece = blokusShapeType::iShapeType ; piece != blokusShapeType::oShapeType; piece++){
                    auto p = getPiece(static_cast<blokusShapeType>(piece));
                    pieceSet.insert(*p);
            } 
        }

};