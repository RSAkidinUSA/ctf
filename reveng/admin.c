#include <stdio.h>
#include <string.h>
#include "reveng.h"

static unsigned char FLAG0[FLAGLEN] = "xxRevEngFlag0xx";
static unsigned char FLAG1[FLAGLEN] = "b1t0ps4reFUN001";
static unsigned char FLAG1[FLAGLEN] = "b1t0ps4reFUN001";
static unsigned char FLAG3[FLAGLEN] = "r3v3ng13stfl4g3";

int main() {
	char tmp[16];
	// generate the flag for attack 0
	memset(tmp, '\0', 16);
	strncpy(tmp, FLAG0, 15);
	
	genFlag0(tmp);
	printf("Flag0: flag{%s}, ", FLAG0);
	printf("Value: %s\n", tmp);

	// generate the flag for attack 1
	memset(tmp, '\0', 16);
	strncpy(tmp, FLAG1, 15);
	
	genFlag1(tmp);
	printf("Flag1: flag{%s}, ", FLAG1);
	printf("Value: %s\n", tmp);

	// generate the flag for attack 2
	memset(tmp, '\0', 16);
	strncpy(tmp, FLAG2, 15);
	
	genFlag2(tmp);
	printf("Flag2: flag{%s}, ", FLAG2);
	printf("Value: %s\n", tmp);

	// generate the flag for attack 2
	memset(tmp, '\0', 16);
	strncpy(tmp, FLAG3, 15);
	
	genFlag2(tmp);
	printf("Flag3: flag{%s}, ", FLAG3);
	printf("Value: %s\n", tmp);

	return 0;
}