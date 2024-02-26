
# I. ��ǻ�� �޸� ����
- CPU�� ������ �ڵ�(�Լ�/ ������ ���� ���� ����)�� ��� ����(���� �Ǵ� ���)�� ��� �޸𸮷κ��� ������
- �޸𸮴� ������ ���� ������
- ��� �޸𸮴� ������ �ּҸ� ����(����Ʈ ����/ �޸𸮻� ��ġ ����)
- 64bit �ý��ۿ��� �޸� �ּ� ���̴� 64bit

## A. �ϵ���� ���� �޸� ����
![�޸� ���� ����](img/memory_structure.png)

|�з�|��Ī|����|
|---|
|CPU|Register||
|CPU|L1, L2, L3 Cache memory||
|Internal (computer)|RAM|�ַ� �ٷ�� ����|
|External (Storage)|HDD, SSD, USB disk (file system)|�ܺ� ���� ��ġ|
|External (Storage)|backup device||

- C����� Ư���� ���μ����� ���� �ٷ�⵵��
	- ���� CPU�� �ƴ� ��Ÿ ���μ����� �ٷ�⵵�ϴٺ��� �������� ���Ǵ� ������ �������� ��쵵 �ִ�
	- ex) ARM ����� ���μ���, �����.. ��

## B. ����Ʈ����(�ü��) ���� �޸� ����
- ���� ��ǻ��(PC)�� ����޸� �ý��ۿ��� �����ǰ� �ִ� �޸� ����
- Virtual = Logical > ����Ʈ�����

|����|Ư¡|
|---|
|Stack|�ڵ�����(scope), ���� 1MB|
|Heap|���� �Ҵ� �޸�(variable)|
|static(PE)|text(code) section: ���� �ڵ� ����<br/>data section: <br/> &nbsp;- Read only(���ڿ� ���)<br/> &nbsp;- Read/Write(���� �޸�)|

## C. Windows vitual memeory system
- Process: ����Ǵ� ���α׷�
	- Thread: ���μ��� �ӿ��� ���� ó���ϴ� ����
		- main()�� �� 
		- multi_thread: �����带 ������ ���� ���α׷�
- OS : ���μ����� ���� �ڿ��� ���� �޸� ������ �˸°� �����층�ϴ� ����(Ŀ�δܰ�)
- VMS(virtual memeory space): OS�� ���� �ڿ�(RAM, HDD/SSD)�� ��� ���μ����� �����ϴ� ȯ��
	- ��ġ�� ū �迭�� �ܼ�ȭ�ؼ� ����
	- logical space: ���θ� �����ϴ� ����
- �޸� 
	- �������� ������ �������� ������ OS�� ���α׷��� ���� ����(���μ����� �׿���)
	- �ڹٿ����� garbage collector�� ����� ���� �޸𸮸� ����
	- ������ �����ϴ�

## D. �޸� ���� �Լ�
- ���� = runtime�� �۵�
- malloc(), calloc() : ���� �޸� �Ҵ� �Լ�
- free() : �޸� �Ҵ� ���� �Լ�
- realloc()
- memset()
- calloc()
- memcpy() : copy
- memcmp() : compare
- memchr()

- �Լ� �Ҽ�

|#include|�Լ�|
|---|
|<stdlib.h> | malloc()<br/>_countof()|
|<string.h> | memset()<br/>memcpy()<br/>memcmp()|
## E. �޸� �����!!
- �̷��� �����ϰ� �޸� ������� ���� �ľ��ϴ� ���� �߿�

# II. ������ ���� �⺻ ����
- ������ ����: �޸��� �ּҸ� �����ϱ� ���� ���뺯��
- 64bit �ý��ۿ��� �ּ� ���, ������ ������ ��� 64bit(8bytes)
- 1byte char�� ������ �޸� �ּ�(��ġ����)�� 64bit
	- char *pszData = &ch; // char ch = 'a';  
		- ch������ *������(�ּ�)�� char �������� ���ڴ�(�ؼ��ϰڴ�)
	- �� �޸� �������� �ּҰ� �پ��ִ� ���� �ƴ϶� �����ϴ� ����(OS)���� �ڵ带 ���δٴ� ���� ���
```c
	printf("%d\n", nData); // ����
	printf("%p\n", &nData); // �޸� pointer
```
>console
10
0078F8EC
- ����� ���� üũ
	- F10���� �����ϴٰ� F9�� �ߴ����� �����ϰ� alt+8�� ������� üũ
