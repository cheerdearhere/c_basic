# I. 형 한정어와 컴파일러 최적화 소개
- Type qualifier: 변수의 타입에 지정
	- 변수에 적용하는 문법으로 컴파일러 최적화에 깊이 관련
- 분류 
	- const		: 변수를 상수화(immutable variable)
	- volatile  : 컴파일러의 최적화를 건너뛰기. 
		- pc에서는 거의 사용안됨.
		- 임베디드 개발쪽에서 반드시 메모리를 사용해야하는 경우
	- 선언 관련
		- extern
		- typedef
## A. const: Constant
- 변수를 상수화하는 문법
	- 리터럴을 그 자체로 쓰기보다 이름을 붙여 의미 이해를 돕는다
- 개념상 읽기 전용으로 만들어주는 것
	- 우선 이렇게 이해
- 변수의 개수가 줄어들기 때문에 성능 최적화(Release mode)에 유리
	- 변수가 많아진다 > 값, 범위(경우의 수)가 커진다 > 복잡도가 커진다 > 자원(메모리, 연산 속도 등) 소모가 커진다
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
- nData가 메모리 자원을 사용 
	- 굳이 runtime마다 연산을 진행할 필요가 있는가?
	- compileTime에서 미리 값을 정해놓고 사용하면 연산을 낮출 수 있다. 
- release mode build일때 컴파일러가 직접 최적화시킨다
	- 중간 메모리 사용을 줄임
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
- 최적화에서 중요한 것은 변수들 간의 의존관계를 파악하는 것.
- const는 최적화에 큰 공헌을 한다.
	- 단 수정할 수 없기에 불편할 수 있음 
	- 포인터와 함께 사용되면 제한적으로 메모리를 사용할 수 있어 편리

## B. simbolic constant: const 심화
- 심볼릭 상수를 정의하는 두가지 방법
	- 형한정어 const를 사용해 이름으로 정의하기
		- 코드에 직접 표시됨
	- 전처리기(#define)를 사용해 이름으로 정의하기
		- 전역에서 사용가능
	- 열거형 상수(enum): 여러개의 심볼릭 상수를 한번에 정의
- 필요에 따라 사용

### 1. 예시
- 합격의 기준은 프로그래머의 재량이 아닌 프로그램 기획단계에서 결정되는 설계자의 재량
	- 처리 조건은 기획의 영역이며 변경가능성이 높음 
```c
	int nInput=0;
	printf("점수를 입력하세요: ");
	scanf_s("%d",&nInput);

	if (nInput >= 70)
		printf("합격입니다\n");
	else
		printf("불합격입니다\n");

```
- 기준으로 사용되는 수를 상수로 처리하면 관리하기 편리하다.
```c
//전처리기
#define MAX_LENGTH 32
#define CUTOFF 70

int main(int argc, char* argv[]) {

	const int nCUTOFF = 70;
	int nInput=0;
	printf("점수를 입력하세요: ");
	scanf_s("%d",&nInput);

	//if (nInput >= 70)
	if(nInput >= nCUTOFF)
		printf("합격입니다\n");
	else
		printf("불합격입니다\n");

	return 0;
}
```
- 전처리기를 통해 문서 제일 앞에 배치할 수 있음
```c
//전처리기
#define MAX_LENGTH 32
#define CUTOFF 70

int main(int argc, char* argv[]) {
	char szName[MAX_LENGTH] = { 0 };
	
	...

	if(nInput >= CUTOFF)
	...
```
- 변경 가능성이 조금이라도 있거나
- 의미를 명확히 해야할때 

### 2. 상수형 포인터
- 참조 관계에서 대상이 변경될 수 있는데 const를 사용해서 포인터 변수를 고정시킬 수 있다.
- 포인터가 가리키는 대상(함수에서 자주 사용)을 상수화
- 포인터 변수 자체를 상수화
```c
	char szBuffer[32] = {"I am a boy."};
	const char* pszBuffer = szBuffer;//szBuffer[0]의 메모리 
	szBuffer[0] = 'i';
//	*pszBuffer = 'i';//에러
```
- pszBuffer에 const를 안넣으면 단순대입 가능
- 함수에서 매개변수로 const를 받으면 데이터를 변동시키지 않음을 확실히 할 수 있음
```c
void PrintString(const char* pszParam) {
	puts(pszParam);
}

int main(int argc, char* argv[]) {
	char szBuffer[32] = {"I am a boy."};

	PrintString(szBuffer);
	PrintString("You are a girl.");

```
### 3. const 위치에 따른 immutable 처리
```c
	int nData = 10;
	
	const int* pnData = &nData;
	//*pnData = 20; 주소는 변경할 수 없음
	pnData = 20; //대입은 가능

	int* const pnNewData = &nData;
	//pnNewData = NULL; 변수에대한 대입 자체가 불가
```
- 단, 너무 남발하는 것도 컴파일을 방해할 수 있음

### 4. enum 사용하기
- 정수형으로 사용가능
- switch-case 사용시 유용
- 구조체, 공용체와 마찬가지로 typedef 사용 가능
```c
enum ACTION {MOVE, JUMP, ATTACK};//index 수로 사용
typedef enum COLOR_CODE {RED = 100, GREEN, BLUE} COLOR;// seed를 100으로 지정, GREEN = 101
```
- 함수, switch-case, 상수 등으로 사용 가능
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
# II. .형 재선언
- 기본 자료형(리터럴)을 가지고 새로운 자료형을 선언한 것
	- 구조체, 공용체, 열거형 
- 기본 자료형을 연장한 개념으로 이해
	- C언어가 제공하는 기본 형식의 이름을 바꾸는 용도로 사용
	- 구조체, 공용체 선언과 조합해 편의성을 확보하기 위함
- typedef는 남발시 읽기 어려운 코드가 될 가능성이 높음
	- api마다 자료형이 달라지면 매번 난해해진다...
	- 포인터를 포함한 재선언인 경우 더 큰 혼란으로 다가올 수 있음
- typedef {기존 자료형} typeName;
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
# III. extern 선언(전역변수에서 자세히 다뤘었음)
- 외부변수 선언시 사용되는 문법
- 한 프로젝트 내부에 여러 C파일이 있을 경우 다른 .c파일에 정의되어 있는 전역변수에 접근하기 위해 선언
	- 전역변수인경우 extern 생략 가능
- 같은 .c파일에서는 내부, 다른 파일이면 외부


[변수와 상수 고급이론 전체 코드](../c_basic/ch18Variable)