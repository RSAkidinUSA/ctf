#include <stdio.h>
#include <string.h>
#include "reveng.h"

static char SALT[FLAGLEN] = "SALTY SEA SALT!";
#define shiftAmount 31;

char myShift(unsigned char sub) {
	unsigned char tmp = sub + shiftAmount;
	tmp %= (RANGEMAX - RANGEMIN);
	tmp += RANGEMIN;
	return tmp;
}

void genFlag0(char *flag) {
	char tmp = flag[0];
	for (int i = 0; i < FLAGLEN - 2; i++) {
		flag[i] = flag[i+1];
		flag[i] = myShift(flag[i]);
	};
	flag[14] = myShift(tmp);
}

void genFlag1(char *flag) {
	// flag manipulation
	for (int i = 0; i < FLAGLEN - 1; i++) {
		unsigned char *tmp = &(flag[i]);
		switch(i % 4) {
			case 0:
				*tmp ^= SALT[i];
				break;
			case 1:
				*tmp |= ~SALT[i];
				break;
			case 2:
				*tmp &= SALT[i];
				break;
			default:
				*tmp = ~SALT[i];
				break;
		}
		*tmp = makePrintable(*tmp);
	}
}

void genFlag2(char *flag) {
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