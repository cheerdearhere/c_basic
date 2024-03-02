#include <stdio.h>

int GetInteger(void) {
	int nResult = 0;
	char szBuffer[32];

	printf("Input string: ");
	gets_s(szBuffer, sizeof(szBuffer));

	nResult = atoi(szBuffer);
	return nResult;
}

int main(int argc, char* argv[]) {

	printf("call Get Integer: %d\n", GetInteger());


	printf("1234567890: %d\n", atoi("2147483647"));
	printf("1234567890: %d\n", atoi("2147483648"));
	printf("1.7e+308: %e\n", atof("1.7e+308"));
	printf("1.7e+309: %e\n", atof("1.7e+309"));

	return 0;
}
