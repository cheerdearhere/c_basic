#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* only basic */  
void StartChapter(char chapterName[]) {
	printf("%s ���� ����\n", chapterName, _countof(chapterName));
}
void CloseChapter(char chapterName[]) {
	printf("%s ���� ����\n", chapterName, _countof(chapterName));
}
/* // only basic */


int main(void) {
	StartChapter("�Լ� ");
	
	
	CloseChapter("�Լ�");
	return 0;
}
