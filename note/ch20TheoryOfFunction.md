# I. �Լ� ������
- �Լ��� �̸�(���)�� ������ �� �ִ� ������
- �Լ� ȣ�� �������� �ǿ����ڰ� �� �� ����
	- �Լ�������(parameters...);
- ��ȯ �ڷ��� (ȣ���Ģ *������)(�Ű�����...) �������� ����
- �Լ� ȣ�� ��Ģ�� ������ �� ����(������Ʈ ���� > C/C++ > ��� > ȣ���Ģ)
	- 32��Ʈ
		- _cdecl(c declaration) : �����ϸ� default
			- ���ø޸��� �����͸� �ʱ�ȭ�ϴ� ��ü�� ȣ����
		- _stdcall
			- ���ø޸��� �����͸� �ʱ�ȭ�ϴ� ��ü�� ��ȣ����
		- _fastcall
			- �Ű������� register�� ����� ����(�Ű����� ������ ���ÿ��� ���x) 
	- 64��Ʈ
		- _fastcall
			- 64��Ʈ������ �⺻ 
```c
int GetMax(int a, int b, int c) {
	int nMax = a;
	if (b > nMax) nMax = b;
	if (c > nMax) nMax = c;
	return nMax;
}
int main(void) {
	int(*pfGetMax)(int, int, int) = GetMax;//�޸��ּҵ� ����
	printf("Max: %d\n", pfGetMax(1, 3, 2));
	return 0;
}
```
```c
	int(*pfGetMax)(int, int, int) = 0x00000000140011370;
	int(*pfGetMax)(int, int, int) 
	= (int(_cdecl*)(int, int, int))0x00000000140011370;
```
- c default
```
	int(_cdecl *pfGetMax)(int, int, int) = GetMax;
```
- �Լ� ���ε�
	- ȣ�� ���谡 �ϳ����̶� �����϶����� ������ ����: static binding
	- ȣ�� ���谡 ���ǿ� ���� �޶��� ��Ÿ�Ӷ� �������� ����: dynamic binding

# II. ��ȣ�� ����(call back ����)
- �Լ��� ȣ���ϴ� ���� �ƴ϶� ȣ�� �Ǵ� ����
- �Լ��� �̸�(�ּ�)�� ���̺귯���� �����ӿ�ũ�� �����ϸ� �� ���ο��� ȣ��Ǵ� ����
	- �̹� ����, ������ ������� ��� ������ ��ɿ� ���� ������ 
	- front������ �ݹ��� �̾��� �ݹ������̶� �θ��⵵ ��.
- �Լ��� �Ű������� �޾� �����ڵ��� ������ ����
- ȣ�� ������ Ƚ���� ��Ȯ�� Ư���ϱ� �����
```
int MyCompare(const void* pParam1, const void* pParam2) {
	return *(int*)pParam1 - *(int*)pParam2;
}

int main(void) {
	int aList[5] = { 30, 10, 40, 50, 20 };
	int i = 0;

	for (i = 0; i < 5; i++)
		printf("%d\t", aList[i]);
	putchar('\n');
	
	qsort(aList, _countof(aList), sizeof(int), MyCompare);

	for (i = 0; i < 5; i++)
		printf("%d\t", aList[i]);
	putchar('\n');
}
```
- void qsort(�迭, ��� ��, ���� ��� ũ��, �񱳸� ����� �ݹ��Լ�)
	- ���ο��� �ݹ��Լ��� ȣ��Ǵ� ������ Ƚ���� Ư���� �� ����
	- typedef int (__cdecl* _CoreCrtNonSecureSearchSortCompareFunction)(void const*, void const*);

# III. Lookup table + call back
- ���� �ش�ȭ�� ���� ó��
- ������
```c
typedef enum _user_action {MOVE, JUMP, ATTACK, QUIT} ACTION;
```
- ����� �Լ�
```c

int DoMove(int nParam){
	printf("DoMove: %d\n",nParam);
	return 0;
}
int DoJump(int nParam){
	printf("DoJump: %d\n", nParam);
	return 0;
}
int DoAttack(int nParam){
	printf("DoAttack: %d\n", nParam);
	return 0;
}
```
- �Է¹ޱ�
```c
int GetInputFromClient(void) {
	int nInput = 0;
	puts("[0: move]\t[1: jump]\t[2: attack]\t[3: quit]");
	scanf_s("%d", &nInput);
	if (nInput < 0 || nInput > 3) {
		puts("�߸��� �Է����� �����մϴ�. ");
		nInput = 3;
	}
	return nInput;
}
```
- �Լ� �����͸� �̿��� �Լ� �迭
```c
	// �Լ��� �迭(lookup table)
	int (*functionArray[3])(int) = {
		DoMove,	DoJump, DoAttack
	}; 
```
- switch-case�� ����ϸ� �Ź� �񱳸� ���� ������ �ʿ�
```c
int main(int argc, char* argv[]) {
	...

	ACTION act = 0;
	while ((act = GetInputFromClient()) != QUIT) {
		switch (act)
		{
		case MOVE: 
			functionArray[MOVE](act);
			break;
		case JUMP: 
			functionArray[JUMP](act);
			break;
		case ATTACK:
			functionArray[ATTACK](act);
			break;
		default:
			break;
		}
	}
	puts("�ý����� �����մϴ�.");
	...
```
- lookup + callback
```c
		functionArray[act](act);
```


[�Լ� ��� �̷� ��ü �ڵ�](../c_basic/ch20TheoryOfFunction)