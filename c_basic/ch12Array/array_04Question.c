#include <stdio.h>
/*
����:  for���� ����� int[5] �迭�� ����� ������ ������������ �����ϴ� ���α׷�
	������ �˰��� ���
��� ����
	 3 5 1 4 2 
	 ����
	 1 2 3 4 5
*/
void quickSort(int arr[], int left, int right) {
	if (left < right) {// ���� ���� �������� �������� return 
		int pivot = arr[left]; // �� ���� value
		int low = left + 1; // �� ��� index
		int high = right; // �� �ִ� index

		while (low <= high) {// �񱳴�� �̵�
			// low�� �������� ����� �ʰ�, low�� �ǹ����� �۰ų� ���� ���� low�� �̵�
			while (low <= right && arr[low] <= pivot)
				low++;
			// high�� ������ ����� �ʰ�, high�� �ǹ����� ũ�ų� ���� ���� high�� �̵�
			while (high >= (left + 1) && arr[high] >= pivot)
				high--;

			// low�� high�� �������� �ʾ��� ��
			if (low <= high) {
				// low�� high ��ġ�� ��Ҹ� ��ȯ
				int temp = arr[low];
				arr[low] = arr[high];
				arr[high] = temp;
			}
		}
		// �ǹ��� �ùٸ� ��ġ�� �̵�
		int temp = arr[left];
		arr[left] = arr[high];
		arr[high] = temp;
		// �ǹ��� �������� ���ʰ� ������ �κ� �迭�� ��������� ����
		quickSort(arr, left, high - 1);
		quickSort(arr, high + 1, right);
	}
}
int main(void) {//���� ��
	int nList[] = { 3,5,1,4,2 };
	int n = sizeof(nList) / sizeof(nList[0]);
	for (int i = 0; i < 5; i++)
		printf("%d\t", nList[i]);
	putchar('\n');

	quickSort(nList, 0, n - 1);
	printf("sort\n");

	//���� ��
	for (int i = 0; i < 5; i++)
		printf("%d\t", nList[i]);
	putchar('\n');

	return 0;
}

/*
�����Ʈ:
��: 
*/