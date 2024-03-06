#include <stdio.h>
int main(int argc, char* argv[])
{
	FILE* filePointer = NULL;
	char ch;

	fopen_s(&filePointer, "Test.txt", "w");
	fputs("Test string!!", filePointer);
	fclose(filePointer);

	fopen_s(&filePointer, "Test.txt", "r");
	if (filePointer == NULL)return;
	while ((ch = fgetc(filePointer)) != EOF) {
		putchar(ch);
	}
	fclose(filePointer);
	return 0;
}