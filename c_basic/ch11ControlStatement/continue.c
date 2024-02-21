#include <stdio.h>
int main(void) {
	char ch = 0;
	while (1) {
		ch = getchar();
		if (ch == 'x')
			continue; //여기서 해당 회차 스코프를 나가기때문에
		//다음회차로
		putchar(ch); //이 부분을 수행하지 않음
	}
	puts("END");
	return 0;
}