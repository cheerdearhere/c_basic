#include <stdio.h>

// global(static) variable 
int g_nCounter = 0;
// �����͸� �ٷ�� function
void InitCounter(int nData) {
	g_nCounter = nData;
}
void IncreaseCounter(void) {
	g_nCounter++;
}

int main(void) {
	//���ο� ������ ��� ����...
	//���غ��̰����� �ٸ� ��� �Լ��� �����ϱ⿡ ����
	InitCounter(10);
	printf("%d\n", g_nCounter);
	IncreaseCounter();
	printf("%d\n", g_nCounter);
	IncreaseCounter();
	printf("%d\n", g_nCounter);
	return 0;
}
