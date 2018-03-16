#include <stdio.h>
#include <string.h>
#include "reveng.h"

void genFlag0(char *flag) {
	srand(PI);
	int max = rand() % PI;
	for (int i = 0; i < max; i++) {
		int spot = rand() % (FLAGLEN - 1);
		do {
			uint8_t xor = rand() % 0x7F;
			flag[spot] ^= xor;
		} while ((flag[spot] < RANGEMIN) || (flag[spot] > RANGEMAX));
	}
}



char makePrintable(unsigned char c) {
	return (c % (RANGEMAX - RANGEMIN)) + RANGEMIN;
}