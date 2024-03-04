#include <stdio.h>

typedef union _IP_ADDR {
	int nAddress;
	short awData[2];
	unsigned char addr[4];
} IP_ADDR;

int main(int argc, char* argv[]) {
	
	IP_ADDR Data = { 0 };
	Data.nAddress = 0x41424344;
	
	printf("int nAddress\t: %X", Data.nAddress);
	putchar('\n');

	int it = sizeof(Data) / sizeof(char);
	printf("char addr\t: ");
	for(int i=0;i<it;i++)
		printf("%c, ", Data.addr[i]);
	putchar('\n');
	
	it = sizeof(Data) / sizeof(short);
	printf("short awData\t: ");
	for (int i = 0; i < it; i++)
		printf("%X, ", Data.awData[i]);
	putchar('\n');

	//초기화해서 다시 찍기
	Data.addr[0] = 192;
	Data.addr[1] = 168;
	Data.addr[2] = 0;
	Data.addr[3] = 1;

	printf("address: %d.%d.%d.%d\n", 
		Data.addr[0],
		Data.addr[1],
		Data.addr[2],
		Data.addr[3]
	);

	return 0;
}