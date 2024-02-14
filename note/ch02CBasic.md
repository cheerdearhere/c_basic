# I. ��� ������ ���ڿ� �����
## A. ��� ������ ����
- ���⼭ ���ڶ� �ҽ� �ڵ�
- ASCII �ڵ� ���� ���� �� �Ϻ�
	- a~z, A~Z, 0~9
	- white space(���鹮��): 
	   space(1ĭ), tab(4ĭ), enter(���� ����)...
	- escape sequence(\�� ���Ե�): 
		\nó�� ����� ó��
		"�� ���� ��� ���ڸ� �״�� ����ϰ� ������ \"
- �ѱ��� ASCII Code�� ������ ����. UTF-8������ �����ڵ� 
- �ּ��������� ��� ����
## B. �����
- C���� �����̳� ��� �� Ư���� �������� ���Ǵ� �ܾ��
- ���, �ڷ��� � ���

|auto|break|case|char|const|
|---|---|---|---|---|
|continue|default|do|double|else|
|enum|extern|float|for|goto|
|if|int|long|registeer|return|
|short|signed|sizeof|static|struct|
|switch|typedef|union|unsigned|void|
|volatile|while||||
|_Bool|_Complex|_Imagnary|Inline||

- ������ ���� ���� ������ �Ѿ

# II. ���� �̸� �ۼ� ��Ģ
- ���� ���� �ĺ���, Identifier.
	- ���� ��/�ҹ���, '_', ����		
	- �������� ù ���ڿ� ���ڴ� ��� �Ұ�
	- �̸� �߰��� ���鹮�� ��� �Ұ�: snake_case, camelCase
	- ����� ��� �Ұ�
	(������ʹ� �������)
	- �ʹ� �� �̸��� ��...
	- �ǹ̸� �� �� ���� �̸��� ��...
- �������� �����ϴ� ���α׷��Ӹ��� �ƴ� �̷��� �� �ڵ带 �ٽ� �� �ڽ��� ���ؼ��� �������� �����ش�
	- �޸��ּ� 232214���� ������ userAddr�� �б� ����

# III. ��, ��, ����, �Լ�
- ���డ���� �ڵ� ���: �Լ� 
- ���� �� ��, ���� �� ����, ������ �� �Լ��� �ȴ�
- ���ڷ� ���� ���(�ǿ�����, ����, ��� ��)
	- �Ұ�ȣ�� �̿��� ���� ���� �� ������ ����
- �װ� �����ڰ� �� ���� �ϼ�, �Ŀ� ���� ��(����)
- ���� �� ������ �ϼ��ϸ� ���� ������ �߰�ȣ�� ���� �� �ִ�. ������ ���� ;�� ���
- ���� ���� ������ �������� �����ϴ� ���� �Լ����Ѵ�
- ������ ����� ���Ƿ� �����ȴ�. 
	- ����: �̸��� �ڷ����� ����
	- ����(�ʱ�ȭ): �������� ��, �����ּ�, ����� ���� ����
```C
//����
int dNum; //�ڷ��� ������ ����
dNum = 3+2; //���� ����
int pNum = dNum++;//����� ���Ǹ� �ѹ��� ����
//�Լ�
//returnType	functionName(parameterList...)
	int			main		(void)
//{code block(function body)
//	return ��ȯ��;
//}
	{
		printf("hi"+pNum);
		return 0;
	}
```
- �������� ������ �Ʒ��� ���������� ����. 
```C
#include <stdio.h>

int main(void){//���� ������ ���� => �Լ�
	int nData; // nData��� �̸��� ������ integer�� �����Ѵ�(����)
	nData = 10; // nData(�ǿ�����)�� 10(���)�� ����(������)�Ѵ�(����)
}
```
- #include  : ��ó����. �������� �ϱ� ���� �����ϱ⶧���� ��κ� �ҽ��ڵ� �ֻ�ܿ� ����
- stdio     : standard Input Output. ǥ�� ����� �Լ� ���̺귯��
- *.h       : header ���� Ȯ����. ���� �ش��ϴ� �ڵ���� ����ִ� ����
- *.c       : c��� �ҽ����� Ȯ����

# IV. ���ڿ�
- Char[]
- "Hello,World" : �޸� �ּ�

|H|e|l|l|o|,|W|o|r|l|d|
|---|---|---|---|---|---|---|---|---|---|---|

# V. �ּ���
- �ּ�: ���α׷� �ҽ� �ڵ忡 �޸� ����� ����
- �ڵ忡�� ���Ե��� ���� = �����ϵ��� ����

|����|����|
|---|---|
|//|�� �� ��ü|
|/* ���� */|���� ��ü|
|Ctrl+k+c|�ּ� ����|
|Ctrl+k+u|�ּ� ����|

- �ڵ�� ���� ����, �ּ��� �� ������
- ���� �������� ���� �ڵ�� �ּ� ���̵� ������ �� �ִ� �ڵ�.
- ������ ���� �������� �ּ��� �ִ� ���� �� ����

# VI. �����
- ����� �����ϱ�
	- üũ�Ϸ��� ���� F9�� break point ó���ϱ�
	- F5�� ����׸�� ����
	- ����� > â > �޸� > 1(�޸�â ����)
	![����� �޸�](img/debug_memoryWindow.png)
	- �� �迭 ��������(64bit -> 8bit)
	- �ּҿ� ������ �Է��ϸ� ���ϴ� �޸𸮷� �̵�
	- F10���� �Լ� ���� ó�� ����: ��������� �ִ� ���� <b style="color:red">������</b>���� ǥ����
	- �Է� ���϶��� �ٸ� �ൿ�� �� �� ����: ����Ⱑ ���� ���� ������ ����� �� �����ϴ�.