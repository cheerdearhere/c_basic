#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	FILE* fp = NULL;
	char szBuffer[512] = { 0 };

	fopen_s(&fp, "Test.txt", "w");
	fputs("Test\n", fp);
	fputs("String\n", fp);
	fputs("Data\n",fp);
	fclose(fp);
	
	fopen_s(&fp, "Test.txt", "r");
	if (fp == NULL) return;

	while (fgets(szBuffer, sizeof(szBuffer), fp)) {
		printf("%s", szBuffer);
		memset(szBuffer, 0, sizeof(szBuffer));
	}
	
	fopen_s(&fp, "CON", "w");
	//standard output
	fputs("Hellow World and CON\n", fp);
	puts("Hellow World and CON");
	fputs("Hellow World and CON\n", stdout);
	//standard input
	fgets(szBuffer, sizeof(szBuffer),stdin);
	fputs(szBuffer,stdout);
	printf("Á¾·á: %d", _fcloseall());
	
	
	int nData = 0;
	//fprintf
	fopen_s(&fp, "fscanfTest.txt", "w");
	fprintf(fp, "%d,%s\n", 20, "Test");	
	fclose(fp);

	//fscanf_s
	fopen_s(&fp, "fscanfTest.txt", "r");
	fscanf_s(fp, "%d,%s",
		&nData,
		szBuffer,
		(unsigned)_countof(szBuffer)
	);
	fclose(fp);
	
	printf("%d, %s", nData, szBuffer);

	return 0;
}