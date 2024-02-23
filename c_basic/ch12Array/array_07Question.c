#include <stdio.h>
#include <stdlib.h>
/*
for���� ����� int[5][5] �迭�� ������ ���� �����ϴ� ���α׷�
����
	1	2	3	4	5
	10	9	8	7	6
	11	12	13	14	15
	20	19	18	17	16
	21	22	23	24	25
��
	�࿡ ���� �ִ� ������ �ٸ������� ������ ���� �������� ���
*/
int main() {
	int nArr[5][5] = { 0 };
	int innerNum = 0;
	//insert
	for (int i = 0; i < _countof(nArr); i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < _countof(nArr); j++) {
				nArr[i][j] = ++innerNum;
			}
		}
		else {
			for (int j = _countof(nArr) - 1; j >= 0; j--) {
				nArr[i][j] = ++innerNum;
			}
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
	- for���� 2���� ���⺸�� ���������� ���� �� ������ �� �� �ִ�
		for (int i = 0; i < _countof(nArr); i++) {
			for (int j = 0; j < _countof(nArr); j++) {
				if (i % 2 == 0) {
					nArr[i][j] = ++innerNum;
				}
				else{
					nArr[i][4 - j] = ++innerNum;
				}
			}
		}
	- ���� ���ڰ��� ����ؼ� �ص� �۵��߰����� ����...
	- if (i % 2 == 0)�� �κ��� flag�� ó���ؼ� ����� ���� �ִ�
		int flag = 1;
		...�߰� ����
		for (int i = 0; i < _countof(nArr); i++) {
			for (int j = 0; j < _countof(nArr); j++) {
				if (flag) {
					nArr[i][j] = ++innerNum;
				}
				else{
					nArr[i][4 - j] = ++innerNum;
				}
				flag = !flag;
			}
		}
*/