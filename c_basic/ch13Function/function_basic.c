#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void startChapter(char chapterName[]) {
	printf("%s 연습 시작\n", chapterName, _countof(chapterName));
}
void closeChapter(char chapterName[]) {
	printf("%s 연습 종료\n", chapterName, _countof(chapterName));
}

int Add(int a, int b){
	int nData = 0;
	nData = a + b;
	return nData;
}

int main(void) {
	startChapter("함수");

	

	closeChapter("함수");
	return 0;
}
