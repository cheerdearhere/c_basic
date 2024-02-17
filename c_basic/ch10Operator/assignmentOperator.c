#include <stdio.h>
int main(void) {
	int data = 0;
	int multi = 10;
	data = 10;//memory copy r -> l
	printf("data : %d\n", data);
	data = data + 5;// + 우선, 그 후 = 
	// 1. data의 값 + 5 => 임시결과 15
//2. data의 location value에 임시결과 15가 overwrite
	printf("data : %d\n", data);
	data *= multi;
	printf("data : %d\n", data);
	return data;
}