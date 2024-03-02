
- �Լ��� �� �� ��� ����
# I. �Ű����� ���ޱ��
- C������ �������� �����ͷ� ����
	- Java�� class
- �μ�, �Ű�����, parameter, argument: �� ���� ��
- �Ű������� Stack area���� ���

Caller  Callee

## A. �Ű�����
- �Ű������� '����'. �Լ��� ������ ���ο� �� ������ �����ϰ� ���� ���޹޾� �ʱ�ȭ
```c
void TestFunc(int a) {
	int b = 20;
//	int a = 20; �̹� �Ű��������� ȣ����
	a = 10;
}
```
- ��ó�� �Լ����� �ٽ� �μ��� �����ϸ� �ȵ�
- ���� ���� ���� �����ؼ� �ʱ�ȭ�� ��� ���� �μ��� ���� �ʿ䰡 ����

## B. �Ű������� ����
- ������������ �ڵ������� �Ű������� ����Ǵ� ��ġ
	- 32bit: stack memory
	- 64bit: register(CPU)
- e��ġx: 
	- e: register�� 
	- ��ġ: �Ʒ����� c, d 
	- x: 16���� ǥ�� 
  - �Լ� �ܺ�(ȣ����)
	```dockerfile
		00007FF68C532268  mov         edx,0Ah (rdx�� 10(16������ ǥ��)) 
		00007FF68C53226D  mov         ecx,5	  (rcx�� 5)
		00007FF68C532272  call        TestFunc (07FF68C5313DEh)  
	```
  - �Լ� ����(��ȣ����)
	```dockerfile
	00007FF68C531D79  mov         dword ptr [a],0Ah  (�Լ� ���ο��� ó���ɶ��� ��������. ������ ǥ��)
	```

- �Ű������� ������ ���� �Էµ�: ����صθ� ����

## C. ������
- Call by value 
	- ��
- Call by reference
	- ������(��ü�� ������ �߻�ȭ�� �������� ����� �����ϵ��� �ϰ��� ..)
	- �����ϵ����ϴ� �� : ������ : �ּ� : pointer
	- C����� �������� �޸��� ������ == ���� 
	- ����, value ������ �����ϹǷ� �ٸ� ��ü��������� reference�ʹ� �ٸ����� ����

### 1. Call by value
- ������ ������ �޾Ƽ� �ܼ� ������ ó���ϴ� �Լ�

```c
int Add(int a, int b) {
	int c = 0;
	c = a + b;
	return c;
}
int main(int argc, char* argv[]) {
	int a = 7;
	int res = 0;
	res = Add(3, 4);
	printf("%d\n", res);
	return 0;
```
- main() ����

|fnc|data| identifier |
|---|---|-----------|
|||           |
|||           |
|||           |
|main|7| a         |

- disassembly code: 
00007FF7894822E8  mov         dword ptr [a],7  

	dword ptr : cpu���� ���� �����ö� �����ͷ� ����

- �Ű����� ����(64bit�̹Ƿ� register ���)

|fnc|data|identifier|
|---|---|---|
||||
||||
||||
|main|7|a|
> disassembly code
```dockerfile
int res = 0;
00007FF7894822EF  mov         dword ptr [res],0  
	res = Add(3, 4);
00007FF7894822F6  mov         edx,4  
00007FF7894822FB  mov         ecx,3  
00007FF789482300  call        Add (07FF7894813E3h)
```
- Add(): 64bit���μ��������� register�� ���ļ� ����

|fnc|data|identifier|
|---|---|---|
|Add|0|c|
|Add|5|a|
|Add|10|b|
|main|7|a|
>disassembly code
```dockerfile
int c = 0;
00007FF7894817F2  mov         dword ptr [c],0  
c = a + b;
00007FF7894817F9  mov         eax,dword ptr [b]  
00007FF7894817FF  mov         ecx,dword ptr [a]  
```

- ���� : �߰����� ����� �������Ϳ��� ����

|fnc|data|identifier|
|---|---|---|
|Add|15|c|
|Add|5|a|
|Add|10|b|
|main|7|a|
- ���� ����� regist���� ���� c�� ����
- ��ȯ���� �����Ҷ� eax�� ���ֻ����
	- ���� �����ؼ� ����ϴ� ���� �ƴϹǷ� ���� 

