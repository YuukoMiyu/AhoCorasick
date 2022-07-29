CC = gcc
CFLAGS = -march=native -Wall -O2
DBFlAGS = -g -F dwarf
SRC = $(wildcard *.c)
EXE = run

.PHONY: clean

all:
	@$(CC) $(CFLAGS) $(SRC) -o $(EXE) 

debug:
	@$(CC) $(CFLAGS) $(DBFlAGS) $(SRC) -o $(EXE) 

start:
	@./$(EXE)

clean:
	@rm -f $(EXE)
