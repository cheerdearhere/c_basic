#incluide <stdio.c>
/*
문제: for문을 사용해 int[5] 배열에 저장된 값들을 오름 차순으로 정렬하는 프로그램
제한사항
	버블정렬 알고리즘 사용
출력 예시
	 50 40 10 50 20
	 정렬
	 10 20 40 50 50
	 3 5 1 4 2 
	 정렬
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
오답노트:
	- 외부 반복은 배열에 직접 관여하는 것이 아니고 index 0는 비교할 필요가 없으므로 4
		for (int i = 0; i < 4; i++) {
			for (int j = i+1; j < 5; j++) {
팁: 
	- 반복된 처리는 함수를 사용하면 좋으나 아직은 안배웠으므로 진행
	- 회차마다 값을 출력해서 이상이 어디에 있는지를 확인하면 편함
	- 복잡한 로직이라면 반복문에서 breakpoint를 지정하고 값변화를 보는 것도 좋은 방법
*/