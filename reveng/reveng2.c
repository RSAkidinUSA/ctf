#include <stdio.h>
#include <string.h>

#include "flags.h"

unsigned char FLAG2[FLAGLEN];

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
	genFlag2(guess);

	printf("Guess of 'flag{%s}' was incorrect\n", argv[1]);
	if (strncmp(guess, FLAG2, 16)) {
		return 1;
	} else {
		return 0;
	}
}