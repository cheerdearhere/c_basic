#incluide <stdio.c>
/*
����: ����ڷκ��� �� ������ �Է¹޾� �ִ밪�� ��ȯ�ϴ� ���α׷�
���ѻ���
	����� �Է°� �ִ� ��� �ڵ带 ���� �Լ��� �и�
��¿���
	(�Է��� �����Ӱ�, ����� ģȭ������)
	MAX: 5
�ۼ� ��
	�Լ� �������� �����غ���
	�Լ� ����(�Լ� �ñ״�ó): 
		returnType methodName(parameterType paramterName, ...)
*/
int CalcMax(int a, int b, int c) {
	int nMax = a;
	if (b > nMax) nMax = b;
	if (c > nMax) nMax = c;

	return nMax;
}
void GetMax(void) {
	int a, b, c;
	puts("�� ������ �Է����ּ���(a b c): ");
	scanf_s("%d%d%d",&a,&b,&c);
	printf("MAX: %d\n", CalcMax(a, b, c));
}
int main(void) {
	
	GetMax();

	return 0;
}
/*
�����Ʈ:
��: 
*/