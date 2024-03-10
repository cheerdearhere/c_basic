# I. ��ó����(����ó����/ preprocessor)?
- Compiler ���� ���� ����ó��
	- header ����(.h)
	- ���Ǻ� ������
	- �ɺ��� ���
	- ��ũ�� 
- #pragma: ���� �������� ����
	- ���⼭ ���� pack()
	- �������� �ʿ��Ҷ�... ���
- #��ȣ�� ����

# II. Include
- ��� ����(���� �ڵ尡 ����ִ� ����)�� �ҽ��ڵ忡 �����ִ� ���
	- ����: .h
	- ����: .c
- #include �������
	- <������ϸ�.h>: �����Ϸ��� �����ϰ��ִ� �ý��� �������
		- alt + F7 > VC++���͸� > �Ϲ� > ���� ���͸� 
		- stdio.h���� ��ġ(�Ҽ� �޼��带 �����ϰ� F12�� ������ ��ġ�� �� �� ����)
		- �ڼ��� �ڵ�� ��������
		- �����ϸ� visual studio�� �缳ġ�ؾ���
			- ���� ����� �մ��� �ʴ� ���� �Ϲ���
			- ������ �ʿ��� ���� �ſ� ����
		- ��θ� �����ؼ� ��뵵 �����ϳ� ���� �׷�������
	- "�������.h": ���� ��α��� ���� �˻�(�ٸ� ���丮��� ��� ǥ��)
		- ������, ����� ���
		- ���� �س��� �������� ������ Link ���� �߻�
		- ���� �ַ�� �� ������Ʈ ������ �����ϴ� �ڵ���� ���
		- #pragma once: include�� ���������� �ʰ� �������� ���
			- ��� ���� ������ �ٸ� ��������� �ο�Ǵµ� ������ �ߺ� �ο��� ��츦 ����
			- pragma once�� �Ⱦ��� �ߺ� ���Ƿ� ���� ������ �߻��� �� ����
- ���???
	- ������ ������ ���� ���ݾ� �ٸ� �� �ִ�.
		-  Block, chunck, Stream ó�� 
	- .exe/ .lib ����
		- runtime�� DLL
	- java������ .class ������ JVM�� ���� ��� ���
		- C/C++���� ������ ���� �ٸ�
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "basicForm.h"

int main(int argc, char* argv[]) {
	OpenChapter();



	CloseChapter();
	return 0;
}
```
# III. #define
- �������� constó�� �ɺ��� ����� ������ �� �ִ� ��ó����
- ������ ����� ������ ���� ����Ǿ� �ҽ��ڵ带 ġȯ
- ��ũ�θ� �����Ҷ��� ����

## A. ��ũ��
- #define ��ó����� ����
- ���´� �Լ�ó�� �������� �Լ��� �ƴϴ�.
- legercy code������ ���ǰ������� ����� ū �Ÿ�Ʈ�� ����. 

## B. �Լ����� ����
- call�� stack memory ���...
- �Լ� ȣ������� overhead�� �߻�
- �̸� �����ϱ� ���� ���Ǵ� ���� ��ũ��
- ��, �����Ϸ� ����ȭ�� overhead �߻����� �پ��鼭 ��ũ�ε� ���󵵰� �پ��

## C. ��ũ�� ����
```c

#define ADD_MACRO(a,b)( a + b )

```
## D. ��ũ�� ���
```c
int AddFnc(int a, int b) {
	return a + b;
}

int main(void) {

	printf("fnc: %d\n", AddFnc(3, 4));
	printf("macro: %d\n", ADD_MACRO(3, 4));

	return 0;
}
```
- ����� ����

## E. ��ũ�� Ư��ȭ ������
- Ư��ȭ ������(#) �ϳ��� ������ ���� �����͸� ���ڿ��� ��ȯ
- a##b: a �ڿ� b�� ����
	- ���ڿ��� ���̴� ���� �ƴ� �ҽ��ڵ� ��ü�� ����
```c
#define STRING(a) #a
#define PASTER(a, b) a##b
```
- ���� ����
```c
	int nData = 10; 

	printf("nData\t: %d\n", nData);
	printf("nDa##ta\t: %d\n", PASTER(nDa, ta));// ���ڿ��� �ƴ� �ҽ��ڵ� ��ü�� ����
	printf("#nData\t: %s\n", STRING(nData));//"nData"
```
>console)
```
nData   : 10
nDa##ta : 10
#nData  : nData
```
- ��ó�� �� �ʿ��� ��찡 �ƴ϶�� �׳� �ִ� ��ũ�κ��� �߾���

## F. ���Ǻ� ������
- ������ ��Ÿ������ ó���ؼ� ���ǿ� ���� �ڵ带 ��ȯ��Ŵ
- ��� ���� ���ο� ���� ���� �����ϵǴ� �ڵ尡 �޶���.
	- JSP�� action tag�� ���� ���
- #ifdef, #else, #endif�� ����
- ������Ʈ ���� ȭ�鿡�� �Ӽ��� �����ߴ� �͵�
	- Debug/Release ���� ����
	- ���ڿ� ó����(MBCS, Unicode) ����
```
#include <stdio.h>

#ifdef _DEBUG
	#define MODEMESSAGE "Debug mode"
#else
	#define MODEMESSAGE "Release mode"
#endif
```
```c
int main(int argc, char* argv[]) {
	
	puts(MODEMESSAGE);// ���� ���(debug/ runtime)�� ���� ��� �޼����� �޶���

	return 0;
}
```
- ���Ǻ� �������� ���� ���� ����ϴ� �о�: unicode
	- �ѱ��� ASCII�� �ƴϱ⶧���� unicode�� ���.
	- �ѱ��� 2bytes�̱⶧���� ���̴� 6������ ���ڼ��� 3���� �Ǿ����
- �ڵ��� ����Ǹ鼭 
	- char > wchrt_t 
	- printf() > wprintf()
- �̸� ó���ϱ����� ��ó��(���Ǻ� ������)
- MYUNICODE�� ���¿� ���� �Ϲ� ���ڿ����� �����ڵ����� ó���� �ٸ�����
```c
#define MYUNICODE

#ifdef MYUNICODE
typedef wchar_t TCHAR;
#define _T(string) L##string
#define PRINT wprintf
#else
typedef char TCHAR;
#define _T(string) string
#define PRINT printf
#endif // MYUNICODE
```
- ���� ���濡���� ó���� �����
```
	TCHAR szData[16] = _T("Test string");
	PRINT(_T("%s\n"), szData);
	PRINT(_T("%zd, %zd\n"), sizeof(TCHAR), sizeof(szData));
```
- ���� ����о߸� �ٷ�� ���� ������ ������ ������ �̷��� �ִ� ������
- �� �����ϰ� �ʹٸ� #pragma


[��ó���� ��ü �ڵ�](../c_basic/ch19Preprocessor)