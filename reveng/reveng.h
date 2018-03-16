#include <stdlib.h>
#include <stdint.h>

#define FLAGLEN 16
#define RANGEMIN 33
#define RANGEMAX 126
#define PI 314159265

void genFlag0(char *flag);
void genFlag1(char *flag);
void genFlag2(char *flag);
char makePrintable(unsigned char c);