>disassembly code
```dockerfile
00007FF789481805  add         ecx,eax  
00007FF789481807  mov         eax,ecx  
00007FF789481809  mov         dword ptr [c],eax  
	return c;
00007FF78948180C  mov         eax,dword ptr [c]  
```

- Add(): 64bit���μ��������� register�� ���ļ� ����

|fnc|data|identifier|
|---|---|---|
|main|15|res|
|main|7|a|

>disassembly code
```dockerfile
	printf("%d\n", res);
00007FF789482308  mov         edx,dword ptr [res]  
00007FF78948230B  lea         rcx,[string "%d\n" (07FF78948AC10h)]  
00007FF789482312  call        printf (07FF78948119Fh)  
```

- main() ����� �Բ� �ش� ������ ����
>disassembly code: 
```dockerfile
	return 0;
00007FF789482317  xor         eax,eax  
00007FF789482319  jmp         main+62h (07FF789482322h) 
```

### 2. Call by reference
- �����͸� ����� ����: 
	- main �Լ��� �޸𸮿� Add�� �����ؼ� ����ϵ��� ��
	- call by value�� ������ ���� �����ؼ� ���
- �Լ��� �Ű������� �����ͷ� ����
	- �޸� ȿ���� ���̱� ���� �����ϰ� ���ſ� ���꿡�� ��� 
```c
int Add(int* a, int* b) {
	return *a + *b;
}
```
- ȣ���ڴ� �ּҿ����ڸ� ����� ����
```c
int main(int argc, char* argv[]) {

	int x = 3, y = 4;
	printf("%d\n", Add(&x, &y));

	return 0;
}
```
- �𽺾���� �̵� ����
```dockerfile
	int x = 3, y = 4;
00007FF725A84E61  mov         dword ptr [x],3  
00007FF725A84E68  mov         dword ptr [y],4  
	printf("%d\n", Add(&x, &y));
00007FF725A84E6F  lea         rdx,[y]  
00007FF725A84E73  lea         rcx,[x]  
00007FF725A84E77  call        Add (07FF725A813E3h)  
```
- ���� �Լ�
```dockerfile
int Add(int* a, int* b) {
00007FF725A817D0  mov         qword ptr [rsp+10h],rdx  
00007FF725A817D5  mov         qword ptr [rsp+8],rcx  
00007FF725A817DA  push        rbp  
00007FF725A817DB  push        rdi  
00007FF725A817DC  sub         rsp,0E8h  
00007FF725A817E3  lea         rbp,[rsp+20h]  
00007FF725A817E8  lea         rcx,[__CA2C9B2D_advancedFunction_basic@c (07FF725A92016h)]  
00007FF725A817EF  call        __CheckForDebuggerJustMyCode (07FF725A8137Ah)  
	return *a + *b;
00007FF725A817F4  mov         rax,qword ptr [a]  
00007FF725A817FB  mov         eax,dword ptr [rax]  
00007FF725A817FD  mov         rcx,qword ptr [b]  
00007FF725A81804  add         eax,dword ptr [rcx]  
}
```
- �� ��ȯ
```dockerfile
00007FF725A84E7C  mov         edx,eax  
00007FF725A84E7E  lea         rcx,[string "%d\n" (07FF725A8AC10h)]  
00007FF725A84E85  call        printf (07FF725A8119Fh)  
```
## D. �ǽ�
```dockerfile
�� char[]�� �ּҸ� �Ű������� �޾� ���ڿ��� Deap copy�ϴ� MyStrcpy() �ۼ�
�Լ��� �ι�° �Ű������� ù��° �Ű������� �޸� ũ�Ⱑ �ǵ��� ����
int main(int argc, char* argv[]) {
	char szBufferSrc[12] = { "TestString" };
	char szBufferDst[12] = { 0 };

	MyStrcpy(szBufferDst, sizeof(szBufferDst), szBufferSrc);
	puts(szBufferDst);
	return 0;
}
```
[�ǽ� ����](../c_basic/ch15AdvancedFunction/AdvancedFunction_01Question.c)

