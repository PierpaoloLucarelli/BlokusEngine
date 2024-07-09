#pragma once

#include <memory>
#include "piece.h"
#include "pieceShapes.h"

class PieceFactory{

    public:
        std::unique_ptr<BlokusPiece> getPiece(blokusShapeType shape){
            switch(shape){
                case blokusShapeType::iShapeType:
                    return std::make_unique<BlokusPiece>(iShape, false);
                case blokusShapeType::smallCornerShapeType:
                    return std::make_unique<BlokusPiece>(smallCornerShape, false);
                case blokusShapeType::BigCornerShapeType:
                    return std::make_unique<BlokusPiece>(BigCornerShape, false);
                case blokusShapeType::singleShapeType:
                    return std::make_unique<BlokusPiece>(singleShape, false);
                case blokusShapeType::crossShapeType:
                    return std::make_unique<BlokusPiece>(crossShape, false);
                case blokusShapeType::tShapeType:
                    return std::make_unique<BlokusPiece>(tShape, false);
                case blokusShapeType::zShapeType:
                    return std::make_unique<BlokusPiece>(zShape, false);
                case blokusShapeType::oShapeType:
                    return std::make_unique<BlokusPiece>(oShape, false);
                default:
                    return nullptr;
            }
        }

};