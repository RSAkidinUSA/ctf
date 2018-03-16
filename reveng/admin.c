#include <stdio.h>
#include <string.h>
#include "reveng.h"

static unsigned char FLAG0[FLAGLEN] = "xxRevEngFlag0xx";
static unsigned char FLAG1[FLAGLEN] = "b1t0ps4reFUN001";
static unsigned char FLAG2[FLAGLEN] = "CheckTheRetVals";
static unsigned char FLAG3[FLAGLEN] = "r3v3ng13stfl4g3";

// check if character needs to be escapable
int escapable(char c) {
	switch (c) {
		case '\'':
		case '%':
		case '"':
		case '\\':
		case '\?':
			return 1;
		default:
			return 0;
	}
}

// write flags to header file
void writeHeader(int flagNum, char *flag, FILE *f) {
	char tmp[64], tmpFlag[64];
	memset(tmp, 0, 64);
	memset(tmpFlag, 0, 64);
	int count = 0;
	for (int i = 0; i < FLAGLEN; i++) {
		// check valid chars
		if (escapable(flag[i])) {
			tmpFlag[count++] = '\\';
		}
		tmpFlag[count++] = flag[i];
	}
	sprintf(tmp, "unsigned char FLAG%d[FLAGLEN] = \"%s\";\n", flagNum, tmpFlag);
	fputs(tmp, f);
}

int main() {
	char tmp[16];
	FILE *f = fopen("flags.h", "w");
	fputs("#include \"reveng.h\"\n\n", f);
	// generate the flag for attack 0
	memset(tmp, '\0', 16);
	strncpy(tmp, FLAG0, 15);
	
	genFlag0(tmp);
	printf("Flag0: flag{%s}, ", FLAG0);
	printf("Value: %s\n", tmp);
	writeHeader(0, tmp, f);

	// generate the flag for attack 1
	memset(tmp, '\0', 16);
	strncpy(tmp, FLAG1, 15);
	
	genFlag1(tmp);
	printf("Flag1: flag{%s}, ", FLAG1);
	printf("Value: %s\n", tmp);
	writeHeader(1, tmp, f);

	// generate the flag for attack 2
	memset(tmp, '\0', 16);
	strncpy(tmp, FLAG2, 15);
	
	genFlag2(tmp);
	printf("Flag2: flag{%s}, ", FLAG2);
	printf("Value: %s\n", tmp);
	writeHeader(2, tmp, f);

	// generate the flag for attack 2
	memset(tmp, '\0', 16);
	strncpy(tmp, FLAG3, 15);
	
	genFlag3(tmp);
	printf("Flag3: flag{%s}, ", FLAG3);
	printf("Value: %s\n", tmp);
	writeHeader(3, tmp, f);

	fflush(f);
	fclose(f);
	return 0;
}