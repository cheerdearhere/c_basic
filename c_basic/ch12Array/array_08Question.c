
#include <stdio.h>
#include <stdlib.h>
/*
for문을 사용해 int[5][5] 배열에 다음과 같이 저장하는 프로그램(달팽이 배열
예시
	1	2	3	4	5	
	16	17	18	19	6
	15	24	25	20	7
	14	23	22	21	8
	13	12	11	10	9
팁
	- 순차적으로 증가하는 칸으로 나눠서 보기
	- 가운데 값을 기준으로 변경되는 규칙 찾기
*/
int main() {
	int nArr[5][5] = { 0 };
	int innerNum = 0;

	// 시작 위치 변수 초기화
	int x = -1, y = 0;
	//연속적으로 증가하는 수의 길이 변수
	int length;
	// 배열을 채우는 방향
	int direction = 1;

	//insert
//	연속적으로 증가하는 수의 길이 : 9 > 7 > 5 > 3 > 1
	for (length = 9; length > 0; length -= 2) {
		//	길이만큼 수행
		for (int i = 0; i < length; i++) {
			//길이의 중간값 = 길이/2+1에서 방향 변동
			if (i < (length / 2 + 1)) {
				//중간값 이전에는 배열의 x좌표 이동
				x += direction;
			}
			else {
				//중간값 이후에는 배열의 y좌표 이동
				y += direction;
			}
			//해당 위치에 값 저장
			nArr[y][x] = ++innerNum;
		}
		// 방향 변경
		direction = -direction;
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
*/