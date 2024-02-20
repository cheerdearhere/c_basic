#include <stdio.h>
int main(void) {

	char cOperator = 0;
	int x = 0, y = 0, nResult = 0;
	printf("연산 식을 입력해주세요\n 합:+ 차:- 곱:* 몫:/ 나머지:\% \n ex) 10*11\n");
	scanf_s("%d%c%d", &x, &cOperator, 1, &y);

	switch (cOperator) {
		case '+':
			nResult = x + y;
			break;
		case '-':
			nResult = x - y;
			break;
		case '*':
			nResult = x * y;
			break;
		case '/':
			if (y == 0) {
				nResult = 0;
			}
			else nResult = x / y;
			break;
		case '%':
			if (y == 0) {
				nResult = 0;
			}
			else nResult = x % y;
			break;
		default:
			nResult = 0;
			break;
	}
	printf("%d %c %d = %d\n", x, cOperator, y, nResult);

	return 0;
}