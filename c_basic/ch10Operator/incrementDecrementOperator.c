#include <stdio.h>
int main(void) {
	int x = 0;
	printf("%d\n", x);
	// ����
	x = x + 1;
	printf("%d\n", x);
	// ���մ���
	x += 1;
	printf("%d\n", x);
	//��������
	printf("%d\n", ++x);
	printf("%d\n", x++);
	++x; // ������ 
	x++; // ������

	x = 0; 
	int nResult = 0;
	
	++x;
	printf("++x: %d\n", x);
	x++;
	printf("x++: %d\n", x);
	nResult = ++x;
	printf("++x: %d, res: %d\n", x, nResult);
	nResult = x--;
	printf("x--: %d, res: %d\n", x, nResult);

	int a = 5, b = 10, data = 0;
	data = ++a + ++b + a--;
	//      6     11   6 = 23
	printf("%d\n", data);
	return 0;
}