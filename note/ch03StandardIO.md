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
	- ��Ÿ �����: ���Ŀ� ���� ���
		- printf() 
		- scanf()  
		- scanf_s()

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
## A. printf
- printf(params...) : print format. 
	- ��Ŀ� ���缭 ������ ������ ���
	- parameter: �Ű������� ���� ���� 

```c
	int x = 10;

// ���� ����� ȭ�鿡 ���
	putchar('B');
// '\n'�� ���� �����̹Ƿ� ���ĺ� ���ڰ� ȭ�鿡 ���̴� ���� �ƴϴ�
	putchar('\n');
	printf("%c\n", 'A');
// '%d', '%c'�� ���� ���ڿ� ���� ���� x�� ��� ������ ����Ѵ�
		// printf(format, variable)
	printf("x�� %d �Դϴ�.", x);
```
## B. format character(���� ����)
- �Է¹��� ���� ������ ǥ��. 
- format�� ����ϴ� �Լ��鿡�� ���������� �����ؼ� ó��

|���Ĺ���|�ڷ���|ǥ��|
|---|---|---|
|%c|int/char|character|
|%d|int|integer|
|%o|int|integer(8����)|
|%x, %X|int|integer(16����)|
|%f|double|float|
|%s|char[]|string|
|%u|Unsigned|unsigned integer|
|%e, %E|log|log10|
|%g|double|double|
|%zd|size_t|check size|
|%lld|long|long long integer(64��Ʈ)|
|%l64u|||

## C. escape sequence
- �齽����(\) �ڿ� �� ���ڳ� ���� ������ ���� ���� ����
- �Ϻ� �ܿ��� ���� ���ȵ�. �ܿ� �ʿ� ���� �ִ� ������ ����ϰ� �˻��� ���

|����|�ǹ�|����|
|---|---|---|
|\a|alert|�����|
|\n|new line|���ο� �ٿ��� ����(����)|
|\r|carriage return|Ŀ���� ���� ������ �̵�(���� ���)|
|\b|backspace|Ű������ backspace ���|
|\f|form feed|Ŀ���� ���� �������� ���ۺκ����� �ѱ�|
|\t|tab|Ű������ tab ���|
|\v|vertical tab|�������� tab ���|
|\o����|8����|10������ �����ϱ� ���� ���|
|\x����|16����|10����, ���ڿ��� �����ϱ� ���� ���|
|\\|\ | \�� ���ڷ� ���|
|\?|?|?�� ���ڷ� ���|
|\'|'|'�� ���ڷ� ���|
|\"|"|"�� ���ڷ� ���|

```c
	printf("%d\n",1234); 
	printf("%d, %d\n", 1234, -5678);

	printf("%+d, %+d\n", 1234, -5678); // ��ȣ ǥ��

	printf("%8d\n", 1234);  // 8ĭ ����
	printf("%08d\n", 1234); // 8ĭ ������ 0���� ǥ��
```

## D. �Ǽ� ���
- �����Ͱ� �����ϴ� �޸� ũ�� �� 
unsigned_int sizeof(data); > data�� �ڷ�ũ��
	- float : 4 ����Ʈ
	- double: 8����Ʈ
```c
//int�� �� ��ȯ
	printf("float size: %d\n", (int)sizeof(123.456F));
	printf("double size: %d\n", (int)sizeof(123.456));
```
float�� �ڷ����� ũ�Ⱑ �۾� �Ҽ��� 6�ڸ����� ������ �߻��� �� ����
```c
// float ������ �Ǽ� �������� ���
	printf("F: %f\n", 123.456F); // float
// double ������ �Ǽ� �������� ���
	printf("D: %f\n", 123.456); // double
	printf("LD: %lf\n", 123.456); // long double
	printf("G: %g\n", 123.456); // long double
```
�ܼ�â
```dockerfile
float size: 4
double size: 8
F: 123.456001
D: 123.456000
LD: 123.456000
G: 123.456
```
�Ҽ��� ó���ϱ�
```c
double dData = 123.456;
printf("%f, %f\n", dData, -123.456);
//�Ҽ��� 2��° �ڸ����� �ݿø��ؼ� 1�ڸ����� ���
printf("%.1f\n", dData);
//�Ҽ��� 3��° �ڸ����� �ݿø��ؼ� 2�ڸ����� ���
printf("%.2f\n", dData);
//�Ҽ��� 4��° �ڸ����� �ݿø��ؼ� 3�ڸ����� ���
printf("%.3f\n", dData);

printf("%8d\n", 123);
```
�ܼ�â
```dockerfile
123.5
123.46
123.456
     123
```
������� �ѹ���
```c
// �Ҽ����� ������ 12�ڸ��� ���. �� �Ҽ��� ���� 4��° �ڸ����� �ݿø��ϰ� 3�ڸ����� ����Ѵ�
printf("%12.3f\n", dData);
printf("%012.4f\n", dData);// ���̿� �� �ڸ��� 0���� ǥ��
```
�ܼ�â
```dockerfile
     123.456
0000123.4560
```
# VI. ����, ���� �Է°� ���๮�� ����
## A. scanf(scanf_s)
- scanf()  : scan format
	- ��Ŀ� ���缭 ������ ������ �Է�
- scanf_s(): ���� �̽��� �̰� ���
### 1. �� scan?
- Ű���带 �������� key Input�� �Ͼ�� �� ���� scan code��� �߱⶧���� �׷��� ������(���� ����)?
- �ϵ����� �����縶�� scan code ���� �ٸ��ٺ��� ��Ģ�� ���� -> Virtual key code -> keycode(javascript event listener)
### 2. scanf�� ���� ��������
�Է��� ���� ���๮��(\n)

���� ����	: %c
buffer		: 

|a|b|c|\n|||| 
|---|
> �� �� ó�� ����(FIFO) ���� ��� 

���� ����	: %c%*c
buffer		: 

|a|\n|1|2|3||||
|---|
> \* : ���ۿ� �Էµ� �� �� �ϳ��� ����

> %c�� ó�� �Է¹��� a�� �ް��� \n�� ���´�. 
�̶� ���۸� �д� �Լ��� ���� �ϸ� \n�� ���� �̹� �Էµ� ������ �νĵȴ�. 
�̶� '%*���Ĺ���'�� ��������� �Է��� ���� \n�� ���������ʰ� ���Եȴ�.
���������� �Է¹޴� ��� �̰��� �� �־� ���۸� ������ ����� �۵���.

���� ����	: %d\n
buffer		: 

|1|\n||||
|---|
> ���� �Է��ϰ� enter�� ġ�� ���๮�ڰ� �ԷµǴ� ���� �ƴ� ���Ĺ��ڿ� �ִ� \n�� ���� ������ �����Ѵ�. 
�׷��� ������ �ٸ� �����Ͱ� �ԷµǾ�� read�� �Ϸ�ȴ�
```c
int i = 0;
scanf_s("%d\n",&i); //enter�� �ȸ���
printf("%d\n",i);
```

scanf_s(format, reffernce, size);
&variableName : ������ ����Ǿ��ִ� �޸��ּ� 
### 3. ����غ���
- �� ���� �ޱ�
```c
	char ch = 0;
	scanf_s("%c", &ch, 1);
//	scan_s(����Ÿ��, ch�� ����� �����ּ�, ���� �޸� ��);
	printf("�Է��� ���ڴ� %c�Դϴ�.\n", ch);
```

- ���� ������ �ޱ�
	- '%*���Ĺ���'�� ����� ���ۿ� �Էµ� \n �����
```c
	char name[32] = { 0 };
	int nAge = 0;

	printf("���̸� �Է��ϼ��� : ");
	scanf_s("%d%*c", &nAge);

	printf("�̸��� �Է��ϼ���: ");
	gets_s(name, sizeof(name));

	printf("����: %d��, �̸�: %s", nAge, name);
```
- �� ���� �ޱ�
	- �ѹ��� ���� ���� �޴� ��� ���� ���� ���̿� ������ ���� �ʴ´�. 
	- ���� ���������� �޼����� ��ĵ�� �̷����°� �Ϲ����̶� ���� �������� �ʴ´�. 
```c
	int x = 0, y = 0;

	printf("�� ������ �Է��ϼ���");
	scanf_s("%d%d", &x, &y);

	printf("�� ���� ���� %d �Դϴ�\n", x + y);
```

# VII. ���� ���� ��� ���ڿ� �Է�
�迭�� �� ��ü�� ���� �ּҸ� ���⶧���� &�� ������ �ʾƵ� �ȴ�. 
gets�� \n�� ������ ������ scanf�� ���鹮�ڸ� ������ ����. 
gets�� ���Ⱑ ������ scanf�� �ƴ�
- ���� ���� �ޱ�
	- _countof(variable): ������ ����
	- sizeof(variable): ������ ũ��
	- �޸𸮸� �����ؼ� ���� ���ؿ� ������ �ȴ�. 
```c
	char szBuffer[4] = {0};
	scanf_s("%4c", szBuffer, (unsigned)_countof(szBuffer));
	printf("%c%c%c%c\n",szBuffer[0], szBuffer[1], szBuffer[2], szBuffer[3]);
```
- �׳� s�� ���� ���ڿ��� ���
```c
	char szBuffer[50] = {0};
	scanf_s("%s", szBuffer, (unsigned)_countof(szBuffer));
	printf("%s\n",szBuffer);
```
- sizeof�� ���
```c
	char text[20];
	int text_size = sizeof(text);
//  scanf_s(format, reference, dataSize);
	scanf_s("%s", text, text_size);
	printf("-> %s\n", text);
```

- �ܼ��� ���� ������

[���� �ڵ�](../c_basic/ch09StandardInputOutput)
# IX. �ǽ�����
```dockerfile
����ڷκ��� �̸��� ���̸� Ű����� �Է¹޾� ����ϴ� ���α׷�
�̸��� gets_s, ���̴� scanf_s �Լ��� �Է¹ް�
printf �Լ��� ���
���� ����
	���̸� �Է��ϼ���: 20
	�̸��� �Է��ϼ���: ö��
	
	����� ���̴� 20���̰� �̸��� 'ö��' �Դϴ�.
```
[�ǽ� �ڵ�](../c_basic/ch09StandardInputOutput/stdioQuestion.c)