![����� üũ](img/assembler.png)
- ������ ȣ��Ǵ� �޸� �ּҴ� ���μ����� ����ɶ����� �����
	- Address Space Layout Randomization(ASLR): �޸� �ջ� ����� ������ �����ϱ����� ���. ����, ��, ���̺귯���� ���� �ּҸ� ������ ������ ��ġ�� target address ������ ��ư� �����. 
	- stack, heap, library ���� �����ּ� ���� ���

## A. ���� ������ ���� ����
- ��������: ����� ����� ����
	- Ư�� �޸� ������ int�� �����Ҷ� ����� ���� 
int* pnData = D2;
- ��������: ������ ����� ����
	- ������ ������ �����ϸ� ��������
*pnData;
- ���������� ����� �� �ִ� ������ ���� �ּҷ� ������� ��ġ�� �ĺ��ϴ� ���
```c
int x = 10;
int* pnData = &x; 
printf("x: %d\n", x);
*pnData = 20; 
printf("x: %d\n", x);
```
- ������ ����ϸ� ���� ����� �� �ִ�

# III. �����Ϳ� 1���� �迭
- �迭�� �̷�� ��� ���Ŀ� ���� ������ ������ �����ϴ� ���� �Ϲ���
- �ּ�: ���(�ĺ���)
	- char []: char*
	- int []: int*
```c
char szData[5] = { 0 };
char* pszData = &szData;
```
- ���� ���� ���� (*)�� ����� ������ �ִ� ������ ������ �� ����
	- *pszData = l-value; 
	- *(char*) ==> 
```c
int aList[5] = { 0 };
int* pnData = aList; // idx 0�� �ּ�
//int *pnData = &aList[0];

printf("aList[0] : %d\n",aList[0]);
*pnData = 20;
printf("aList[0] : %d\n", aList[0]);// ���� �ּҸ� ���
printf("pnData[0] : %d\n", pnData[0]);
```
>console
aList[0] : 0
aList[0] : 20
pnData[0] : 20

- ������ ������ �迭 �̸��� ���� +, - ������ �� �� ����(������� �ƴ�)
- ��� ������ �ƴ� ��� ��ġ(�迭�� �ε���)�� ����ϱ� ���� �����̸� �迭 ����� ����
- ������ ������ ���ؼ��� ���� ��/�� ���굵 ����
- ++ / +�� �ַ� ���
	- ���ؿ�� index 0 �� �ĺ��ڷ� ���� ������ ��Ҵ� ����� ��ġ�� 
```c
*(aList + 1)
*(aList�� �ּ�(idx 0) + 1) => idx 1�� �ּ�
```
- �迭�� ũ�⿡ ���� �ּ��ϳ��� �Ű����� Ŀ���� ���� ũ�Ⱑ �޶�����
	- char[8] 
	- short[4] 
	- int[2]
- single pointer�� single demention array�� ���� ����
```c
char szBuffer[16] = { "Hello" };
char* pszData = szBuffer; //�̱� ������

while (*pszData != '\0') //���� ����. ���� ����(null) �߰������� �̵�
	pszData++; // ���ϱ⿬��(��� �ƴ�. ������ �̵�)
printf("&pszData: %p, &szBuffer: %p\n",
	pszData,
	szBuffer);// �޸� �ּ�
printf("Length: %d\n", pszData - szBuffer); // ���� ����(����ƴ�)
// > ���ڿ��� ���� ��� ����
```
>console
&pszData: 003AF8CD, &szBuffer: 003AF8C8
Length: 5

![�޸� ����](img/memory_pointer.png)
- �Ʒ��� char szBuffer[]�� ù ���(idx 0)�� ����� �����͸� ����
- ������ char szBuffer[]�� �ּҰ��� pszData�� litte endian ����� ���� ����Ǿ������� ���� ����
- while���� ���鼭 pszData�� �޸� �ּҰ� ��(little endian���� ���� ������ ��)�� ������� ���� ����

- string�� ���̸� �����ϴ� �Լ�
```c
strlen(szBuffer);
```

# IV. �޸� �����Ҵ� �� ����
## A. �޸� ���� �Ҵ�
- ���� ����(Build = Compile + Link)�� ��� ��뷮�� ������ �� ����. ������� �Է��� �߻��ϴ� RunTime�� ����ϵ��� Ȯ���� �� ���� ���� ���
- Heap ������ ����ϴ� ���
- ���α׷� ���� �� �ʿ��� �޸𸮸� OS�� ��û(�Ҵ�)�� ����ϸ� ��ȯ(����)�� å���� ����
	- OS�� �㰡�� �� �̳����� ��밡��
	- ��ȯ�� �ʼ�
