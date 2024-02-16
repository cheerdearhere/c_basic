#include <stdio.h>
#include <stdlib.h>
int main(void) {
	char ch = 0;
	printf("문자 하나를 입력하세요: ");
	scanf_s("%c%*c", &ch, 1);
	printf("입력한 문자는 %c입니다.\n", ch);

	printf("4개 이하의 문자를 입력하세요: ");
	char szBuffer[4] = {0};
	scanf_s("%4c%*c", szBuffer, (unsigned)_countof(szBuffer));
 	printf("%c%c%c%c\n",szBuffer[0], szBuffer[1], szBuffer[2], szBuffer[3]);

	printf("50개 이하의 문자를 입력하세요: ");
	char szBigBuffer[50] = { 0 };
	scanf_s("%s%*c", szBigBuffer, (unsigned)_countof(szBigBuffer));
	printf("%s\n", szBigBuffer);

	printf("90개 이하의 문자를 입력하세요: ");
	char text[90];
	int text_size = sizeof(text);
	//  scanf_s(format, inputData, dataSize);
	scanf_s("%s", text, text_size);
	printf("-> %s\n", text);

	printf("왼쪽 머릿글과 오른쪽 머릿글을 입력하세요(각 30개 이하): ");
	char leftBuffer[30] = { 0 };
	char rightBuffer[30] = { 0 };
	scanf_s("%s %s",
		leftBuffer, (unsigned)_countof(leftBuffer),
		rightBuffer, (unsigned)_countof(rightBuffer));
	printf("%s\n%s", leftBuffer, rightBuffer);
	return 0;
}