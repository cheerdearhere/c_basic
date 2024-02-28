#include <stdio.h>
#include <string.h>
/*
�� char[]�� �ּҸ� �Ű������� �޾� ���ڿ��� Deap copy�ϴ� MyStrcpy() �ۼ�
�Լ��� �ι�° �Ű������� ù��° �Ű������� �޸� ũ�Ⱑ �ǵ��� ����
	int main(int argc, char* argv[]) {
		char szBufferSrc[12] = { "TestString" };
		char szBufferDst[12] = { 0 };

		MyStrcpy(szBufferDst, sizeof(szBufferDst), szBufferSrc);
		puts(szBufferDst);
		return 0;
	}
��� ����
	TestString
*/
void MyStrcpy(char* targetArr, int length, char* sorceArr) {
	size_t nLenSrc = 0;
	nLenSrc = strlen(targetArr);

	for (int i = 0; i < nLenSrc; i++)
		targetArr[i] = sorceArr[i];
}


int main(int argc, char* argv[]) {
	char szBufferSrc[12] = { "TestString" };
	char szBufferDst[12] = { 0 };

	MyStrcpy(szBufferDst, sizeof(szBufferDst), szBufferSrc);
	puts(szBufferDst);
	return 0;
}
/*
�����Ʈ:
	- �� �� ��Ȯ�� �Ű������� size�� unsigned int�� ���
		void MyStrcpy(char* targetArr, unsigned int length, char* sorceArr) {

��: 
	- �� �ڷ�� ����� ũ�⸦ ���� üũ�ؾ��Ѵ�(����� ����� �μ��� �޴� ����). 
		if (nLenSrc + 1 > length) {
		// exception: �ٸ� ���� ����ó���� �н����� �ʾ����Ƿ� ����
		return;
	}
	- strlen(char*)�� ���� �ʾƵ� ������ �ȴ�. 
		- ������ ��� �޸� ũ�Ⱑ 12����Ʈ�� ������ 5����Ʈ�� 7����Ʈ ��ŭ�� ������ ���� ����ȴ�
		- �� ������ ���� ������ �߻���Ű�Ƿ� Deep copy�� ������ ������ ����� �� �� ����.
	size_t nLenSrc = 0;
	nLenSrc = strlen(targetArr);
*/ 