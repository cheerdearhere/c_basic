#include <stdio.h>
typedef struct USERDATA {
	char szName[32];
	char szPhone[32];
} USERDATA;

int main(int argc, char* argv[]) {
	FILE* fp = NULL;
	USERDATA UserData[3] = {
		{"Hong-gil","010-0000-0000"},
		{"Kong-gil","010-1111-0000"},
		{"Jong-gil","010-2222-0000"}
	};

	fopen_s(&fp, "Test.dat", "wb");
	if (fp == NULL) return;
	//fwrite(Buffer, ElementSize, ElementCount,FILE)
	fwrite(&UserData, sizeof(USERDATA), 1, fp);
	fwrite(&UserData[1], sizeof(USERDATA), 1, fp);
	fwrite(&UserData[2], sizeof(USERDATA), 1, fp);
	fclose(fp);

	memset(&UserData[0], 0, sizeof(UserData));
	fp = NULL;
	fopen_s(&fp, "Test.dat", "rb");
	if (fp == NULL) return;
	//fread(Buffer, size, count, fileStructPointer);
	int it = sizeof(UserData) / sizeof(USERDATA);

	for (int i = 0; i < it; i++) {
		puts("=====");
		fread(&UserData[i], sizeof(USERDATA), 1, fp);
		puts(UserData[i].szName);
		puts(UserData[i].szPhone);
	}

	fclose(fp);
	return 0;
}



