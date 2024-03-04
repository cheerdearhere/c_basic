#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct _DATAFLAG {
	unsigned char main : 1;
	unsigned char left : 2;
	unsigned char right : 3;
	unsigned char top : 2;
} DATAFLAG;


int main(int argc, char* argv[]) {

	DATAFLAG flagSwitch = { 1,3,7,5 };

	printf("data: \n\tmain: %d\n\tleft: %d\n\tright: %d\n\ttop: %d\nflag: %X\nsize: %zd\n",
		flagSwitch.main,
		flagSwitch.left,
		flagSwitch.right,
		flagSwitch.top,
		*((unsigned char*)&flagSwitch),
		sizeof(flagSwitch)
	);

	printf("main = flag & 0x01: %d\n", *((unsigned char*)&flagSwitch) & 0x01);
	printf("left = flag & 0x06: %d\n", *((unsigned char*)&flagSwitch) & 0x06);
	printf("left = flag & 0x06 >> 1: %d\n", *((unsigned char*)&flagSwitch) & 0x06 >> 1);

	return 0;
}
