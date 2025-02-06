add_library(blokusboardlib STATIC
    board.cpp
    match.cpp
    piece.cpp
    pieceShapes.cpp
)

target_include_directories(blokusboardlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
