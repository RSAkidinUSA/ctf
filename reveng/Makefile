CC = gcc
SRC := reveng0.c reveng1.c
GEN = flaggen.c
BIN = inc
FLAGS := -std=c99 -static
.PHONY: clean

all: 
	@echo "Invalid use of make, please use one of the given options"

build-challenges: 
	$(CC) reveng0.c $(GEN) -o reveng0 -O0 $(FLAGS)
	$(CC) reveng1.c $(GEN) -o reveng1 -O1 $(FLAGS)
	$(CC) reveng2.c $(GEN) -o reveng2 -O2 $(FLAGS)
	$(CC) reveng3.c $(GEN) -o reveng3 -O3 $(FLAGS)

build-admin:
	$(CC) admin.c $(GEN) -o reveng-admin $(FLAGS)

clean:
	#$(eval rm-ignore = $(foreach file, $(SRC),-not -name $(file)))
	#@find . -type f $(rm-ignore) -not -name Makefile -delete