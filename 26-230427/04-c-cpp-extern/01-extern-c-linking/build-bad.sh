#!/bin/bash
gcc a.c b.cpp  # gcc does not link with C++ standard library
g++ a.c b.cpp  # g++ considers all files to be C++ regardless of extension
