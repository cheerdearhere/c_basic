#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main(int argc, char* argv[]) {

	//concatenation ����: ��� ���̱�
		//file path: ���� ��� ����κ�
	char szPath[128] = { "C:\\Program Files\\" };
	//path�Է�
	char szBuffer[128] = { 0 };
	printf("Input path: ");
	gets_s(szBuffer, sizeof(szBuffer));
	// ���ڿ� ��ġ��
	strcat_s(szPath, sizeof(szPath), szBuffer);
	puts(szPath);

	// ���̸� üũ�ؼ� ���޾� ����ϱ�
	strcpy_s(szPath, sizeof(szPath), "C:\\Program Files\\");
	//�������� ��ĥ������ ������üũ�� ���� �ؾ���
	strcat_s(szPath, sizeof(szPath), "CHS\\");
	strcat_s(szPath, sizeof(szPath), "C programming");
	puts(szPath);

	//strcat: ���� �̽��� �Ʒ��� ��ü(�Է¹޴� ���ڿ�ũ�� �Է�)
		//strcpy_s(szPath, sizeof(szPath), "C:\\Program Files\\");
		//strcat(szPath + strlen("C:\\Program Files\\"), "CHS\\");
		//strcat(szPath + strlen("C:\\Program Files\\CHS\\"), "C programming");
		// puts(szPath);
	//strcat_s 
		// szPath + ���� > index 0���� �̵�
	strcpy_s(szPath, sizeof(szPath), "C:\\Program Files\\");
	strcat_s(szPath + strlen("C:\\Program Files\\"), sizeof(szPath) - 17, "CHS\\");
	strcat_s(szPath + strlen("C:\\Program Files\\CHS\\"), sizeof(szPath) - 25, "C programming");
	puts(szPath);
	//strcpy: ��Ȯ�� �ּҸ� �˰��ִٸ� �׳� �����ؼ� ���
	strcpy_s(szPath, sizeof(szPath), "C:\\Program Files\\");
	strcpy_s(szPath + strlen("C:\\Program Files\\"), sizeof(szPath) - 17, "CHS\\");
	strcpy_s(szPath + strlen("C:\\Program Files\\CHS\\"), sizeof(szPath) - 25, "C programming");
	puts(szPath);
	//sprintf����ϱ�
	char szOriginPath[128] = { 0 };
	char szInputBuffer[128] = { 0 };

	printf("Input path: ");
	gets_s(szInputBuffer, sizeof(szInputBuffer));

	//sizeof�� �ƴ� _countof ������� ���
	sprintf_s(
		szOriginPath, //������ ��
		_countof(szOriginPath),//ũ��
		"C:\\Program Files\\%s",// ����ȭ�� ���ڿ�
		szInputBuffer//�Է�
	);
	puts(szOriginPath);
}