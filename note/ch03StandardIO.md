- computer
	- �� ���� ��ġ
		- CPU: ���� ���
		- RAM: ������ ���
	- �ֺ� ���
		- HDD
		- �ܺ� ������ġ
		- Input
			- Ű����
			- ���콺
			- ��ġ����...
		- Output
			- �׷���ó��
			- �����
			- ����Ŀ...
- Interrupt: �ֺ���⿡�� �߻��� ��ȣ. �̰��� ��ǻ���� �ֿ�����ġ�� ����
- �̷��� �߻��� ��ȣ�� ������ ���� ���� ó���ϴ� ���� OS
- Input/Output: ������ �Է�
	- HCI(Human Computer Interface): ����� ��ǻ�� ������ ������ ��ȯ�� ó���ϴ� ������
	- CLI(Command Line Interface): Ű����� �Է�
	- GRI(Graphical User Interfase): Ű����, ������ ���� ����� �Է�
- �Էµ� �����ʹ� I/O Buffer(Memory)���� <b>�� ���� ����</b>�� ó��
	- RAM�� �Ϻθ� ���ݾ� ���ҿ��� ���ȴ�. �� ���۴� �޸� �ȿ� �ӽ� ����� ����.

![ComputerLayer](img/computerLayer.png "��ǻ�� ����")

# I. Console

	User mode : client �κ�. �������Ʈ���� ��κ�. 
		device file(���� �����ϴ� ���α׷��� �߻�ȭ�� ����ڰ� ����ϵ����� �������̽�)�� 
		�������̽��� ���
	________________________________
	Kernel mode: �Էµ� ������ �ӽ÷� �����ߴٰ� ������ġ�� ����
	- ��ġ ����̹�, OS ��
S/W: kernel+user mode 
___
H/W: CPU + RAM + �ֺ����. �ֺ���� > RAM > CPU > RAM > �ֺ����...

- �ܼ�: ����ڰ� �̿��ϱ� ������ ���� HCI �� �ϳ�. ����� �������̽�

# II. char I/O
- getchar(), putchar: Buffered I/O, ���� ����� �޸��� ���� read�� write
	���ۿ� �־��ٰ� ����
```c
	char ch = 0; //���� ����, ����
	//char�� ���ڸ� �ǹ������� ���� ���� ���Ѵ�. ASCII code �ѹ�
	ch = getchar();//getchar(): ����ڰ� �Է��س��� I/OBuffer �� �� ���ڸ� �������� �Լ�
	//I/OBuffer�� Queue. FILO ������ ó�� ó���� ���� ���� ���� ����
	putchar(ch);//putchar(char character): �Ű������� ���� ���ڸ� IO ���ۿ� ����
	putchar('Z');
	return 0;
```
Ű���� �Է� > Ű���� ����̹� ������ ���� > Ű���� ���� �������̽� > I/O buffer�� ���� > �ܼ� �������̽��� ǥ�� > getchar()�� ���� ù �Է��� ���� > ���� char ch�� ����(�޸�) > putchar()�� ch�� ����� ���� IO buffer�� ����> �ܼ� �������̽��� '����ڰ� �Է��� ����' ǥ�� > putchar()�� IO buffer�� 'Z' ���� > �ܼ� �������̽��� '����ڰ� �Է��� ����'Z�� ǥ�õ�

- _getch(), _getche(): Non-burffered I/O, Ű���� �Է� ��ü�� ���� ����
	��ġ���� �ٷ� �Է¹���(�߰� ���۸� �Ȱ�ġ�� �ٷ� ���� �������̽�)
- ����� ������ ���α����� �ٸ�
```c
#include <conio.h>

int main(void) {
	char ch = 0;
	printf("�ƹ� Ű�� ������ �������� �Ѿ�ϴ�. \n");

	ch = _getch();//IO Buffer ���� �ٷ� �Է°� ������

	printf("�Է��� Ű�� ");
	putchar(ch);//���ۿ� ���
	printf("�Դϴ�\n");
	return 0;
}
```
- Ű���� �Է¿��� ���ڸ� üũ�� ��쿡�� ���۸� ����ϴ� �Լ���, 
	- ��� �����Ͻ÷��� 'y'�� ...
- "�ƹ�Ű�� �����ÿ�"ó�� Ű �Է¸� ����� ��쿡�� None-buffer �Լ� ���

