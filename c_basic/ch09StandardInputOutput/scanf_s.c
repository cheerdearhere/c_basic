#include <stdio.h>
#include <stdlib.h>
int main(void) {
	char ch = 0;
	printf("���� �ϳ��� �Է��ϼ���: ");
	scanf_s("%c%*c", &ch, 1);
	printf("�Է��� ���ڴ� %c�Դϴ�.\n", ch);

	printf("4�� ������ ���ڸ� �Է��ϼ���: ");
	char szBuffer[4] = {0};
	scanf_s("%4c%*c", szBuffer, (unsigned)_countof(szBuffer));
 	printf("%c%c%c%c\n",szBuffer[0], szBuffer[1], szBuffer[2], szBuffer[3]);

	printf("50�� ������ ���ڸ� �Է��ϼ���: ");
	char szBigBuffer[50] = { 0 };
	scanf_s("%s%*c", szBigBuffer, (unsigned)_countof(szBigBuffer));
	printf("%s\n", szBigBuffer);

	printf("90�� ������ ���ڸ� �Է��ϼ���: ");
	char text[90];
	int text_size = sizeof(text);
	//  scanf_s(format, inputData, dataSize);
	scanf_s("%s", text, text_size);
	printf("-> %s\n", text);

	printf("���� �Ӹ��۰� ������ �Ӹ����� �Է��ϼ���(�� 30�� ����): ");
	char leftBuffer[30] = { 0 };
	char rightBuffer[30] = { 0 };
	scanf_s("%s %s",
		leftBuffer, (unsigned)_countof(leftBuffer),
		rightBuffer, (unsigned)_countof(rightBuffer));
	printf("%s\n%s", leftBuffer, rightBuffer);
	return 0;
}