#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int userAge = 0;
	char userName[30] = { 0 };

	printf("나이를 입력하세요: ");
	scanf_s("%d%*c", &userAge);

	printf("이름을 입력하세요: ");
	gets_s(userName, sizeof(userName));

	printf("당신의 나이는 %d살이고 이름은 '%s' 입니다.\n", userAge, userName);
}

/*
사용자로부터 이름과 나이를 키보드로 입력받아 출력하는 프로그램
이름은 gets_s, 나이는 scanf_s 함수로 입력받고
printf 함수로 출력
실행 예시
	나이를 입력하세요: 20
	이름을 입력하세요: 철수

	당신의 나이는 20살이고 이름은 '철수' 입니다.
*/