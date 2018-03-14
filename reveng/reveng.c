#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define FLAGLEN 16
#define RANGEMIN 40
#define RANGEMAX 126
#define PI 314159265

static unsigned char FLAG[FLAGLEN] = "revengflag000";

void genFlag(void) {
	srand(PI);
	int max = rand() % PI;
	for (int i = 0; i < max; i++) {
		int spot = rand() % FLAGLEN;
		do {
			uint8_t xor = rand() % 0x7F;
			FLAG[spot] ^= xor;
		} while ((FLAG[spot] < RANGEMIN) || (FLAG[spot] > RANGEMAX));
	}
}

char makePrintable(unsigned char c) {
	return (c % (RANGEMAX - RANGEMIN)) + RANGEMIN;
}

int main(int argc, char **argv) {
	if (argc != 2 || (strlen(argv[1]) == 0)) {
		printf("Usage: %s mask(string)\n", argv[0]);
		return(1);
	}
	unsigned char mask[5];
	memset(mask, 0, 5);
	strncpy(mask, argv[1], 4);
	while (strlen(mask) < 4) {
		mask[strlen(mask)] = mask[0];
	}
	// generate the flag
	genFlag();
	// Uncomment the following line only to determine the flag to save
	// printf("flag{%s}\n", FLAG);

	// flag manipulation
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			unsigned char *tmp = &(FLAG[j * 4 + i]);
			switch(i) {
				case 0:
					*tmp ^= mask[j];
					break;
				case 1:
					*tmp |= ~mask[j];
					break;
				case 2:
					*tmp &= mask[j];
					break;
				default:
					*tmp = ~*tmp;
					break;
			}
			*tmp = makePrintable(*tmp);
		}
	}
	// print flag manipulated by input chars
	printf("flag{%s}\n", FLAG);
}