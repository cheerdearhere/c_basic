#include <stdio.h>
#include <conio.h>

int main(void) {
	char ch = 0;
	printf("아무 키나 누르면 다음으로 넘어갑니다. \n");

	ch = _getch();//Scanner(System.in)

	printf("입력한 키는 ");
	putchar(ch);//버퍼에 출력
	printf("입니다\n");
	return 0;
}