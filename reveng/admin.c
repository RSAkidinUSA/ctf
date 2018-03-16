#include <stdio.h>
#include <string.h>
#include "reveng.h"

static unsigned char FLAG0[FLAGLEN] = "revengflag00000";
static unsigned char FLAG1[FLAGLEN] = "revengflag00001";
static unsigned char FLAG2[FLAGLEN] = "revengflag00002";

int main() {
	char tmp[16];
	// generate the flag
	memset(tmp, '\0', 16);
	strncpy(tmp, FLAG0, 15);
	
	genFlag0(tmp);
	printf("Flag0: flag{%s}\n", FLAG0);
	printf("Value to write to reveng0.c: %s\n", tmp);
}