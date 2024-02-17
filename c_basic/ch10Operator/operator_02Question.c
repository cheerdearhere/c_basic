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

	printf("%d초는 %d시간 %02d분 %02d초 입니다\n", inputSec, hours, minutes, seconds);
/* 
오답노트	

*/
	return 0;
}