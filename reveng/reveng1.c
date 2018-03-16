#include <stdio.h>
#include <string.h>

#include "reveng.h"

static unsigned char FLAG[FLAGLEN] = "R&eoJf1!EFr%@\"B";

int main(int argc, char **argv) {
	if (argc != 2 || (strlen(argv[1]) == 0)) {
		printf("Reverse Engineering flag 1\n");
		printf("Usage: %s mask(string)\n", argv[0]);
		return(1);
	}
	unsigned char guess[16];
	memset(guess, 0, 16);
	strncpy(guess, argv[1], 15);
	while (strlen(guess) < 15) {
		guess[strlen(guess)] = guess[0];
	}
	// generate the flag
	genFlag1(guess);

	if (strncmp(guess, FLAG, 16)) {
		printf("Guess of 'flag{%s}' was incorrect\n", argv[1]);
	} else {
		printf("Congratulations, 'flag{%s}' is the correct flag\n", argv[1]);
	}
}