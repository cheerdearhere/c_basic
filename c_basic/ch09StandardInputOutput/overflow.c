#include <stdio.h>
int main(void) {
	char szBuffer[8] = { 0 };

//	gets(szBuffer);// ������Ʈ ���� > ���� �Ӽ� > C/C++ > SDL üũ false(���Ȱ˻�x)
//  gets_s(char*_buffer, rsize_t_Size): ������ ���
//		sizeof(�迭) > �迭�� ũ��	
	gets_s(szBuffer,sizeof(szBuffer));
// fgets(char *_buffer, int *_maxCount, File *_Stream): ������ ���
	fgets(szBuffer, sizeof(szBuffer), stdin);
	puts(szBuffer);

	return 0;
}