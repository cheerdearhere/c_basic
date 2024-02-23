#include <stdio.h>
/*
문제:  for문을 사용해 int[5] 배열에 저장된 값들을 오름차순으로 정렬하는 프로그램
	퀵정렬 알고리즘 사용
출력 예시
	 3 5 1 4 2 
	 정렬
	 1 2 3 4 5
*/
void quickSort(int arr[], int left, int right) {
	if (left < right) {// 좌측 값과 우측값이 같아지면 return 
		int pivot = arr[left]; // 비교 기준 value
		int low = left + 1; // 비교 대상 index
		int high = right; // 비교 최대 index

		while (low <= high) {// 비교대상 이동
			// low가 오른쪽을 벗어나지 않고, low가 피벗보다 작거나 같은 동안 low를 이동
			while (low <= right && arr[low] <= pivot)
				low++;
			// high가 왼쪽을 벗어나지 않고, high가 피벗보다 크거나 같은 동안 high를 이동
			while (high >= (left + 1) && arr[high] >= pivot)
				high--;

			// low와 high가 교차하지 않았을 때
			if (low <= high) {
				// low와 high 위치의 요소를 교환
				int temp = arr[low];
				arr[low] = arr[high];
				arr[high] = temp;
			}
		}
		// 피벗을 올바른 위치로 이동
		int temp = arr[left];
		arr[left] = arr[high];
		arr[high] = temp;
		// 피벗을 기준으로 왼쪽과 오른쪽 부분 배열을 재귀적으로 정렬
		quickSort(arr, left, high - 1);
		quickSort(arr, high + 1, right);
	}
}
int main(void) {//정렬 전
	int nList[] = { 3,5,1,4,2 };
	int n = sizeof(nList) / sizeof(nList[0]);
	for (int i = 0; i < 5; i++)
		printf("%d\t", nList[i]);
	putchar('\n');

	quickSort(nList, 0, n - 1);
	printf("sort\n");

	//정렬 후
	for (int i = 0; i < 5; i++)
		printf("%d\t", nList[i]);
	putchar('\n');

	return 0;
}

/*
오답노트:
팁: 
*/