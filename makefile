# Emanuel Hernandez
# Smash Part 2 Project
# March 23, 2018

CC = gcc
CFLAGS = -Wall -g
OBJ = obj
SRC = src
BIN = bin

all: $(BIN)/smash

$(BIN)/smash: $(OBJ)/smash.o $(OBJ)/history.o
	-mkdir -p $(BIN)
	$(CC) $(CFLAGS) -o $(BIN)/smash $^ -I$(SRC) 

$(OBJ)/%.o: $(SRC)/%.c
	-mkdir -p $(OBJ)
	$(CC) -MMD $(CFLAGS) -c -o $@ $< -I$(SRC) 

-include *.d

.PHONY: clean

clean:
	rm -f $(BIN)/* $(OBJ)/*

