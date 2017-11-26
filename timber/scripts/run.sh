#!/usr/bin/env sh

echo "Compiling..."
g++ -c src/*.cpp -std=c++11

echo "Linking..."
g++ *.o -o timber.app -lsfml-graphics -lsfml-window -lsfml-system

echo "Starting Timber!!!"
./timber.app