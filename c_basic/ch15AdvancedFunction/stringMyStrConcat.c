#include <stdio.h>
char* mystrcat(char* pszDst, char* pszSrc) {//������ �ּҿ� �Է�
	while (*pszDst != '\0') //���ڹ迭�� �ش� �����Ͱ� null�� �ƴϸ�
		++pszDst;// �������� ���������� �̵�

	while (*pszSrc != '\0')
		*pszDst++ = *pszSrc++;

	// ���� �� �ϳ��� ����(������ ����)
	*++pszDst = '\0';// ������ ���� ������ ���� �������� ������ index ������ null�Է�
	return --pszDst;//���� ������ ��ȯ
}


int main(int argc, char* argv[]) {

	char szPath[128] = { 0 };
	char* pszEnd = NULL;

	//char szPath[]�� �ּҸ� ����ϹǷ� ������ ������ ��
	pszEnd = mystrcat(szPath, "C:\\Program Files\\");
	pszEnd = mystrcat(pszEnd, "CHS\\");
	pszEnd = mystrcat(pszEnd, "C programming");

	puts(szPath);

	return 0;
}
