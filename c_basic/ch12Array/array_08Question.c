
#include <stdio.h>
#include <stdlib.h>
/*
for���� ����� int[5][5] �迭�� ������ ���� �����ϴ� ���α׷�(������ �迭
����
	1	2	3	4	5	
	16	17	18	19	6
	15	24	25	20	7
	14	23	22	21	8
	13	12	11	10	9
��
	- ���������� �����ϴ� ĭ���� ������ ����
	- ��� ���� �������� ����Ǵ� ��Ģ ã��
*/
int main() {
	int nArr[5][5] = { 0 };
	int innerNum = 0;

	// ���� ��ġ ���� �ʱ�ȭ
	int x = -1, y = 0;
	//���������� �����ϴ� ���� ���� ����
	int length;
	// �迭�� ä��� ����
	int direction = 1;

	//insert
//	���������� �����ϴ� ���� ���� : 9 > 7 > 5 > 3 > 1
	for (length = 9; length > 0; length -= 2) {
		//	���̸�ŭ ����
		for (int i = 0; i < length; i++) {
			//������ �߰��� = ����/2+1���� ���� ����
			if (i < (length / 2 + 1)) {
				//�߰��� �������� �迭�� x��ǥ �̵�
				x += direction;
			}
			else {
				//�߰��� ���Ŀ��� �迭�� y��ǥ �̵�
				y += direction;
			}
			//�ش� ��ġ�� �� ����
			nArr[y][x] = ++innerNum;
		}
		// ���� ����
		direction = -direction;
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
*/