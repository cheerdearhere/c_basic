#include <stdio.h>
int main(void) {

	int nInput = 0;
	char ch;
	scanf_s("%d", &nInput);

	if (nInput >= 80) {
		if (nInput >= 90)
			ch = 'A';
		else
			ch = 'B';
	}
	else {
		if (nInput >= 70)
			ch = 'C';
		else {
			if (nInput < 60)
				ch = 'F';
		}
	}

	printf("당신의 학점: %c\n", ch);
	return 0;
}