- �Ҵ���� �޸𸮴� ������ ���� �������
	- �Ҵ� �ް� ���ų�(clear) ���� ����ų�(overwrite) �����Ϳ� ������ ���� �ʵ��� �ڵ带 ¥�� �Ѵ�.
	- �뷮�� ���� ����
	- �߿��� ���� ������ ���� �����ؾ���
- �����Ⱚ: ����� �� �϶�
	- ��������: cc
	- �����Ҵ��� �޸�: cd
	- �����Ҵ��� �޸� �� ��: fd
- malloc() : stdlib.h �Ҽ�
	- returnType: �޸� �ּ�
	- parameterType: 
- free()
 	- returnType: 
	- parameterType: �޸� �ּ�(�ĺ���)
	- free�� ����ϸ� ����� �� + OS �غ��� �ѹ��� �ʱ�ȭ��
```c
	int* pList = NULL;

	pList = (int*)malloc(sizeof(int) * 3);
	//int 3�� ũ���� �޸� 3���� �غ��ض�
	// ���߽������� ��. runtime���� �ľ�
	pList[0] = 10;
	pList[1] = 20;
	pList[2] = 30;

	for (int i = 0; i < 3; i++)
		printf("%d %d\n", i, pList[i]);
	free(pList);// �޸� ��ȯ
```

## B. �Ҵ� ������ ������
- �ڿ� ����� ���� ����
	- Allocation = 64 KB // ����� Ʈ��
	- �� ���� �̵��ϴ� ũ�� = 4KB // ����� ����
- ����(4KB)�� �� ���� �ʴ� ��� �ٸ� ���� �뿩�ϰų�
- ������ ���� �Ѵ�(3KB, 2KB) ��� ���ο� ������ �����´� => 2����

```c
int* pList = NULL, i = 0;

pList = (int*)malloc(sizeof(int) * 3);
//int 3�� ũ���� �޸� 3���� �غ��ض�
// ���߽������� ��. runtime���� �ľ�
pList[0] = 10;
pList[1] = 20;
pList[2] = 30;

for (i = 0; i < 3; i++)
	printf("%d %d\n", i, pList[i]);
free(pList);// �޸� ��ȯ
```

# V. �޸� �ʱ�ȭ, ����, ��
- �ܼ� ������ ����Ҷ��� �޸� �����͸� ����ϴ� �����͵�(�迭 ��)�� ���ο� ����� �����ϰ��Ѵ�.
## A. �ʱ�ȭ
### 1. �޸� ��� ��ġ ��
- ������������ �ڵ�����(stack memory), char[6] �迭�� ó��
```c
char szBuffer[] = { "Hello" };
```
- ������ ����: ����(static area) ���ڿ� ���
	- in java: public static final char[] 
```c
char* pszBuffer = "Hello";
```
- �޸� ���� �Ҵ�/ �޸� ���� �ִ� char[6]
	- heap memory
	- ������ null(\0)
```c
char* pszData = NULL;
pszData = (char*)malloc(sizeof(char) * 6);
pszData[0] = 'H';
pszData[1] = 'e';
pszData[2] = 'l';
pszData[3] = 'l';
pszData[4] = 'o';
pszData[5] = '\0';
```
- �� ��� �޸� �ּ�(���� �з�)�� �ٸ�
```c
puts(szBuffer);
puts(pszBuffer);
puts(pszData);
```
- �޸� �����Ҵ� ����
```c
free(pszData);
```
- �ʱ�ȭ�� ���õ� ���� �޼���
	- malloc(): �޸� ũ�� OS�� ��û
		(int*)malloc(sizeof(int) * 3);
	- memset(): ��� �����͸� ũ�⸸ŭ �ʱ�ȭ
		memset(pList, 0, sizeof(int) * 3);
	- calloc(): �޸𸮸� ��û�ϸ鼭 �����͸� ũ�⸸ŭ �ʱ�ȭ
		- malloc() + memset()
		(int*)calloc(3, sizeof(int));
