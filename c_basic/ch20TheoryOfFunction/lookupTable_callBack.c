#include <stdio.h>

typedef enum _user_action {MOVE, JUMP, ATTACK, QUIT} ACTION;

int DoMove(int nParam){
	printf("DoMove: %d\n",nParam);
	return 0;
}
int DoJump(int nParam){
	printf("DoJump: %d\n", nParam);
	return 0;
}
int DoAttack(int nParam){
	printf("DoAttack: %d\n", nParam);
	return 0;
}

int GetInputFromClient(void) {
	int nInput = 0;
	puts("[0: move]\t[1: jump]\t[2: attack]\t[3: quit]");
	scanf_s("%d", &nInput);
	if (nInput < 0 || nInput > 3) {
		puts("�߸��� �Է����� �����մϴ�. ");
		nInput = 3;
	}
	return nInput;
}

int main(int argc, char* argv[]) {
	// �Լ��� �迭(lookup table)
	int (*functionArray[3])(int) = {
		DoMove,	DoJump, DoAttack
	};
	ACTION act = 0;
	while ((act = GetInputFromClient()) != QUIT) {
//		switch-case
		//switch (act)
		//{
		//case MOVE: 
		//	functionArray[MOVE](act);
		//	break;
		//case JUMP: 
		//	functionArray[JUMP](act);
		//	break;
		//case ATTACK:
		//	functionArray[ATTACK](act);
		//	break;
		//default:
		//	break;
		//}
//		lookup
		functionArray[act](act);
	}
	puts("�ý����� �����մϴ�.");
	
	return 0;
}