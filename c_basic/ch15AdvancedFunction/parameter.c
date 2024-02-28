#include <stdio.h>

void TestFunc(int a, int c) {
	//int b = 20;
//	int a = 20; 이미 매개변수에서 호출함
	a = 10;
	int b = a + c;
}
int main(int argc, char* argv[]) {

	TestFunc(5, 10);

	return 0;
}
