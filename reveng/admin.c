#include <stdio.h>
#include <string.h>
#include "reveng.h"

static unsigned char FLAG0[FLAGLEN] = "revengflag000";
static unsigned char FLAG1[FLAGLEN] = "revengflag000";
static unsigned char FLAG2[FLAGLEN] = "revengflag000";

int main(int argc, char **argv) {
	// generate the flag
	genFlag0(FLAG0);
	printf("flag{%s}\n", FLAG0);
}