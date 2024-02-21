#include <stdio.h>

int main(void) {
	char ch = 0;
	while (1) {
		ch = getchar();
		if (ch == 'x')
			break; //여기서 스코프를 나가기때문에
		putchar(ch); //이 부분을 수행하지 않음
	}
	puts("END");
	return 0;
}