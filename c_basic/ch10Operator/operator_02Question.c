#include <stdio.h>
/*
문제2
사용자로	부터 정수로 초(second)를 입력받아 '시:분:초' 형식으로 출력
시, 분, 초 정보는 모두 두자리 정수로 표시하고 
한 자리 숫자의 경우 앞에 0을 붙여 출력
콘솔 예시
	초를 입력하세요: 4000
	4000초는 1시간 06분 40초 입니다. 
*/
int main(void) {
	int inputSec = 0;
	int seconds = 0;
	int minutes = 0;
	int hours = 0;

	printf("초를 입력하세요: ");
	scanf_s("%d",&inputSec);
	
	minutes = inputSec / 60;
	seconds = inputSec % 60;

	hours = minutes / 60;
	minutes = minutes % 60;

	printf("%d초는 %02d시간 %02d분 %02d초 입니다\n", inputSec, hours, minutes, seconds);
/* 
오답노트	
	시간에 0표시 안함: %02d
팁
	- 우선 입력과 출력을 체크하고 연산을 생각하면 편하다
	- 매번 입력하기보다 예시값(4000)을 초기화에서 처리하고 예제를 실행하면 시간을 줄일 수 있다.
	- 더 간략히: 강사님 코드
		- 변수는 하나만 쓰도록하면 정리하기 좋음
			hour = input / 3600;
			min = (input % 3600) / 60;
			sec = input % 60;
		- 굳이 변수가 필요한가 체크
			printf("%d초는 %02d시간 %02d분 %02d초 입니다\n", 
				inputSec, 
				input / 3600, 
				(input % 3600) / 60, 
				input % 60
			);
		- 단위가 바뀌는 경계 값들이 제대로 처리가 되는지 확인
			0, 59, 60, 3599, 3600...
*/
	return 0;
}