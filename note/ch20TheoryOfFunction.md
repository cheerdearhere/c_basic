# I. 함수 포인터
- 함수의 이름(상수)을 저장할 수 있는 포인터
- 함수 호출 연산자의 피연산자가 될 수 있음
	- 함수포인터(parameters...);
- 반환 자료형 (호출규칙 *변수명)(매개변수...) 형식으로 선언
- 함수 호출 규칙은 생략할 수 있음(프로젝트 설정 > C/C++ > 고급 > 호출규칙)
	- 32비트
		- _cdecl(c declaration) : 생략하면 default
			- 스택메모리의 포인터를 초기화하는 주체가 호출자
		- _stdcall
			- 스택메모리의 포인터를 초기화하는 주체가 피호출자
		- _fastcall
			- 매개변수를 register를 사용해 전달(매개변수 전달을 스택에서 사용x) 
	- 64비트
		- _fastcall
			- 64비트에서는 기본 
```c
int GetMax(int a, int b, int c) {
	int nMax = a;
	if (b > nMax) nMax = b;
	if (c > nMax) nMax = c;
	return nMax;
}
int main(void) {
	int(*pfGetMax)(int, int, int) = GetMax;//메모리주소도 가능
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
- 함수 바인딩
	- 호출 관계가 하나뿐이라 컴파일때부터 정해진 상태: static binding
	- 호출 관계가 조건에 따라 달라져 런타임때 정해지는 상태: dynamic binding

# II. 역호출 구조(call back 구조)
- 함수가 호출하는 것이 아니라 호출 되는 구조
- 함수의 이름(주소)을 라이브러리나 프레임워크에 전달하면 그 내부에서 호출되는 구조
	- 이미 구조, 로직이 만들어진 경우 내부의 기능에 따라 결정됨 
	- front에서는 콜백이 이어져 콜백지옥이라 부르기도 함.
- 함수를 매개변수로 받아 내부코드대로 수행을 결정
- 호출 시점과 횟수를 정확히 특정하기 어려움
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
- void qsort(배열, 요소 수, 단위 요소 크기, 비교를 담당할 콜백함수)
	- 내부에서 콜백함수가 호출되는 시점과 횟수를 특정할 수 없음
	- typedef int (__cdecl* _CoreCrtNonSecureSearchSortCompareFunction)(void const*, void const*);

# III. Lookup table + call back
- 성능 극대화를 위한 처리
- 열거형
```c
typedef enum _user_action {MOVE, JUMP, ATTACK, QUIT} ACTION;
```
- 사용할 함수
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
- 입력받기
```c
int GetInputFromClient(void) {
	int nInput = 0;
	puts("[0: move]\t[1: jump]\t[2: attack]\t[3: quit]");
	scanf_s("%d", &nInput);
	if (nInput < 0 || nInput > 3) {
		puts("잘못된 입력으로 종료합니다. ");
		nInput = 3;
	}
	return nInput;
}
```
- 함수 포인터를 이용한 함수 배열
```c
	// 함수의 배열(lookup table)
	int (*functionArray[3])(int) = {
		DoMove,	DoJump, DoAttack
	}; 
```
- switch-case를 사용하면 매번 비교를 위한 연산이 필요
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
	puts("시스템을 종료합니다.");
	...
```
- lookup + callback
```c
		functionArray[act](act);
```


[함수 고급 이론 전체 코드](../c_basic/ch20TheoryOfFunction)