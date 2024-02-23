#include <stdio.h>
#include <stdlib.h>

int main() {
	int aList[3][4] = {
		{10,20,30},
		{40,50,60}
	};
	for (int i = 0; i < _countof(aList); i++) {
		//행 합
		int sum = 0;
		for (int j = 0; j < _countof(aList[i]); j++) {
			if (i < 2) {
				if (j < 3)
					sum += aList[i][j];
				else if (j == 3)
					aList[i][j] = sum;
			}
			else if (i == 2) {
				aList[i][j] = aList[0][j] + aList[1][j];
			}
			else
				continue;
		}
	}
	//print
	for (int i = 0; i < _countof(aList); i++) {
		for (int j = 0; j < _countof(aList[i]); j++) {
			printf("%d\t", aList[i][j]);
		}
		putchar('\n');
	}
	return 0;
}

/*
오답노트:
팁: 
*/