- ���⼭�� strlen(char*)�� ���� �ʾƵ� ������ �ȴ�. 
```c
size_t nLenSrc = 0;
nLenSrc = strlen(targetArr);
```
- ������ ��� �޸� ũ�Ⱑ 12����Ʈ�� ������ 5����Ʈ�� 7����Ʈ ��ŭ�� ������ ���� ����ȴ�
- �� ������ ���� ������ �߻���Ű�Ƿ� Deep copy�� ������ ������ ����� �� �� ����.
- ���� ������ ũ�Ⱑ Ÿ�ٺ��� �� ū��� \0�� ���⶧���� ������ Ŀ�� �� �־� �����ؾ��Ѵ�
```c
	char testSrc[7] = { "abcdef" };
	char targetDst[5] = { "1234"};
	MyStrcpy(targetDst, sizeof(targetDst), testSrc);
	puts(targetDst);
```
# II. �������� �ּ� ��ȯ ����
- ��ȣ�� �Լ��� ���������� �Լ��� ��ȯ�� �Բ� ��� �Ҹ�
	- ���������� ���� ���� �����Ӱ� �����ֱ⸦ �����ϱ⶧��(�ڵ�����)
	- malloc()�� ����� ���� free()�� �Ҵ��� ������ ������ ���� ������ ������� ��������
- �Ҹ�� �޸� ������ �ּҸ� ȣ���� �Լ����� ��ȯ�ϰ� �����ϴ� ���� �ſ� �ɰ��� ����
	- return�� ���������� �ּҸ� ��ȯ�ϴ� �Լ�
```c
int* TestFunc(void) {
	int nData = 10;
	return &nData;
}

int main(int argc, char* argv[]) {
	int* pnResult = NULL;
	pnResult = TestFunc();

	printf("%d\n", *pnResult);
	return 0;
}
```
- ���� �״�� 10�� ��������.
- stack ����
	- main()

	|fnc|data|identifier|
	|---|---|---|
	||||
	||||
	||||
	|main|�ּ�|pnResult|

	- TestFunc()

	|fnc|data|identifier|
	|---|---|---|
	||||
	||||
	|TestFunc|10|nData|
	|main|�ּ�|pnResult|

	- return ����
	
	|fnc|data|identifier|
	|---|---|---|
	||||
	||||
	|(����)|(����)|(����)|
	|main|&nData|pnResult|
> ���⼭ ��µ� �� 10�� ������ ���� ����
- �Լ��� �ϳ��϶��� ������ ���� ������ Ȥ�ö� �޸𸮸� �����ϴ� ��� ���� �߻�
```c

int* TestFunc(void) {
	int nData = 10;
	return &nData;
}
int* TestFunc2(void) {
	int a = 5;
	return NULL;
}

int main(int argc, char* argv[]) {

	int* pnResult = NULL;
	pnResult = TestFunc();

	printf("TestFunc: %d\n", *pnResult);

	TestFunc2();
	printf("after TestFunc2: %d\n", *pnResult);

	return 0;
}
```
>console)
```dockerfile
TestFunc: 10
after TestFunc2: 5
```

- return�� NULL�̰� ���������� ���谡 �������� ������ ����ߴ� ���� ������� �����־� ���Ŀ��� ������ ��
	- ������, ��ũ, �� Ÿ�Կ��� ���ܰ� �߻����� ����
	- ���� �̻�����
- ����� �ּҸ� ��ȯ���� ����

# III. Call by reference�� �޸� ���� �Ҵ� �̽�
## A. Swap�ϱ�
- call by reference���� ���� ���Ǵ� ����
```c
void Swap(int* pLeft, int* pRight) {
	int nTmp = *pLeft;
	*pLeft = *pRight;
	*pRight = nTmp;
}

int main(int argc, char* argv[]) {
	
	int x = 10, y = 20;
	printf("x=%d, y=%d\n", x, y);

	Swap(&x, &y);
	printf("x=%d, y=%d\n", x, y);
	
	return 0;
}
```
## B. ���ڿ� 
- �޸� ���� �Ҵ� �� ������ �Լ�
	- <b style="color:red">Pointer�� ���� �ٺ����� ������</b> 
	- Callee�� �޸𸮸� �������� �Ҵ��� �� ��ȯ�ϴ� ������ ������ ������ ����
		- Callee�� Caller���� ��ȯ������ �ּҸ� ���� ����
		- �̶� Callee�� �޸𸮸� �Ҵ縸 ���� ���(��ȯ���� ���� ���)
			- Caller�� ������ �ؾ��ϴµ�.. �̹� Collee�� ����� ��Ȳ
	- �޸� ������ ���� Ȯ���� �ȳ� �ʿ�
	- �Ҵ�� �޸� ũ�� ���޹��� ���
		- <b style="color:red">pointer�� ������ �Ҵ��� �޸� ũ�⸦ �� �� ����</b>
		- �Ҵ��� �޸𸮺��� ��/�ڸ� ����ϸ� underflow/overflow�� �߻�
		- pointer�� size�� ���� ���¸� �������� �ʴ´�
		=> �̽� �߻�
