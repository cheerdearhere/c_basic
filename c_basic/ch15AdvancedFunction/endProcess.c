#include <stdio.h>
void EndProtocol(void) {
	char ch;
	printf("Do you want to EXIT? (Y/N)\n");
	ch = _getch();
	if (ch == 'y' || ch == 'Y') {
		puts("EXIT");
		exit(1);//즉시 종료
	}
	puts("End of main()");
}