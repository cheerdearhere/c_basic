#incluide <stdio.c>
/*
����: for���� ����� int[5] �迭�� ����� ������ ���� �������� �����ϴ� ���α׷�
���ѻ���
	�������� �˰��� ���
��� ����
	 50 40 10 50 20
	 ����
	 10 20 40 50 50
	 3 5 1 4 2 
	 ����
	 1 2 3 4 5
*/
int main(void) {
	int aList[] = { 50,40,10,50,20 };

	for (int i = 0; i < 5; i++)
		printf("%d\t", aList[i]);
	putchar('\n');
	for (int i = 0; i < 4; i++) {
		for (int j = i+1; j < 5; j++) {
			if (aList[i] > aList[j]) {
				int temp = aList[i];
				aList[i] = aList[j];
				aList[j] = temp;
			}
		}
	}
	printf("sort\n");
	for (int i = 0; i < 5; i++)
		printf("%d\t", aList[i]);
	putchar('\n');

	int bList[] = { 3,5,1,4,2 };
	for (int i = 0; i < 5; i++)
		printf("%d\t", bList[i]);
	putchar('\n');
	for (int i = 0; i < 4; i++) {
		for (int j = i+1; j < 5; j++) {
			if (bList[i] > bList[j]) {
				int temp = bList[i];
				bList[i] = bList[j];
				bList[j] = temp;
			}
		}
	}
	printf("sort\n");
	for (int i = 0; i < 5; i++)
		printf("%d\t", bList[i]);
	putchar('\n');

	return 0;
}
/*
�����Ʈ:
	- �ܺ� �ݺ��� �迭�� ���� �����ϴ� ���� �ƴϰ� index 0�� ���� �ʿ䰡 �����Ƿ� 4
		for (int i = 0; i < 4; i++) {
			for (int j = i+1; j < 5; j++) {
��: 
	- �ݺ��� ó���� �Լ��� ����ϸ� ������ ������ �ȹ�����Ƿ� ����
	- ȸ������ ���� ����ؼ� �̻��� ��� �ִ����� Ȯ���ϸ� ����
	- ������ �����̶�� �ݺ������� breakpoint�� �����ϰ� ����ȭ�� ���� �͵� ���� ���
*/