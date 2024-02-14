#include <stdio.h>
int main(void) {
	char szBuffer[8] = { 0 };

//	gets(szBuffer);// 프로젝트 설정 > 구성 속성 > C/C++ > SDL 체크 false(보안검사x)
//  gets_s(char*_buffer, rsize_t_Size): 윈도우 기반
//		sizeof(배열) > 배열의 크기	
	gets_s(szBuffer,sizeof(szBuffer));
// fgets(char *_buffer, int *_maxCount, File *_Stream): 리눅스 기반
	fgets(szBuffer, sizeof(szBuffer), stdin);
	puts(szBuffer);

	return 0;
}