- ���ڿ��� ���������� ���� �迭��.
	- �̸��� �޴� ��� �ſ� �پ��� ��Ȳ
		- �̸��� �� ����
			- ����
		- �̸��� �� ����
			- �̼��� 
		- �̸��� �� ���� ����
			- ���ùμ�
		- �ܱ����� ���
		...
	- �� ��� ����� ���� ���ߴܰ�(compile ����)���� �ľ��� �� ����
- �������� �Է¹����� ������ ������ �߻��Ѵ�
	- ����� �Է��� ���� �ŷ����� �ʴ´�
	- Fuzzing test(attack): �ǵ��� ������ �������� �Է��� ����
### 1. �������� ���ڿ��� �Է� �ޱ�
 ```c
 void GetName(char* pszName, unsigned int nSize) {
	printf("�̸��� �Է��ϼ���: ");
	gets_s(pszName, nSize);
}

int main(int argc, char* argv[]) {

	char szName[32] = { 0 };
	GetName(szName, sizeof(szName));
	printf("����� �̸��� %s �Դϴ�.\n", szName);

	return 0;
}
 ```
- gets_s�� ���� ũ�⸦ ��� �����Ͱ� �Էµ� ��� �������� ������� ���� ���ᰡ �߻�
- �ٸ� �ǵ��� �ٸ�
### 2. ���ڿ��� �������� �Է¹ޱ�
```c
char* GetName(void) {
	char* pszName = NULL;
	pszName = (char*)calloc(32, sizeof(char));//�����Ҵ�
	printf("�̸��� �Է��ϼ���: ");
	fgets(pszName, sizeof(char) * 32, stdin); //���������� ���
	// == gets_s()

	return pszName;
}

int main(int argc, char* argv[]) {
	char* pszName = NULL;
	pszName = GetName();
	//Callee���� �����Ҵ��� �޸� pszName�� stack frame ���ſ� �Բ� �����
	printf("����� �̸��� %s �Դϴ�.\n", pszName);
	
	//Collee�� �����Ƿ� �Ҵ� ������ å���� Caller
	free(pszName);

	return 0;
}
```
- ���� �Ҵ�� ������ �и��Ǹ�... ���� �߻�...
	- Ư�� multi thread�� ����ϴ� ��� �ſ� �ɰ�
	- �� ��� ������ ���� �ڼ��� �ۼ��ؾ���. 
	- Ư�� �޸� �Ҵ� ����� ����
- ���� ��Ŀ���� ���� ����� �ݵ�� �ʿ�
	- Java�� �޸� ������ JVM(Java Vitual Machine)�� GC(Garbage collector)�� ����
- GC�� ���� �����ϴ� ��찡 ����
	- ���� �Ҵ��� ���� ���� ����� ���� �����ڰ� �ִ� ���
	- ��� �����ڰ� ����� ��� ���� ��� ������ ����� �����
	- ���� ����� �����ϰ��ִ� �����ڰ� ���ø޸𸮿��� ����� ��� ���� ����� �����ϴ� ���
	- �ѹ��� �����غ��� �Ƿ� ��� ������ �� ����(rnwhcp )

# IV. ��� ȣ��
- �Լ� �ڵ� ���ο��� �ٽ� �ڽ��� ȣ���ϴ� ��
- Caller�� Callee�� ����
- �ݺ����� Stack �ڷᱸ���� ��ģ ��
	- stack�� Call stack�� ���� ���
	- ������ �ݺ������� ���� ����? ���ư�����.
	- ��ü ����� ��ȸ/�˻��Ҷ� ���� ���
		- quick sort
