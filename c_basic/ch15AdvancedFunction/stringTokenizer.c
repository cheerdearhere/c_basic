#include <stdio.h>
#include <string.h>



int main(int argc, char* argv[]) {
	//String tokenizer �Լ� ���
		// ����
	char szBuffer[128] = { "nData = x + y; \nnResult = a * b" };
	// ������ ����: ����, ������, \n
	char* pszSep = " *+=;\n";
	char* pszToken = NULL;
	char* pszNextToken = NULL;
	//strtok_s(��� ���ڿ�, separator, ó���� ��ū�� ����Ű�� ������)
	pszToken = strtok_s(szBuffer, pszSep, &pszNextToken);
	// ���������� ���������� ���ٺ��� ��Ƽ������ ���� �̽��� �־�����
	// ������ ���� ���丮�� ������� �ذ��
	while (pszToken != NULL) {
		puts(pszToken);
		pszToken = strtok_s(NULL, pszSep, &pszNextToken);
		//��� �޸��� ���� 00(null)�� ��ȯ
	}
	printf("\nszBuffer: %s\n", szBuffer);
	//���� ���ۿ��� ������ ��

	return 0;
}
