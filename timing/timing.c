#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#define FLAGLEN 16
#define PASSLEN 16

static unsigned char FLAG[FLAGLEN] = "t1m1nGfjau39aFD";
static unsigned char PASS[PASSLEN] = "PASSWORD1234567";

#define RANGEMIN 40
#define RANGEMAX 126

void genPass(void) {
	int seed = time(NULL);
	srand(seed);
	int max = rand() % 500;
	for (int i = 0; i < max; i++) {
		int spot = rand() % PASSLEN;
		do {
			uint8_t xor = rand() % 0x7F;
			PASS[spot] ^= xor;
		} while ((PASS[spot] < RANGEMIN) || (PASS[spot] > RANGEMAX));
	}
}

int checkflag (char *guess) {
	// null terminate password
	guess[15] = '\0';
	// check password
	for (int i = 0; i < PASSLEN; i++) {
		if (PASS[i] != guess[i]) {
			printf("Incorrect password, try again:\n");
			fflush(stdout);
			return 0;
		}
	}
	printf("Correct password!\n");
	fflush(stdout);
	return 1;
}

int main(int argc, char **argv) {
	genPass();
	char guess[64];

	printf("Please enter the password to get the stopwatch flag:\n");
	fflush(stdout);
	for (;;) {
		memset(guess, 0, 64);
		if (checkflag(fgets(guess, 64, stdin))) {
			break;
		} 
	}
	return 0;	
}