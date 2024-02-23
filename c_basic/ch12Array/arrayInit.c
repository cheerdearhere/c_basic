#include <stdio.h>
int main(void) {

	int aList[5] = { 0 };
	aList[0] = 10;
	aList[1] = 20;
	aList[2] = 30;
	aList[3] = 40;
	aList[4] = 50;

	// aList = { 10,20,30,40,50 };
	for (int i = 0; i < 5; i++)
		printf("%d\t", aList[i]);
	putchar('\n');

	int bList[] = { 10,20,30,40,50 };//선언과 초기화
	bList[2] = 300;
	bList[3] = 400;
	for (int i = 0; i < 5; i++)
		printf("%d\t", bList[i]);
	putchar('\n');

	return 0;
}