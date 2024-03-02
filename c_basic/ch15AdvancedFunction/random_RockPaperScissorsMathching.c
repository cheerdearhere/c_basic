#include <stdio.h> 
#include <string.h>
#include <time.h>


int ComputerUser(void) {
	srand((unsigned)time(NULL));
	return (rand() % 3) + 1;
}

/**
* ����(1) ����(2) ��(3)
* ���� ��: 2/ ���º�: 1/ ���� �� 0 / 3 �߸����� �й�/ 4 ����
*/
int RockPaperScissors(int user) {
	int nResult = 0;
	int com = 0;
	char* entry[3] = { "����","����","��" };

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
		"����� �й��Դϴ�.",
		"���º��Դϴ�. ",
		"����� �¸��Դϴ�. ",
		"�߸������Ƿ� ����� �й��Դϴ�. ",
		"1���� ���� �� �Դϴ�. �ý����� �����մϴ�. "
	};

	do {
		printf("#### ����(1) ����(2) ��(3): \n\t1���� ������ ����\n�Է�: ");
		scanf_s("%d", &nInput);

		printf("%s\n", szResult[RockPaperScissors(nInput)]);
	} while (nInput > 0);

	return 0;
}
