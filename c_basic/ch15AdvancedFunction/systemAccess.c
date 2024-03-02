#include <stdio.h>
void AccessSysemtModule(void) {
	char szCommand[512] = { 0 };
	printf("Input command: ");
	gets_s(szCommand, sizeof(szCommand));

	system(szCommand);
	//system("notepad.exe");
}