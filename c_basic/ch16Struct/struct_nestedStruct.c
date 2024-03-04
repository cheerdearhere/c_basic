#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct MYBODY {
	int nHeight;
	int nWeight;
} MYBODY;

typedef struct USERDATA {
	int nAge;
	char szName[32];
	char szPhone[32];
	MYBODY bodySize;
} USERDATA;

int main(int argc, char* argv[]) {

	USERDATA user = {
		18,
		"Hone",
		"010-1234-1234",
		{176, 70}
	};
	printf("이름: %s, 나이: %d, 연락처: %s\n h-w: %d - %d\n",
		user.szName,
		user.nAge,
		user.szPhone,
		user.bodySize.nHeight,
		user.bodySize.nWeight
	);

	return 0;
}
