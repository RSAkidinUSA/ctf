CC = gcc
SRC := reveng0.c reveng1.c
GEN = flaggen.c
BIN = inc
.PHONY: clean

all: 
	@echo "Invalid use of make, please use one of the given options"

build-challenge: 
	$(CC) reveng0.c $(GEN) -o reveng0
	$(CC) reveng1.c $(GEN) -o reveng1
	$(CC) reveng2.c $(GEN) -o reveng2

build-admin:
	$(CC) admin.c $(GEN) -o reveng-admin

clean:
	#$(eval rm-ignore = $(foreach file, $(SRC),-not -name $(file)))
	#@find . -type f $(rm-ignore) -not -name Makefile -delete