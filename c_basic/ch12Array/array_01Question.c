#incluide <stdio.c>
/*
문제: for문을 사용해 int[5] 배열에 저장된 값 중 가장 큰 값을 찾아 출력하는 프로그램을 작성
그후 가장 작은 값을 찾아 출력, int[0]에 최소값이 저장되도록함. 배열 요소의 값이 사라지지 않도록 교환
제한사항
	int nMax 사용
출력예시
	50 40 10 50 20
	MAX: 50
	MIN: 10
	10 40 50 50 20
*/
int main(void) {
	//init
	int nMax = 0;
	int nMin = 0;
	int nArray[5] = { 0 };// = { 50, 40, 10, 50, 20 };//입력 안받을때

	//input
	for (int i = 0; i < _countof(nArray); i++) {
		scanf_s("%d", &nArray[i]);//입력 받을때
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
오답노트:
	- 배열이 음수로 이뤄진 경우 첫 초기값인 0이 max로나오는 에러
		- 최대값 최소값을 사용할때 기준값을 미리 넣고 순회를 줄이는 방법 사용
	max = nArray[0];
	for(int i = 1; i < 5 ; i++){...
팁: 
	- 빌드는 중간중간에 해서 컴파일 에러를 조금씩 잡아가자

*/