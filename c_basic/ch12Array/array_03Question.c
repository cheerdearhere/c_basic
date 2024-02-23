#incluide <stdio.c>
/*
문제: for문을 사용해 int[5] 배열에 저장된 값들을 오름차순으로 정렬하는 프로그램
	선택정렬 알고리즘 사용
출력 예시
	 3 5 1 4 2 
	 정렬
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
오답노트:
팁: 
*/