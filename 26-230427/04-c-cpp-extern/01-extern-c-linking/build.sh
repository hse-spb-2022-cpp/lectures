#!/bin/bash
gcc a.c -c        # gcc or `-x c`, otherwise will assume c++ regardless of extension
gcc b.cpp -c      # gcc or g++ both work(?)
g++ a.o b.o -o a  # g++! Should include C++ standard library: https://stackoverflow.com/a/172592/767632
#gcc a.o b.o -lstdc++ -o a
