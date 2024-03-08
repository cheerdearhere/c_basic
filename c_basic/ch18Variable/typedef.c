#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned int  UINT;
typedef const char* LPSTR;

int main(int argc, char* argv[]) {

	UINT uData = 10;
	printf("%u\n", uData);

	LPSTR pszData = NULL;
	pszData = "Hello world";
	printf("%s\n", pszData);
	printf("%p\n", pszData);

	return 0;
}