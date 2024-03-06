#include <stdio.h>

int main(void) {
	FILE* fp = NULL;
	fopen_s(&fp, "CON", "r"); //stdin
//	fopen_s(&fp, "CON", "w"); //stdout

	char szBuffer[32] = { 0 };
	fgets(szBuffer, sizeof(szBuffer), fp);
	fputs(szBuffer, stdout);
	fflush(stdout);

	fclose(fp);
	return 0;
}