- ���� �ڷᱸ������ �ſ� �߿��ϰ� Ȱ��
	- Ư�� Tree ���� 
- �Լ� ȣ�� �������� ����
	- �޸� ����
- ������ �߻��� Stack overflow �߻�
## A. ��ǥ���� ���ȣ�� ���� - factorial
```c
int GetFactorial(int nParam) {
	int nResult = 0;
	if (nParam == 1) return 1;
	//Caller == Callee
	nResult = nParam * GetFactorial(nParam - 1);
	return nResult; 
}

int main(int argc, char* argv[]) {
	
	printf("5! = %d\n", GetFactorial(5));

	return 0;
}
```
- stack memory
	- TestFunc()

	|fnc|data|identifier|
	|---|---|---|
	||||
	||||
	||||
	|main|||

	|fnc|data|identifier|
	|---|---|---|
	||||
	||||
	|GetFactorial|5|nParam|
	|main|||

	|fnc|data|identifier|
	|---|---|---|
	||||
	|GetFactorial|0|nResult|
	|GetFactorial|5|nParam|
	|main|||
	- ��� 1ȸ

	|fnc|data|identifier|
	|---|---|---|
	|GetFactorial|0|nResult|
	|GetFactorial|4|nParam|
	|GetFactorial|0|nResult|
	|GetFactorial|5|nParam|
	|main|||

	- ��� 2ȸ

	|fnc|data|identifier|
	|---|---|---|
	|GetFactorial|0|nResult|
	|GetFactorial|3|nParam|
	|GetFactorial|0|nResult|
	|GetFactorial|4|nParam|
	|GetFactorial|0|nResult|
	|GetFactorial|5|nParam|
	|main|||

	- ... �ݺ�

	|fnc|data|identifier|
	|---|---|---|
	|GetFactorial|1|nParam|
	|GetFactorial|0|nResult|
	|GetFactorial|2|nParam|
	|GetFactorial|0|nResult|
	|GetFactorial|3|nParam|
	|GetFactorial|0|nResult|
	|GetFactorial|4|nParam|
	|GetFactorial|0|nResult|
	|GetFactorial|5|nParam|
	|main|||

	- nParam = 1�̹Ƿ� return 1

	|fnc|data|identifier|
	|---|---|---|
	|GetFactorial|1|nParam|
	|GetFactorial|1|nResult|
	|GetFactorial|2|nParam|
	|GetFactorial|0|nResult|
	|GetFactorial|3|nParam|
	|GetFactorial|0|nResult|
	|GetFactorial|4|nParam|
	|GetFactorial|0|nResult|
	|GetFactorial|5|nParam|
	|main|||

	|fnc|data|identifier|
	|---|---|---|
	|GetFactorial|1*2|nResult|
	|GetFactorial|3|nParam|
	|GetFactorial|0|nResult|
	|GetFactorial|4|nParam|
	|GetFactorial|0|nResult|
	|GetFactorial|5|nParam|
	|main|||

	|fnc|data|identifier|
	|---|---|---|
	|GetFactorial|3|nParam|
	|GetFactorial|1\*2*3|nResult|
	|GetFactorial|4|nParam|
	|GetFactorial|0|nResult|
	|GetFactorial|5|nParam|
	|main|||

	- ... �ݺ�

	|fnc|data|identifier|
	|---|---|---|
	|GetFactorial|1\*2\*3\*4\*5|nResult|
	|GetFactorial|5|nParam|
	|main|||

	- main

	|fnc|data|identifier|
	|---|---|---|
	|main|1\*2\*3\*4\*5||

- ���� ���� ���丮�� ������ �޸� �Ҹ� ���������� �ʴ´�. 
- ���� �н���

## B. ���ڿ� ��� �Լ� �����
```c
void putData(char* pszParam) {
	if (*pszParam == '\0') return;// ���� ���� �߽߰� �ݺ� ����
	putchar(*pszParam); // ���
	putData(pszParam + 1); // ������ �̵��� ��� ȣ��
}

int main(int argc, char* argv[]) {

	putData("TestData");
	putchar('\n');

	return 0;
}
```
>console)
```dockerfile
TestData
```
- ȣ�� ����, �޸�, ���� �޸� Ȯ�� ��
![���ȣ��](img/recursiveCall.png)
- ���ȣ���ϰ� ����ϸ� ���ڿ��� �ݴ�� ��µ�
```c
void putData(char* pszParam) {
	if (*pszParam == '\0') return;// ���� ���� �߽߰� �ݺ� ����
	putData(pszParam + 1); // ������ �̵�
	putchar(*pszParam); // ���
}
```
>console)
```dockerfile
ataDtseT
```

