#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* only basic */  
void StartChapter(char chapterName[]) {
	printf("%s 연습 시작\n", chapterName, _countof(chapterName));
}
void CloseChapter(char chapterName[]) {
	printf("%s 연습 종료\n", chapterName, _countof(chapterName));
}
/* // only basic */


int main(void) {
	StartChapter("함수 ");
	
	
	CloseChapter("함수");
	return 0;
}
