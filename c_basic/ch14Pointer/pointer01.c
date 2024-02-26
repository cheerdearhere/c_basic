#include <stdio.h>
int main(void) {
	int nData = 10;
	printf("%s\n", "nData");

	printf("%d\n", nData);
	printf("%p\n", &nData);

	char ch = 'A';
	char* pszData = &ch;
	printf("ch : %d\n", ch, sizeof(ch));
	printf("pszData : %p\n", *pszData, (int)sizeof(*pszData));

	int x = 10;
	int* pnData = &x;
	printf("x: %d\n", x);
	*pnData = 20;
	printf("x: %d\n", x);
	return 0;
}
