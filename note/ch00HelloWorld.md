
# I. Hello World
## A. ������Ʈ �����غ���
### 1. ������Ʈ ����
![project](img/initProject.png)

### 2. ������Ʈ�� c ���� ����
- ����Ű: ctrl+shift+a
- Ȯ���� �����ϱ�
	- .cpp -> C++�� ������
	- .c -> C�� ������

### 3. �ڵ�
```C
#include <stdio.h>
// returnType functionName(parameterType){code}
int main(void) 
{//���� �ڵ� ����
	printf("Hello, World\n");//���ڿ� �ܼ� ���
	return 0;//��ȯ��
}
```
- stdio : study, studio�ƴ�
	- standard input output�� ����

### 4. ���� ����
- ������ ���� �� ��ũ ó�� 
- �ܼ� ��� Ȯ��

```dockerfile
���� 12:40�� ���带 ������...
1>------ ���� ����: ������Ʈ: HelloWorld, ����: Debug x64 ------
1>HelloWorld.c
1>HelloWorld.vcxproj -> D:\developerFiles\workspace\c_basic\helloWorld\x64\Debug\HelloWorld.exe
========== ����: 1�� ����, 0�� ����, 0�� �ֽ� ����, 0�� �ǳʶ� ==========
========== ������(��) ���� 12:40�� �Ϸ�Ǿ�����, 01.469 ����(��) �ɸ� ==========
```

### 5. �ַ�� ���� �ٸ� ������Ʈ�� �߰��� ���
���� > �߰� > ������Ʈ �߰� > �׸� �߰� > .c > �ڵ� �� ���� > �����

## B. ���α׷��� ���ǻ���
### 1. -time
|����|����|�� ���� ����
|------|------|---|
|compile time|- .c �ҽ��ڵ带 �������� .obj�� ����<br/>- JVM���� ġ�� .java�� .class�� ����<br/>- ������������ �����Ϸ��� ������ �˻��ϰ� ������ ������ ������ �Ϸ���|������ ����|
|link time|- ���� ���ϵ�� ���̺귯���� ���� ���Ϸ� �ռ�<br/>- JVM �����Ϸ� ������ ����<br/>- ������ ��ǰ�� üũ�ϴ� �����̶�� ��ũ�� �� ��ǰ�� ����|������ ���� ��  > ���� ����|
|build time|compileTime + LinkTime||
|run time|- ����� ���� ����|���� �ߴ��� ����(����� ȯ��, �ð� �� �پ��� ����)|

### 2. �ҽ��ڵ�� ��������
|Ȯ���� ��|Ư¡|���|
|---|---|---|
|.c|C��� �ҽ��ڵ� ����|Text|
|.obj|�ҽ��ڵ� ������ �������� ��������|PE|
|.lib|�ܺ� ���̺귯�� ���Ϸ� ������ �Ϸ����(obj�� ����)|PE|
|.exe|.obj�� .lib�� �ռ��� ��������|NPE|
* PE(Portable Executable): ���յ��� ���� ���¶� �ű�鼭 �����ų �� �ִ� ���� ����. ���̳ʸ� �ڵ�� ������ ���� 
* <-> NPE(None Portable Executable)

## C. Visual Studio 
- �ַ��: 
	- Ȯ���: .sln
	- ���� ������Ʈ�� ��� �����ϴ� ���� ���� 
	- F7Ű�� ����. ����������Ʈ ����
- ������Ʈ: 
	- � �ַ�� �� �� �乭�� �ڵ� ���� 
	- ����������Ʈ�� �����ؾ� �ַ�� ����� �����
	- ���� ������Ʈ �� �����ϰ� ���� ������Ʈ�� ����������Ʈ�� �����ϰ� �����ؾ� �׽�Ʈ�� �� ����
- VS�� ���� ������Ʈ�� �� �ַ������ ������ �� ����
	- ������, �����Ϸ�, ��Ŀ �� ���α׷��ֿ� ����
- x64�� �ַ� ��. 32��Ʈ�ΰ�� x82���
![����](img/solutionFiles.png)
- ������Ʈ ����
	- .exe : ��������
	- .pdb : ������ ���� db ����
	- .c   : �ҽ�����
	- .vcxproj/vcxproj.filters: ������Ʈ ȯ�� ����
- .vs, x64������ vs�� ���� �����ϹǷ� �����ص� ��
- .c���ϸ� �������� ��� ������Ʈ�� ���� �����ؾ��ϹǷ� sln������ �Բ� ������ ���� ����