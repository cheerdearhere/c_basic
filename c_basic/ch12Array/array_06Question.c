#include <stdio.h>
#include <stdlib.h>
/*
for���� ����� int[5][5] �迭�� ������ ���� �����ϴ� ���α׷�
����
1	2	3	4	5
6	7	8	9	10
11	12	13	14	15
16	17	18	19	20
21	22	23	24	25
*/
int main() {
	int nArr[5][5] = { 0 };
	int innerNum = 0;
	//insert
	for (int i = 0; i < _countof(nArr); i++) {
		for (int j = 0; j < _countof(nArr[i]); j++) {
			nArr[i][j] = ++innerNum;
		}
	}
	//print
	for (int i = 0; i < _countof(nArr); i++) {
		for (int j = 0; j < _countof(nArr[i]); j++) {
			printf("%d\t", nArr[i][j]);
		}
		putchar('\n');
	}
	return 0;
}
/*
�����Ʈ:
��: 
	- �Ӹ��� �����ǰ� ���� �ڵ��� �ض�
	- �켱 �� ������ �ϰ� �� ����� �ڵ�� �ű�� ��
		- �� �׸��� �� ��� ������ ����
		- �ڵ�� �� ����ϻ�

*/