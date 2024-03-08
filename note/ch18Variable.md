# I. �� ������� �����Ϸ� ����ȭ �Ұ�
- Type qualifier: ������ Ÿ�Կ� ����
	- ������ �����ϴ� �������� �����Ϸ� ����ȭ�� ���� ����
- �з� 
	- const		: ������ ���ȭ(immutable variable)
	- volatile  : �����Ϸ��� ����ȭ�� �ǳʶٱ�. 
		- pc������ ���� ���ȵ�.
		- �Ӻ���� �����ʿ��� �ݵ�� �޸𸮸� ����ؾ��ϴ� ���
	- ���� ����
		- extern
		- typedef
## A. const: Constant
- ������ ���ȭ�ϴ� ����
	- ���ͷ��� �� ��ü�� ���⺸�� �̸��� �ٿ� �ǹ� ���ظ� ���´�
- ����� �б� �������� ������ִ� ��
	- �켱 �̷��� ����
- ������ ������ �پ��� ������ ���� ����ȭ(Release mode)�� ����
	- ������ �������� > ��, ����(����� ��)�� Ŀ���� > ���⵵�� Ŀ���� > �ڿ�(�޸�, ���� �ӵ� ��) �Ҹ� Ŀ����
```c
	int nData;
	nData = 3 + 4;
	printf("%d\n", nData);
```
>disassembly
```
00007FF631251A1E  call        __CheckForDebuggerJustMyCode (07FF631251375h)  
	int nData;
	nData = 3 + 4;
00007FF631251A23  mov         dword ptr [nData],7  
	printf("%d\n", nData);
00007FF631251A2A  mov         edx,dword ptr [nData]  
```
- nData�� �޸� �ڿ��� ��� 
	- ���� runtime���� ������ ������ �ʿ䰡 �ִ°�?
	- compileTime���� �̸� ���� ���س��� ����ϸ� ������ ���� �� �ִ�. 
- release mode build�϶� �����Ϸ��� ���� ����ȭ��Ų��
	- �߰� �޸� ����� ����
```
00007FF7697E1070  sub         rsp,28h  
	int nData; 
	const int a = 3, b = 4;
//	nData = 3 + 4;
	nData = a + b;
	printf("%d\n", nData);
00007FF7697E1074  mov         edx,7  
00007FF7697E1079  lea         rcx,[string "%d\n" (07FF7697E2250h)]  
00007FF7697E1080  call        printf (07FF7697E1010h)  
```
- ����ȭ���� �߿��� ���� ������ ���� �������踦 �ľ��ϴ� ��.
- const�� ����ȭ�� ū ������ �Ѵ�.
	- �� ������ �� ���⿡ ������ �� ���� 
	- �����Ϳ� �Բ� ���Ǹ� ���������� �޸𸮸� ����� �� �־� ��

