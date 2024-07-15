#!/bin/bash

if [ "$1" == "main" ]; then
    g++ -Wall -lncurses -Wextra -I ./include ./src/*.cpp -o blokus

elif [ "$1" == "debug" ]; then
    g++ -g -Wall -lncurses -Wextra -I ./include ./src/*.cpp -o blokus
elif [ "$1" == "test" ]; then
    files=$(ls ./src/*.cpp | grep -v main.cpp)
    g++ -Wall  -Wextra -I ./include ./test/test.cpp $files -o testblokus
else
    echo "Usage: $0 {main|test|debug}"
    exit 1
fi