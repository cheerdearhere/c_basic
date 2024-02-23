#include <stdio.h>
#include <stdlib.h>
/*
for문을 사용해 int[5][5] 배열에 다음과 같이 저장하는 프로그램
예시
	1	2	3	4	5
	10	9	8	7	6
	11	12	13	14	15
	20	19	18	17	16
	21	22	23	24	25
팁
	행에 따라 넣는 순서를 다르게할지 삽입할 값을 변경할지 고민
*/
int main() {
	int nArr[5][5] = { 0 };
	int innerNum = 0;
	//insert
	for (int i = 0; i < _countof(nArr); i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < _countof(nArr); j++) {
				nArr[i][j] = ++innerNum;
			}
		}
		else {
			for (int j = _countof(nArr) - 1; j >= 0; j--) {
				nArr[i][j] = ++innerNum;
			}
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
	- for문을 2개로 쓰기보다 보수개념을 쓰면 더 간략히 쓸 수 있다
		for (int i = 0; i < _countof(nArr); i++) {
			for (int j = 0; j < _countof(nArr); j++) {
				if (i % 2 == 0) {
					nArr[i][j] = ++innerNum;
				}
				else{
					nArr[i][4 - j] = ++innerNum;
				}
			}
		}
	- 들어가는 숫자값을 고려해서 해도 작동했겠지만 굳이...
	- if (i % 2 == 0)이 부분을 flag로 처리해서 사용할 수도 있다
		int flag = 1;
		...중간 생략
		for (int i = 0; i < _countof(nArr); i++) {
			for (int j = 0; j < _countof(nArr); j++) {
				if (flag) {
					nArr[i][j] = ++innerNum;
				}
				else{
					nArr[i][4 - j] = ++innerNum;
				}
				flag = !flag;
			}
		}
*/