# V. ���� ���Ǵ� �Լ�
## A. ǥ���Լ� �߾���
- � ����� �����ϱ� ����...	
	- ���� ����: ���� ������
	- ���� : chatGPT�� �ش� ����� �����ϴ� �Լ��� �ִ��� ���� �����

## B. ���� ó�� �Լ�
- ���ڴ� �⺻������ ASCII �ڵ�
- ������ �����̳� ǥ��� ���� ���ڿ� ���� �ٸ� �� ����
	- 'A' > 65
	- 'A' + 1 > 65 + 1 > 66 > 'B'
	
| �з� | �Լ��� | ��� ���� | #include <?> |
| ---- | ------ | --------- | ------------ |
| **����** | isalpha() | ���ĺ� ���θ� Ȯ�� | `<ctype.h>` |
| **����** | isdigit() | ���� ���θ� Ȯ�� | `<ctype.h>` |
| **����** | isxdigit() | 16���� ���� ���θ� Ȯ�� | `<ctype.h>` |
| **����** | isalnum() | ���ĺ� �Ǵ� ���� ���θ� Ȯ�� | `<ctype.h>` |
| **����** | islower() | �ҹ��� ���θ� Ȯ�� | `<ctype.h>` |
| **``����** | isupper() | �빮�� ���θ� Ȯ�� | `<ctype.h>` |
| **����** | isspace() | ���� ���� ���θ� Ȯ�� | `<ctype.h>` |
| **��ȯ** | toupper() | �ҹ��ڸ� �빮�ڷ� ��ȯ | `<ctype.h>` |
| **��ȯ** | tolower() | �빮�ڸ� �ҹ��ڷ� ��ȯ | `<ctype.h>` |
| **�����** | gets() / gets_s() | ǥ�� �Է¿��� ���ڿ��� �о�� | `<stdio.h>` |
| **�����** | puts() | ���ڿ��� ǥ�� ��¿� ��� | `<stdio.h>` |
| **�����** | sprintf() | ����ȭ�� ���ڿ��� ���ۿ� ���� | `<stdio.h>` |
| **�����** | printf() | ����ȭ�� ���ڿ��� ǥ�� ��¿� ��� | `<stdio.h>` |
| **�����** | scanf_s() | ����ȭ�� �Է��� �޾� ������ ���� | `<stdio.h>` |
| **�����** | strcpy() | ���ڿ��� ���� | `<string.h>` |
| **�����** | strcat() | ���ڿ��� �̾���� | `<string.h>` |
| **�����** | strstr() | ���ڿ����� �κ� ���ڿ��� ã�� | `<string.h>` |
| **�����** | strpbrk() | ���ڿ����� Ư�� ���� ���տ� ���Ե� ���ڰ� ó������ ��Ÿ���� ��ġ�� ã�� | `<string.h>` |
| **�����** | strtok() | ���ڿ��� ��ū���� ���� | `<string.h>` |
| **���ڿ� ���� �� ũ��** | strlen() | ���ڿ��� ���̸� ��ȯ | `<string.h>` |
| **���ڿ� ���� �� ũ��** | sizeof() | ���� �Ǵ� ������ ������ ũ�⸦ ��ȯ | - |
| **���ڿ� ���� �� ũ��** | strnlen() | �ִ� ���̱��� ���ڿ��� ���̸� ��ȯ | `<string.h>` |
| **���ڿ� ��** | strcmp() | �� ���ڿ��� �� | `<string.h>` |
| **���ڿ� ��** | strncmp() | �ִ� ���̱��� �� ���ڿ��� �� | `<string.h>` |
| **���ڿ� ��** | strcasecmp() | ��ҹ��ڸ� �����ϰ� �� ���ڿ��� �� | `<strings.h>` |
| **���ڿ� ��** | strncasecmp() | ��ҹ��ڸ� �����ϰ� �ִ� ���̱��� �� ���ڿ��� �� | `<strings.h>` |
| **���ڿ� �˻� �� ����** | strchr() | ���ڿ����� Ư�� ���ڰ� ó������ ��Ÿ���� ��ġ�� ã�� | `<string.h>` |
| **���ڿ� �˻� �� ����** | strrchr() | ���ڿ����� Ư�� ���ڰ� ���������� ��Ÿ���� ��ġ�� ã�� | `<string.h>` |
| **���ڿ� �˻� �� ����** | strstr() | ���ڿ����� �κ� ���ڿ��� ã�� | `<string.h>` |
| **���ڿ� �˻� �� ����** | strdup() | ���ڿ��� ���� | `<string.h>` |
| **���ڿ� �˻� �� ����** | strndup() | �ִ� ���̱��� ���ڿ��� ���� | `<string.h>` |
| **���ڿ� ��ȯ �� ����** | strtok() | ���ڿ��� ��ū���� ���� | `<string.h>` |
| **���ڿ� ��ȯ �� ����** | strlwr() | ���ڿ��� �ҹ��ڷ� ��ȯ | `<string.h>` |
| **���ڿ� ��ȯ �� ����** | strupr() | ���ڿ��� �빮�ڷ� ��ȯ | `<string.h>` |
| **���ڿ� ��ȯ �� ����** | strcat() | ���ڿ��� �̾���� | `<string.h>` |
| **���ڿ� ��ȯ �� ����** | strncat() | �ִ� ���̱��� ���ڿ��� �̾���� | `<string.h>` |
| **��Ÿ ���ڿ� ���� �Լ�** | memset() | �޸� ������ Ư�� ������ ���� | `<string.h>` |
| **��Ÿ ���ڿ� ���� �Լ�** | memcpy() | �޸� ������ �ٸ� �޸� �������� ���� | `<string.h>` |
| **��Ÿ ���ڿ� ���� �Լ�** | memmove() | �޸� ������ �ٸ� �޸� �������� �̵� | `<string.h>` |
| **��Ÿ ���ڿ� ���� �Լ�** | memcmp() | �� �޸� ������ �� | `<string.h>` |

