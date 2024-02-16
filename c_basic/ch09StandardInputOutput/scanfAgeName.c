#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char name[32] = { 0 };
	int nAge = 0;

	printf("나이를 입력하세요 : ");
	scanf_s("%d%*c", &nAge);

	printf("이름을 입력하세요: ");
	gets_s(name, sizeof(name));

	printf("나이: %d세, 이름: %s", nAge, name);

	return 0;
}