#include <stdio.h>
int main(void) {
	int tArr[3][4] = { 0 };
	int innerNum = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			tArr[i][j] = ++innerNum;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d\t", tArr[i][j]);
		}
		putchar('\n');
	}

	return 0;
}