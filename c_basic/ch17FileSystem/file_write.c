#include <stdio.h>

int main(int argc, char* argv[]) {
	FILE* fp = NULL;
	fopen_s(&fp, "Test.txt", "a");
	if (fp == NULL) {
		puts("ERROR: Failed to open file!");
		return;
	}
	//TODO: File I/O
//	fprintf(fp, "%s\n", "Hello!!!");
	fprintf(fp,"%s\n","World");



	fclose(fp);
}