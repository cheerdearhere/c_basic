#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void startChapter(char chapterName[]) {
	printf("%s ���� ����\n", chapterName, _countof(chapterName));
}
void closeChapter(char chapterName[]) {
	printf("%s ���� ����\n", chapterName, _countof(chapterName));
}

int Add(int a, int b){
	int nData = 0;
	nData = a + b;
	return nData;
}

int main(void) {
	startChapter("�Լ�");

	

	closeChapter("�Լ�");
	return 0;
}