# III. String I/O
- ���ڿ��� ��κ� Bufferred I/O�� ���
- ���ڿ��� ���� ���� null�� ������ ǥ��(String zero)
	- ���ܵ� ����
- �ϳ��� �����ö��� ���� �Լ��� 
	- char 
- ���� ������ ������ ���ڿ��� ���ڿ� �Լ��� ���
	- char[n] : �������� �迭... �߿�
	- �迭�� �����ؼ� ���� �ڷ����� �����Ͱ� �Էµ�
- �Լ� ����
	- �Է�
		- gets()   : ���� �̽��� ��� x
		- gets_s() : ������ �迭 read(std Input)
		- fgets()  : ������ �迭 read(���� �������̽� ���)
	- ���
		- puts()   : std Output
		- 
			- printf() :
			- scanf()  :
			- scanf_s():

- gets(), puts(): gets�� �����θ� ���� ��ť�� �ڵ��� �ͼ�������	
```c
// �迭�� ����� ����
//	�迭Ÿ�� �迭�̸�[�迭ũ��] = {�迭 ��� �ʱⰪ};
	char szName[32] = { 0 }; // 32ĭ�� ��� 0���� 

	printf("�̸��� �Է��ϼ��� : ");
	gets(szName);// gets(char *_Buffer)
	// gets()�� ���� ���� ������ ���� gets_s(char *_buffer, size_t_Size) ����

	printf("����� �̸��� ");
	puts(szName); // ��� �� �ڵ� �����
	printf("�Դϴ�.");
```
- char * : character pointer - ���ڰ� ����� �޸��� ���� �ּ�

# IV. gets() �Լ��� ���� ����(��ť�� �ڵ�)
## A. gets() �Լ��� ���� ����
- param���� �޸� �ּҸ� ���� 
	- but �󸶳� �ᵵ �Ǵ��� ũ�� Ȯ���� �ȵ�(�������̸� �޴� ���� �迭. �޸𸮴� ��������)
- �޸��� ��踦 ��� ���⸦ ������ �� ����(�����̽�)
	- overflow: ��踦 ��� ���� 
		- �̻� �������� �̾��� 
		- �ɰ��� ������Ȳ�� �߻�
		- ������ ���� ���Ⱑ �Ͼ ���� ������ �Ͼ �� ����
		![�����÷ο�](img/overflow.png)
- ���� ������ �߻����� �ʵ��� �ڵ� ���ؿ����� ������ �߿�(��ť�� �ڵ� �ʿ�)
	- ��Ⱥ� ���๰
		- [��ť�� �ڵ�(C, Java)](https://www.mois.go.kr/frt/bbs/type001/commonSelectBoardArticle.do%3Bjsessionid=fr7QaTyG2gK5o02XJnYETp3havIQ1MGLKMYdWaaEe5me9IOk932SIy2BbP1AM08Z.mopwas54_servlet_engine1?bbsId=BBSMSTR_000000000012&nttId=42152) 
		- [����Ʈ���� ���ߺ��� ���̵�](https://www.mois.go.kr/frt/bbs/type001/commonSelectBoardArticle.do;jsessionid=TjAX2IwVk6hpONx8dKSZ4VTj.node10?bbsId=BBSMSTR_000000000015&nttId=88956)
## B. ��ť�� �ڵ� ����
- gets_s(char *_buffer, sizeof(��� ���ڹ迭)): ������
- fgets(char *_buffer): ������
- ���̸� ����� �ߴ� ��Ŵ
```c
	char szBuffer[8] = { 0 };

//	gets(szBuffer);// ������Ʈ ���� > ���� �Ӽ� > C/C++ > SDL üũ false(���Ȱ˻�x)
//  gets_s(char*_buffer, rsize_t_Size): ������ ���
//		sizeof(�迭) > �迭�� ũ��	
	gets_s(szBuffer,sizeof(szBuffer));
// fgets(char *_buffer, int *_maxCount, File *_Stream): ������ ���
	fgets(szBuffer, sizeof(szBuffer), stdin);
	puts(szBuffer);

	return 0;
```
# V. ���� ���ڿ� �̽������� ������
# VI. �Ǽ� ���
# VII. ����, ���� �Է°� ���๮�� ����
# IX. ���� ���� ��� ���ڿ� �Է�
[���� �ڵ�](../c_basic/ch09StandardInputOutput)
# X. �ǽ�����