#!/usr/bin/env sh

GCC_OPTS=$1;

echo "Compiling..." \
&& g++ -c src/**/*.cpp -std=c++11 $GCC_OPTS \
&& echo "Linking..." \
&& g++ *.o -o timber.app -lsfml-graphics -lsfml-window -lsfml-system