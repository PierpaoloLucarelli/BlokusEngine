#!/bin/bash

if [ "$1" == "main" ]; then
    g++ -Wall  -Wextra -I ./include ./src/board.cpp ./src/main.cpp ./src/match.cpp ./src/minimax.cpp ./src/piece.cpp ./src/pieceShapes.cpp ./src/gui.cpp -o blokus -lncurses

elif [ "$1" == "debug" ]; then
    g++ -g -p -Wall -DUSE_NCURSES -Wextra -I ./include ./src/*.cpp -o blokus -lncurses

elif [ "$1" == "test" ]; then
    files=$(ls ./src/*.cpp | grep -v main.cpp)
    g++ -Wall  -Wextra -I ./include ./test/test.cpp $files -o testblokus

elif [ "$1" == "pieces" ]; then
    g++ -Wall  -Wextra -I ./include ./src/makePieces.cpp ./src/pieceShapes.cpp ./src/piece.cpp -o makePieces
else
    echo "Usage: $0 {main|test|debug|pieces}"
    exit 1
fi