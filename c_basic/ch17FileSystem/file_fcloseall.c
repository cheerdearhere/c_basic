#include <stdio.h>

int main(int argc, char* argv[]) {
	FILE* fp = NULL;
	int nClosed = 0;


	fopen_s(&fp, "Test.txt", "a");
	if (fp == NULL) {
		puts("ERROR: Failed to open file!");
		return;
	}
	//TODO: File I/O
	fprintf(fp, "%s\n", "World");

	fopen_s(&fp, "Test1.txt", "r"); 
	fopen_s(&fp, "Test2.txt", "r");
	fopen_s(&fp, "Test3.txt", "a");

	nClosed = _fcloseall();
	printf("%d개 프로세스를 닫습니다.\n",nClosed);
	return 0;
}