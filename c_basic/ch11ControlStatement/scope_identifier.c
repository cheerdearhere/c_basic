#include<stdio.h>
int main(void) 
{
	int x = 1;//1
	printf("%d\n", x); //1 stack frame
	if (x > 0) {
		int x = 2;//2
		printf("%d\n", x); //2 stack frame
		if (x > 1) {
			int x = 3;//3 
			printf("%d\n", x); //3 stack frame
		}
	}
	//	printf("%d",b); // b는 접근 불가
	printf("%d\n", x);//2,3은 scope를 벗어나 stack frame이 사라져 함께 소멸됨 
	// 1 stack frame 호출

	int nInput = 0; //1번
	scanf_s("%d", &nInput);
	printf("1: before: %d\n", nInput);

	if (nInput > 0) {
		printf("2: before: %d\n", nInput);
		int nInput = 100; //2번
		printf("2: after: %d\n", nInput);
	}

	printf("1: after: %d\n", nInput);

	return 0;
}