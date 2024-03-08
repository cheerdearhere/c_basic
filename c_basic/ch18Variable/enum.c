#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum ACTION {MOVE, JUMP, ATTACK};//index 수로 사용
typedef enum COLOR_CODE {RED = 100, GREEN, BLUE} COLOR;// seed를 100으로 지정, GREEN = 101

void DoAction(enum ACTION act) {
	switch (act)
	{
	case MOVE:
		printf("move(%d)\n",act);
		break;
	case JUMP:
		printf("jump(%d)\n", act);
		break;
	case ATTACK:
		printf("attack(%d)\n", act);
		break;
	default:
		break;
	}
}

int main(int argc, char* argv[]) {
	enum ACTION act = MOVE;
	COLOR color = BLUE;

	DoAction(act);
	act = ATTACK;
	DoAction(act);
	printf("blue: %d\n", color);

	return 0;
}