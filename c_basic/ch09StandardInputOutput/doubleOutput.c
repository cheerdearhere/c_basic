#include <stdio.h>
int main(void) {
// �Ǽ� �ڷ� ������ �޸� ũ��(����Ʈ ����) ���
	printf("float size: %d\n", (int)sizeof(123.456F));
	printf("double size: %d\n", (int)sizeof(123.456));
// float ������ �Ǽ� �������� ���
	printf("F: %f\n", 123.456F); // float
// double ������ �Ǽ� �������� ���
	printf("D: %f\n", 123.456); // double
	printf("LD: %lf\n", 123.456); // long double
	printf("G: %g\n", 123.456); // long double
// �Ҽ��� ���� �ݿø�
	double dData = 123.456;
	printf("%f, %f\n", dData, -123.456);
	//�Ҽ��� 2��° �ڸ����� �ݿø��ؼ� 1�ڸ����� ���
	printf("%.1f\n", dData);
	//�Ҽ��� 3��° �ڸ����� �ݿø��ؼ� 2�ڸ����� ���
	printf("%.2f\n", dData);
	//�Ҽ��� 4��° �ڸ����� �ݿø��ؼ� 3�ڸ����� ���
	printf("%.3f\n", dData);

	printf("%8d\n", 123);

//	����: �Ҽ����� ������ 12�ڸ��� ���. �� �Ҽ��� ���� 4��° �ڸ����� �ݿø��ϰ� 3�ڸ����� ����Ѵ�
	printf("%12.3f\n", dData);
	printf("%012.4f\n", dData);
	return 0;
}