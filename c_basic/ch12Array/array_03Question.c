#incluide <stdio.c>
/*
����: for���� ����� int[5] �迭�� ����� ������ ������������ �����ϴ� ���α׷�
	�������� �˰��� ���
��� ����
	 3 5 1 4 2 
	 ����
	 1 2 3 4 5
*/
int main(void) {

	int nList[] = { 30,50,10,40,20 };

	for (int i = 0; i < 5; i++)
		printf("%d\t", nList[i]);
	putchar('\n');

	int idxMin = 0;
	for (int i = 0; i < 4; i++) {
		idxMin = i;
		for (int j = i + 1; j < 5; j++) {
			if (nList[i] > nList[j])
				idxMin = j;
		}
		if (idxMin != i) {
			int temp = nList[i];
			nList[i] = nList[idxMin];
			nList[idxMin] = temp;
		}
		//print
		for (int j = 0; j < 5; j++)
			printf("%d\t", nList[j]);
		putchar('\n');
	}
	printf("sort\n");
	for (int i = 0; i < 5; i++)
		printf("%d\t", nList[i]);
	putchar('\n');

	return 0;
}
/*
�����Ʈ:
��: 
*/