#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define FLAGLEN 16
#define RANGEMIN 40
#define RANGEMAX 126
#define SEED 562951413

static unsigned char FLAG[FLAGLEN] = "revengflag000";

void genFlag(void) {
	srand(SEED);
	int max = rand() % (SEED / 2);
	for (int i = 0; i < max; i++) {
		int spot = rand() % FLAGLEN;
		do {
			uint8_t xor = rand() % 0x7F;
			FLAG[spot] ^= xor;
		} while ((FLAG[spot] < RANGEMIN) || (FLAG[spot] > RANGEMAX));
	}
}

int main(int argc, char **argv) {
	if (argc != 2 || (strlen(argv[1]) == 0)) {
		printf("Usage: %s guess\n", argv[0]);
		return(1);
	}
	char tmp[51];
	memset(tmp, 0, 51);
	// generate the flag
	genFlag();
	sprintf(tmp, "flag{%s}", FLAG);
	// Uncomment the following line only to determine the flag to save
	// printf("flag{%s}\n", FLAG);

	for (int i = 0; i < FLAGLEN + strlen("flag{") + strlen("}"); i++) {
		if (tmp[i] != argv[1][i]) {
			printf("Guess, %s, is not correct!\n", argv[1]);
			return 1;
		}
	}
	printf("Guess, %s, was correct!\n", argv[1]);
	return 0;
}