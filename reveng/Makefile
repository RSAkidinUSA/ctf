CC = gcc
SRC := reveng0.c reveng1.c
GEN = flaggen.c
BIN = inc
.PHONY: clean

all: 
	@echo "Invalid use of make, please use one of the given options"

build-challenges: 
	$(CC) reveng0.c $(GEN) -o reveng0 -O0
	$(CC) reveng1.c $(GEN) -o reveng1 -O1
	$(CC) reveng2.c $(GEN) -o reveng2 -O2

build-admin:
	$(CC) admin.c $(GEN) -o reveng-admin

clean:
	#$(eval rm-ignore = $(foreach file, $(SRC),-not -name $(file)))
	#@find . -type f $(rm-ignore) -not -name Makefile -delete