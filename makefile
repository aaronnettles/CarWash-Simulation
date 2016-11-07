# use g++ on Linux
CC = clang++
FLAGS = -O2
SOURCE = main.cpp
PROG = main

all:
	$(CC) $(FLAGS) $(SOURCE) -o $(PROG)