#include <stdio.h>
#include <stdlib.h>

int Add(int a, int b) {
	int nData = 0;
	nData = a + b;

	return nData;
}

int GetMax(int a, int b, int c) {
	int nMax = a;
	if (b > nMax) nMax = b;
	if (c > nMax) nMax = c;

	return nMax;
}
int GetMaxArr(int arr[], int length) {
	int nMax = arr[0];
	//	int length = sizeof(arr) / sizeof(int); �Լ� �����ͷ� ���޵� �迭�� ũ�⸦ üũ�� �� ����
	for (int i = 1; i < length; ++i) {
		if (arr[i] > nMax) nMax = arr[i];
	}
	return nMax;
}
int main(void) {

	int sum = 0;
	sum = Add(3, 4);
	printf("��: %d\n", sum);

	int max = 0;
	max = GetMax(10, 15, 3);
	printf("max: %d\n", max);
	printf("%d\n", GetMax(2, 3, 1) * 2); // �Լ��� ���� ��� ����
	printf("%d\n", max = GetMax(3, 1, 2));// ������ �־ �� ����� �Է��� �� �ִ�

	int nList[5] = { 4,5,12,2,1 };
	max = GetMaxArr(nList, sizeof(nList) / sizeof(int));
	printf("max: %d\n", max);

	return 0;
}
