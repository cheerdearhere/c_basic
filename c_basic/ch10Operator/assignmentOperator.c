#include <stdio.h>
int main(void) {
	int data = 0;
	int multi = 10;
	data = 10;//memory copy r -> l
	printf("data : %d\n", data);
	data = data + 5;// + �켱, �� �� = 
	// 1. data�� �� + 5 => �ӽð�� 15
//2. data�� location value�� �ӽð�� 15�� overwrite
	printf("data : %d\n", data);
	data *= multi;
	printf("data : %d\n", data);
	return data;
}