- chatGPT: �� �˻��ؼ� ����ϴ� ���� �Ƿ�
	- �Թ� ������ ������ �ŷ��Ҹ���

- Ư�� ���ڿ� ����, ������ ���ֻ��ǹǷ� �Ʒ� �Լ��� �ڼ��� ��������
	- strtok()
	- strpbrk()
	- strcpy_s()

- �������� �迭�� �� ����� ���
	- Ư�� ���־��̴� �������� �迭 ���ڿ�

## C. �������� �Է¿� ���� Stack frame �ջ�
```c
void GetString(void) {
	char szBuffer[8] = { 0 };
	int nData = 0x11223344;

	gets(szBuffer);
	printf("%s, %08X\n", szBuffer, nData);
	return;
}
```
>���� ���� �̳� console)
```dockerfile
TEST
TEST, 11223344
```
>���۸� �Ѿ ��� �ջ� console)
```dockerfile
TEST TEST 
TEST TEST, 11223300
```
- 64��Ʈ������ ����ó�����Ǿ� ����
```
Run-Time Check Failure #2 - Stack around the variable 'szBuffer' was corrupted.
'[0x6F34] ch15AdvancedFunction.exe' ���α׷��� ����Ǿ����ϴ�(�ڵ�: 0 (0x0)).
```
- �׽�Ʈ�� ���� ����: �°� �����̽��� �Ű澲�� �ʰڴ�
	- �⺻ ��Ÿ�� �˻� : �⺻��
	- ���� �˻�: ���Ȱ˻� ����
- ����: 
	- 64��Ʈ ���μ��� ü���� �����鼭 ���� ��ȭ�� ������ ���������� ������ stack area�� ����Ѵ�
	- stack frame�� ���ϼ��� 0������ ��������� 
		- ���� ���ΰ��� ���߿� �����⿡ �ļ����̴�
	- ���߿� ���� �������� ������ �Ѿ�� ���� �������� ������Ų��
		- szBuffer[8]�� "TESTTEST"�� ������ ���� ������ \0�� �߰���. 
		- szBuffer[8]�� �Ѿ� nData�� ������ \0�� �Է�
	- cpu�� little endian����̹Ƿ� ���������� �޸𸮸� ä��
		- 44 33 22 11���� �� �κ��� 44�� \0�� �Էµ�
	- �ٽ� ����Ҷ��� 44�κ��� null(00)�� ���
