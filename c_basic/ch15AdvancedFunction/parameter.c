#include <stdio.h>

void TestFunc(int a, int c) {
	//int b = 20;
//	int a = 20; �̹� �Ű��������� ȣ����
	a = 10;
	int b = a + c;
}
int main(int argc, char* argv[]) {

	TestFunc(5, 10);

	return 0;
}
