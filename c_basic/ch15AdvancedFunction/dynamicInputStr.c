#include <stdio.h>


char* GetName(void) {
	char* pszName = NULL;
	pszName = (char*)calloc(32, sizeof(char));//�����Ҵ�
	printf("�̸��� �Է��ϼ���: ");
	fgets(pszName, sizeof(char) * 32, stdin); //���������� ���
	// == gets_s()

	return pszName;
}
int main(int argc, char* argv[]) 
	char* pszName = NULL;
	pszName = GetName();
	//Callee���� �����Ҵ��� �޸� pszName�� stack frame ���ſ� �Բ� �����
	printf("����� �̸��� %s �Դϴ�.\n", pszName);

	//Collee�� �����Ƿ� �Ҵ� ������ å���� Caller
	free(pszName);

	return 0;
}
