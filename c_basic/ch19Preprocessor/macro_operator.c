#include <stdio.h>

#define STRING(a) #a
#define PASTER(a, b) a##b

int main(int argc, char* argv[]) {

	int nData = 10; 

	printf("nData\t: %d\n", nData);
	printf("nDa##ta\t: %d\n", PASTER(nDa, ta));// ���ڿ��� �ƴ� �ҽ��ڵ� ��ü�� ����
	printf("#nData\t: %s\n", STRING(nData));//"nData"

	return 0;
}