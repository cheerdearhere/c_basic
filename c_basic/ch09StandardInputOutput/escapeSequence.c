#include <stdio.h>
int main(void) {
	printf("%d\n",1234); 
	printf("%d, %d\n", 1234, -5678);
	printf("%+d, %+d\n", 1234, -5678);//��ȣ ǥ��

	printf("%8d\n", 1234);// 8ĭ ����
	printf("%08d\n", 1234);//8ĭ ������ 0���� ǥ��
	
	printf("%s\n","hello world");

	char text[20];
	int text_size = sizeof(text);
//  scanf_s(format, inputData, dataSize);
	scanf_s("%s", text, text_size);
	printf("-> %s\n", text);
	return 0;
}