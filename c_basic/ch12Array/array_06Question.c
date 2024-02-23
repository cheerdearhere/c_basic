#include <stdio.h>
#include <stdlib.h>
/*
for문을 사용해 int[5][5] 배열에 다음과 같이 저장하는 프로그램
예시
1	2	3	4	5
6	7	8	9	10
11	12	13	14	15
16	17	18	19	20
21	22	23	24	25
*/
int main() {
	int nArr[5][5] = { 0 };
	int innerNum = 0;
	//insert
	for (int i = 0; i < _countof(nArr); i++) {
		for (int j = 0; j < _countof(nArr[i]); j++) {
			nArr[i][j] = ++innerNum;
		}
	}
	//print
	for (int i = 0; i < _countof(nArr); i++) {
		for (int j = 0; j < _countof(nArr[i]); j++) {
			printf("%d\t", nArr[i][j]);
		}
		putchar('\n');
	}
	return 0;
}
/*
오답노트:
팁: 
	- 머리가 정리되고 나서 코딩을 해라
	- 우선 논리 정리를 하고 그 결과를 코드로 옮기는 것
		- 잘 그리고 잘 적어서 정리한 다음
		- 코드는 그 결과일뿐

*/