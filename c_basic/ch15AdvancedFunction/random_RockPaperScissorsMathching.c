#include <stdio.h> 
#include <string.h>
#include <time.h>


int ComputerUser(void) {
	srand((unsigned)time(NULL));
	return (rand() % 3) + 1;
}

/**
* 가위(1) 바위(2) 보(3)
* 유저 승: 2/ 무승부: 1/ 유저 패 0 / 3 잘못내서 패배/ 4 종료
*/
int RockPaperScissors(int user) {
	int nResult = 0;
	int com = 0;
	char* entry[3] = { "가위","바위","보" };

	// mistake
	if (user > 3) return 3;

	//exit
	if (user < 1) return 4;

	com = ComputerUser();
	printf("u: %s\t", entry[user - 1]);
	nResult = com - user;
	printf("c: %s\n", entry[com - 1]);

	switch (nResult)
	{
	case -1:
	case 2:
		return 2;
	case 0:
		return 1;
	default:
		return 0;
	}
}

int main(int argc, char* argv[]) {
	int nInput = 0;
	char* szResult[5] = {
		"당신의 패배입니다.",
		"무승부입니다. ",
		"당신의 승리입니다. ",
		"잘못냈으므로 당신의 패배입니다. ",
		"1보다 작은 수 입니다. 시스템을 종료합니다. "
	};

	do {
		printf("#### 가위(1) 바위(2) 보(3): \n\t1보다 작으면 종료\n입력: ");
		scanf_s("%d", &nInput);

		printf("%s\n", szResult[RockPaperScissors(nInput)]);
	} while (nInput > 0);

	return 0;
}
