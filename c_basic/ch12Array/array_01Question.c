#incluide <stdio.c>
/*
����: for���� ����� int[5] �迭�� ����� �� �� ���� ū ���� ã�� ����ϴ� ���α׷��� �ۼ�
���� ���� ���� ���� ã�� ���, int[0]�� �ּҰ��� ����ǵ�����. �迭 ����� ���� ������� �ʵ��� ��ȯ
���ѻ���
	int nMax ���
��¿���
	50 40 10 50 20
	MAX: 50
	MIN: 10
	10 40 50 50 20
*/
int main(void) {
	//init
	int nMax = 0;
	int nMin = 0;
	int nArray[5] = { 0 };// = { 50, 40, 10, 50, 20 };//�Է� �ȹ�����

	//input
	for (int i = 0; i < _countof(nArray); i++) {
		scanf_s("%d", &nArray[i]);//�Է� ������
	}

	for (int i = 0; i < _countof(nArray); i++)
		printf("%d\t", nArray[i]);
	//max
	nMax = nArray[0];
	for (int i = 1; i < _countof(nArray); i++) {
		if (nMax < nArray[i])
			nMax = nArray[i];
	}
	printf("\nMAX: %d\n", nMax);
	//min
	nMin = nArray[0];
	for (int i = 1; i < _countof(nArray); i++) {
		if (nArray[0] > nArray[i]) {
			int temp = nArray[0];
			nArray[0] = nArray[i];
			nArray[i] = temp;
		}
	}
	nMin = nArray[0];
	printf("MIN: %d\n", nMin);

	for (int i = 0; i < _countof(nArray); i++) {
		printf("%d\t", nArray[i]);
	}
	putchar('\n');

	return 0;
}
/*
�����Ʈ:
	- �迭�� ������ �̷��� ��� ù �ʱⰪ�� 0�� max�γ����� ����
		- �ִ밪 �ּҰ��� ����Ҷ� ���ذ��� �̸� �ְ� ��ȸ�� ���̴� ��� ���
	max = nArray[0];
	for(int i = 1; i < 5 ; i++){...
��: 
	- ����� �߰��߰��� �ؼ� ������ ������ ���ݾ� ��ư���

*/