```c
//pointer
int* pList = NULL, * pNewList = NULL;
//array
int aList[3] = { 0 }; // 12 bytes ���� �ĺ��ڴ� index 0�� ����Ŵ 

//�޸� �ʱ�ȭ�� ���� �Ϲ����� ��
pList = (int*)malloc(sizeof(int) * 3); // 64bit¥�� �޸��ּ�
memset(pList, 0, sizeof(int) * 3);  // 64bit¥�� �޸��ּ�

//malloc + memset -> calloc: �����Ҵ� �� ������ ���� 0���� �ʱ�ȭ��Ŵ
pNewList = (int*)calloc(3, sizeof(int));

for (int i = 0; i < 3; ++i)
	printf("pList[%d]�� ��: %d\t", i, pList[i]);
putchar('\n');
for(int i = 0; i < 3; ++i )
	printf("pNewList[%d]�� ��: %d\t", i, pNewList[i]);
putchar('\n');

free(pList);
free(pNewList);
```
- �����Ҵ��� ������ �����Ⱚ�� ������ 0���� �ʱ�ȭ�ؾ��ϴ°�?
	- no
	- �ٸ� �����Ҵ����� ���ڿ��� ����Ҷ��� ������ �ʱ�ȭ
## B. <b style="color:red">����</b>(�ſ� �߿�)
- �ܼ� ���Կ������� �� �ǿ����ڰ� ��� ������� �޸� ���� �����ϴ� ������ ������ �� ����
```c
// ������ ����� �翬
	aVar = bVar;
// l-value (����) r-value;
```
- ������ ������ ������ ���(�޸� �ּҰ�)
- ��� ���� �߻�...
```c
char szBuffer[12] = { "HelloWorld" };
char szNewBuffer[12] = { 0 };

szNewBuffer = szBuffer; 
```
![�迭 �ܼ� ����](img/pointer_cannot.png)
- copy�� ����
	- Deep copy : ���� �����ͱ��� ����
	- Shallow copy : �����͸� ����
- �迭�� ���ؼ��� �ܼ� ���� �������� �迭 ��ü�� ������ �� ������ �ݺ����� ���� ���� ��Ҹ� �ϳ��� ����(�ܼ� ����)�ؾ��Ѵ�.
- memcpy()�� �������
```c
	//		�ٿ� ����,	������,	ũ��
	memcpy(szNewBuffer, szBuffer, 4);
```
- memcpy�� ���δ� �̷��� ������ ���� �ܼ� ����
```c
char szBuffer[12] = { "HelloWorld" };
char* pszData = NULL;
pszData = (char*)malloc(sizeof(char) * 12);
for(int i = 0; i < 12; ++i)
	pszData[i] = szBuffer[i];
puts(pszData);
```

## C. ��
- �񱳴� ����!
- java�� �ܼ��� ������ �ʰ� _string.equals(_string_other)
```c
	char szBuffer[12] = { "TestString" };
	char* pszData = "TestString";

	printf("%d\n", memcmp(szBuffer, pszData, 10));
	printf("%d\n", memcmp("teststring", pszData, 10));
	printf("%d\n", memcmp("DataString", pszData, 10));
```
>console
0
1
-1

## D. �ǽ� ����
```dockerfile
�Ʒ� �ڵ��� ���Կ� ���� ���ϰ� �ٸ��� �����Ͻÿ�
#include <stdio.h>
#include <stdlib.h>
int main(void) {
	char szBuffer[12] = { "HelloWorld" };
	char* pszData = NULL;
	pszData = (char*)malloc(sizeof(char) * 12);
	pszData = szBuffer;
	puts(pszData);

	return 0;
}
```
[�ǽ� ����](../c_basic/ch14Pointer/pointer_01Question.c)
- compile time������ ������ �߰ߵ��� �ʱ⶧���� ���ǰ� �ʿ��ϴ�
- ���ڿ� ���� ���� �Լ��� �ִ�
  - strcpy() > ���� �̽� > strcpy_s() ��� ����

# VI. �迭 ������ Ǯ���
# VII. ���ڿ� ����, ��, �˻�
# IX. ���� �Ҵ�� �޸� ������ realloc()
# X. ����������(���丸)
- �̱� �����Ͱ� �ͼ����� �ڿ� �� ��
# XI. ������ �迭�� ���� ������
# XII. ���� �޸𸮿� ���ҷ� ������ 





[�ǽ� ����](../c_basic/ch14Pointer/.c)


[�޸𸮿� ������ ��ü �ڵ�](../c_basic/ch14Pointer)