- �Է� ���̸� �������� �ʴ� gets()��� gets_s()�� ����� ����

## D. ����

|function||
|---|---|
|atoi|ASCII to int|
|atol|ASCII to long|
|atof|ASCII to float|

- ���ǻ���: ����
```c
printf("1234567890: %d\n", atoi("2147483647"));
printf("1234567890: %d\n", atoi("2147483648"));
printf("1.7e+308: %e\n", atof("1.7e+308"));
printf("1.7e+309: %e\n", atof("1.7e+309"));
```
- ���� �ִ밪�� �Ѿ�� ���� �� ���õǰų� ���Ѵ�(inf)�� ���
>console)
```
1234567890: 2147483647
1234567890: 2147483647
1.7e+308: 1.700000e+308
1.7e+309: inf
```
## E. �ð�
- ����ü�� ���� �� �̹Ƿ� �׳� �Ұ������θ� ����

|function||
|---|---|
|time()||
|localtime_s()||
|ctime_s()||

```c
	struct tm curtime = { 0 };
	time_t t = 0;
	
	t = time(NULL);
		//64bit unsigned int: 1970.1.1(����������/ UTC, GMT) ������ seconds
	localtime_s(&curtime,&t);

	printf("%lld\n", t);// �ʴ��� ���

	char szBuffer[128] = { 0 };
	//ctime_s: ���ڿ��� ���(�⺻ ��)
	ctime_s(szBuffer, sizeof(szBuffer), &t);
	printf("%s\n", szBuffer);

	//���ϴ� ������ ���� ����
	printf("%04d-%02d-%02d\n",
		curtime.tm_year + 1900,
		curtime.tm_mon + 1,
		curtime.tm_mday);
```
- time_t�� 32bit�� 2000�� ���� ���
	- ����Ʈ���� �α��� ������ ���� ����
		- 1970.1.1���� 32bit integer�� ����� ����: 2038.01.19 
		- �׶����� ���������� 15�� �� �Ƹ� ���װ� ���� ����
	- 64��Ʈ�� ����

- �ʿ��Ҷ� ã�ƾ��� �ȴ�		
## F. ����
- ������ ����
	- �õ忡 ���� ���� ������ �����ϹǷ� �õ带 ��� �ʱ�ȭ����� ����
	- ���ϴ� ������� ���
		- ����� ���� modulus operate

|function||
|---|---|
|srand()|rand �Լ��� �õ尪 ����|
|rand()|�õ带 �������� ������(����� ����) ����|

- Ư�� ����
	- � Ȱ���� ���� return�� ����
		- ��� : ���� 25%
		- �丮 : ���� 10%
		- ...
	- ������ ���� �˰��� ���� ȸ���� ��å�� �ٸ� �� ����
		- �����ڰ� ���� ������ �ʿ䰡 ���� �� ����

## G. �ý��� 
- ������ ���� �ý��� �Լ�
- ��������...�˾Ƽ�...

|function||
|---|---|
|systemn()|�ý��� Ŀ�ǵ�|
|exit()|cmd ����|

- �ý��� �Լ� ����
	- �̺�Ʈ ������ �����...
		- notepad.exe: �޸��� ����
		- dir: ���丮 �˻�
		- cls: Ŭ����
		- cmd: �ٸ� cmdâ ȣ��
		- exit: cmd ����
```c
	char szCommand[512] = { 0 };
	printf("Input command: ");
	gets_s(szCommand, sizeof(szCommand));

	system(szCommand);
	//system("notepad.exe");//�޸��� ����
```
- ����� ��ɾ ���� �����ϴ� ���� �ſ� �ߴ��� ���Ȼ�� �� �� ����


- exit()�� ������ ������� ����
```c
	char ch; 
	printf("Do you want to EXIT? (Y/N)\n");
	ch = _getch();
	if (ch == 'y' || ch == 'Y') {
		puts("EXIT");
		exit(1);//��� ����
	}
	puts("End of main()");
```

[�Լ� ���� ��ü �ڵ�](../c_basic/ch15ch15AdvancedFunction)