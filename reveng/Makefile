CC = gcc
SRC := reveng0.c reveng1.c
GEN = flaggen.c
BIN = inc
.PHONY: clean

all: 
	@echo "Invalid use of make, please use one of the given options"

build-challenges: 
	$(CC) reveng0.c $(GEN) -o reveng0 -O0 -static
	$(CC) reveng1.c $(GEN) -o reveng1 -O1 -static
	$(CC) reveng2.c $(GEN) -o reveng2 -O2 -static
	$(CC) reveng3.c $(GEN) -o reveng3 -O3 -static

build-admin:
	$(CC) admin.c $(GEN) -o reveng-admin

clean:
	#$(eval rm-ignore = $(foreach file, $(SRC),-not -name $(file)))
	#@find . -type f $(rm-ignore) -not -name Makefile -delete