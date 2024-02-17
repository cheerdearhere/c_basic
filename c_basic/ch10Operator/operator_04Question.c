#include <stdio.h>
/*
사용자로부터 세 정수를 입력받아 총합을 출력
사용자 입력이 저장되는 변수 하나와 값을 누적하는 변수 하나만 사용해 구현
출력 예시 
	1
	2
	3
	total: 6
*/
int main(void) {
	int saveNum = 0, inputNum = 0;

	scanf_s("%d", &inputNum);
	saveNum += inputNum;
	scanf_s("%d", &inputNum);
	saveNum += inputNum;
	scanf_s("%d", &inputNum);
	saveNum += inputNum;
	
	printf("Total: %d\n", saveNum);
	return 0;
/*
오답노트: 
팁: 
	- 변수명은 좀 더 직관적이고 짧고 쉽게: 
		saveNum -> total
		inputNum -> input
	- 전체를 돌리기보다 테스트 코드로:
		처음부터 scanf_s를 쓰기보다 상수를 사용
		input = 1;
	- 지역변수를 선언하고 초기화하지 않으면 연산을 진행할 수 없다. 
*/
}