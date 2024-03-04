#include <stdio.h>

#pragma pack(push,1)
typedef struct USERDATA {
	char ch;
	int nAge;
	char szName[5];
} USERDATA;

int main(int argc, char* argv[]) {
	USERDATA user = { 'A',10,"Choon" };
	
	int data = 0x11223344;
	
	printf("%d\n", sizeof(USERDATA));

	return 0;
}