## B. simbolic constant: const ��ȭ
- �ɺ��� ����� �����ϴ� �ΰ��� ���
	- �������� const�� ����� �̸����� �����ϱ�
		- �ڵ忡 ���� ǥ�õ�
	- ��ó����(#define)�� ����� �̸����� �����ϱ�
		- �������� ��밡��
	- ������ ���(enum): �������� �ɺ��� ����� �ѹ��� ����
- �ʿ信 ���� ���

### 1. ����
- �հ��� ������ ���α׷����� �緮�� �ƴ� ���α׷� ��ȹ�ܰ迡�� �����Ǵ� �������� �緮
	- ó�� ������ ��ȹ�� �����̸� ���氡�ɼ��� ���� 
```c
	int nInput=0;
	printf("������ �Է��ϼ���: ");
	scanf_s("%d",&nInput);

	if (nInput >= 70)
		printf("�հ��Դϴ�\n");
	else
		printf("���հ��Դϴ�\n");

```
- �������� ���Ǵ� ���� ����� ó���ϸ� �����ϱ� ���ϴ�.
```c
//��ó����
#define MAX_LENGTH 32
#define CUTOFF 70

int main(int argc, char* argv[]) {

	const int nCUTOFF = 70;
	int nInput=0;
	printf("������ �Է��ϼ���: ");
	scanf_s("%d",&nInput);

	//if (nInput >= 70)
	if(nInput >= nCUTOFF)
		printf("�հ��Դϴ�\n");
	else
		printf("���հ��Դϴ�\n");

	return 0;
}
```
- ��ó���⸦ ���� ���� ���� �տ� ��ġ�� �� ����
```c
//��ó����
#define MAX_LENGTH 32
#define CUTOFF 70

int main(int argc, char* argv[]) {
	char szName[MAX_LENGTH] = { 0 };
	
	...

	if(nInput >= CUTOFF)
	...
```
- ���� ���ɼ��� �����̶� �ְų�
- �ǹ̸� ��Ȯ�� �ؾ��Ҷ� 

### 2. ����� ������
- ���� ���迡�� ����� ����� �� �ִµ� const�� ����ؼ� ������ ������ ������ų �� �ִ�.
- �����Ͱ� ����Ű�� ���(�Լ����� ���� ���)�� ���ȭ
- ������ ���� ��ü�� ���ȭ
```c
	char szBuffer[32] = {"I am a boy."};
	const char* pszBuffer = szBuffer;//szBuffer[0]�� �޸� 
	szBuffer[0] = 'i';
//	*pszBuffer = 'i';//����
```
- pszBuffer�� const�� �ȳ����� �ܼ����� ����
- �Լ����� �Ű������� const�� ������ �����͸� ������Ű�� ������ Ȯ���� �� �� ����
```c
void PrintString(const char* pszParam) {
	puts(pszParam);
}

int main(int argc, char* argv[]) {
	char szBuffer[32] = {"I am a boy."};

	PrintString(szBuffer);
	PrintString("You are a girl.");

```
### 3. const ��ġ�� ���� immutable ó��
```c
	int nData = 10;
	
	const int* pnData = &nData;
	//*pnData = 20; �ּҴ� ������ �� ����
	pnData = 20; //������ ����

	int* const pnNewData = &nData;
	//pnNewData = NULL; ���������� ���� ��ü�� �Ұ�
```
- ��, �ʹ� �����ϴ� �͵� �������� ������ �� ����

### 4. enum ����ϱ�
- ���������� ��밡��
- switch-case ���� ����
- ����ü, ����ü�� ���������� typedef ��� ����
```c
enum ACTION {MOVE, JUMP, ATTACK};//index ���� ���
typedef enum COLOR_CODE {RED = 100, GREEN, BLUE} COLOR;// seed�� 100���� ����, GREEN = 101
```
- �Լ�, switch-case, ��� ������ ��� ����
```c
void DoAction(enum ACTION act) {
	switch (act)
	{
	case MOVE:
		printf("move(%d)\n",act);
		break;
	case JUMP:
		printf("jump(%d)\n", act);
		break;
	case ATTACK:
		printf("attack(%d)\n", act);
		break;
	default:
		break;
	}
}

int main(int argc, char* argv[]) {
	enum ACTION act = MOVE;
	COLOR color = BLUE;

	DoAction(act);
	act = ATTACK;
	DoAction(act);
	printf("blue: %d\n", color);

```
>console)
```
move(0)
attack(2)
blue: 102
```
# II. .�� �缱��
- �⺻ �ڷ���(���ͷ�)�� ������ ���ο� �ڷ����� ������ ��
	- ����ü, ����ü, ������ 
- �⺻ �ڷ����� ������ �������� ����
	- C�� �����ϴ� �⺻ ������ �̸��� �ٲٴ� �뵵�� ���
	- ����ü, ����ü ����� ������ ���Ǽ��� Ȯ���ϱ� ����
- typedef�� ���߽� �б� ����� �ڵ尡 �� ���ɼ��� ����
	- api���� �ڷ����� �޶����� �Ź� ����������...
	- �����͸� ������ �缱���� ��� �� ū ȥ������ �ٰ��� �� ����
- typedef {���� �ڷ���} typeName;
```c
typedef unsigned int  UINT;
typedef const char* LPSTR;

int main(int argc, char* argv[]) {

	UINT uData = 10;
	printf("%u\n", uData);

	LPSTR pszData = NULL;
	pszData = "Hello world";
	printf("%s\n", pszData);
	printf("%p\n", pszData);
```
# III. extern ����(������������ �ڼ��� �ٷ����)
- �ܺκ��� ����� ���Ǵ� ����
- �� ������Ʈ ���ο� ���� C������ ���� ��� �ٸ� .c���Ͽ� ���ǵǾ� �ִ� ���������� �����ϱ� ���� ����
	- ���������ΰ�� extern ���� ����
- ���� .c���Ͽ����� ����, �ٸ� �����̸� �ܺ�


[������ ��� ����̷� ��ü �ڵ�](../c_basic/ch18Variable)