
# I. 컴퓨터 메모리 종류
- CPU는 연산할 코드(함수/ 실행을 위한 기계어 집합)와 대상 정보(변수 또는 상수)를 모두 메모리로부터 가져옴
- 메모리는 변수를 통해 가져옴
- 모든 메모리는 고유한 주소를 가짐(바이트 단위/ 메모리상 위치 정보)
- 64bit 시스템에서 메모리 주소 길이는 64bit

## A. 하드웨어 기준 메모리 구조
![메모리 구조 사진](img/memory_structure.png)

|분류|명칭|설명|
|---|
|CPU|Register||
|CPU|L1, L2, L3 Cache memory||
|Internal (computer)|RAM|주로 다루는 영역|
|External (Storage)|HDD, SSD, USB disk (file system)|외부 저장 장치|
|External (Storage)|backup device||

- C언어의 특성상 프로세서를 직접 다루기도함
	- 범용 CPU가 아닌 기타 프로세서를 다루기도하다보니 범용으로 사용되는 문법과 동떨어진 경우도 있다
	- ex) ARM 모바일 프로세서, 라즈베리.. 등

## B. 소프트웨어(운영체제) 기준 메모리 종류
- 범용 컴퓨터(PC)는 가상메모리 시스템에서 관리되고 있는 메모리 종류
- Virtual = Logical > 소프트웨어다

|종류|특징|
|---|
|Stack|자동변수(scope), 보통 1MB|
|Heap|동적 할당 메모리(variable)|
|static(PE)|text(code) section: 실행 코드 기계어<br/>data section: <br/> &nbsp;- Read only(문자열 상수)<br/> &nbsp;- Read/Write(정적 메모리)|

## C. Windows vitual memeory system
- Process: 실행되는 프로그램
	- Thread: 프로세스 속에서 일을 처리하는 단위
		- main()의 수 
		- multi_thread: 쓰레드를 여러개 쓰는 프로그램
- OS : 프로세스를 돌릴 자원을 가상 메모리 공간에 알맞게 스케쥴링하는 역할(커널단계)
- VMS(virtual memeory space): OS를 통해 자원(RAM, HDD/SSD)을 얻어 프로세스를 수행하는 환경
	- 덩치가 큰 배열로 단순화해서 이해
	- logical space: 논리로만 존재하는 공간
- 메모리 
	- 자유도가 높지만 관리하지 않으면 OS가 프로그램을 실행 중지(프로세스를 죽였다)
	- 자바에서는 garbage collector를 사용해 참조 메모리를 관리
	- 엑셀과 유사하다

## D. 메모리 관리 함수
- 동적 = runtime에 작동
- malloc(), calloc() : 동적 메모리 할당 함수
- free() : 메모리 할당 해제 함수
- realloc()
- memset()
- memcpy()
- memcmp()
- memchr()

## E. 메모리 디버깅!!
- 이론을 이해하고 메모리 디버깅을 통해 파악하는 것이 중요

# II. 포인터 변수 기본 문법
- 포인터 변수: 메모리의 주소를 저장하기 위한 전용변수
- 64bit 시스템에서 주소 상수, 포인터 변수는 모두 64bit(8bytes)
- 1byte char형 변수의 메모리 주소(위치정보)는 64bit
	- char *pszData = &ch; // char ch = 'a';  
		- ch에대한 *포인터(주소)를 char 형식으로 쓰겠다(해석하겠다)
	- 매 메모리 공간마다 주소가 붙어있는 것이 아니라 관리하는 입장(OS)에서 코드를 붙인다는 것을 기억
```c
	printf("%d\n", nData); // 변수
	printf("%p\n", &nData); // 메모리 pointer
```
>console
10
0078F8EC
- 디버그 모드로 체크
	- F10으로 진행하다가 F9로 중단점을 지정하고 alt+8로 어셈블러를 체크
![어셈블러 체크](img/assembler.png)
- 변수가 호출되는 메모리 주소는 프로세스가 실행될때마다 변경됨
	- Address Space Layout Randomization(ASLR): 메모리 손상 취약점 공격을 방지하기위한 기술. 스택, 힙, 라이브러ㅏ리 등의 주소를 랜덤한 영역에 배치해 target address 예측을 어렵게 만든다. 
	- stack, heap, library 등의 시작주소 관리 방식

## A. 직접 지정과 간접 지정
- 직접지정: 상수를 사용해 지정
	- 특정 메모리 공간을 int로 지정할때 상수로 지정 
int* pnData = D2;
- 간접지정: 변수를 사용해 지정
	- 포인터 변수로 지정하면 간접지정
*pnData;
- 간접지정은 변경될 수 있는 임의의 기준 주소로 상대적인 위치를 식별하는 방식
```c
int x = 10;
int* pnData = &x; 
printf("x: %d\n", x);
*pnData = 20; 
printf("x: %d\n", x);
```
- 엑셀을 사용하면 쉽게 사용할 수 있다

# III. 포인터와 1차원 배열
- 배열을 이루는 요소 형식에 대한 포인터 변수를 선언하는 것이 일반적
- 주소: 상수(식별자)
	- char []: char*
	- int []: int*
```c
char szData[5] = { 0 };
char* pszData = &szData;
```
- 간접 지정 연산 (*)의 결과는 형식이 있는 변수로 생각할 수 있음
	- *pszData = l-value; 
	- *(char*) ==> 
```c
int aList[5] = { 0 };
int* pnData = aList; // idx 0의 주소
//int *pnData = &aList[0];

printf("aList[0] : %d\n",aList[0]);
*pnData = 20;
printf("aList[0] : %d\n", aList[0]);// 같은 주소를 사용
printf("pnData[0] : %d\n", pnData[0]);
```
>console
aList[0] : 0
aList[0] : 20
pnData[0] : 20

- 포인터 변수나 배열 이름에 대해 +, - 연산을 할 수 있음(산술연산 아님)
- 산술 연산이 아닌 상대 위치(배열의 인덱스)를 계산하기 위한 연산이며 배열 요소의 개수
- 포인터 변수에 대해서는 단항 증/감 연산도 가능
- ++ / +를 주로 사용
	- 기준요소 index 0 을 식별자로 쓰고 나머지 요소는 상대적 위치로 
```c
*(aList + 1)
*(aList의 주소(idx 0) + 1) => idx 1의 주소
```
- 배열의 크기에 따라 주소하나를 옮겼을때 커지는 값의 크기가 달라진다
	- char[8] 
	- short[4] 
	- int[2]
- single pointer와 single demention array는 거의 같다
```c
char szBuffer[16] = { "Hello" };
char* pszData = szBuffer; //싱글 포인터

while (*pszData != '\0') //간접 지정. 제로 문자(null) 발견전까지 이동
	pszData++; // 더하기연산(산술 아님. 포인터 이동)
printf("&pszData: %p, &szBuffer: %p\n",
	pszData,
	szBuffer);// 메모리 주소
printf("Length: %d\n", pszData - szBuffer); // 빼기 연산(산술아님)
// > 문자열의 길이 계산 로직
```
>console
&pszData: 003AF8CD, &szBuffer: 003AF8C8
Length: 5

![메모리 변경](img/memory_pointer.png)
- 아래는 char szBuffer[]의 첫 요소(idx 0)에 저장된 데이터를 보관
- 우측은 char szBuffer[]의 주소값이 pszData에 litte endian 방식을 따라 저장되어있음을 관측 가능
- while문이 돌면서 pszData의 메모리 주소가 끝(little endian으로 제일 왼쪽의 값)이 변경됨을 관측 가능

- string의 길이를 측정하는 함수
```c
strlen(szBuffer);
```

# IV. 메모리 동적할당 및 해제
## A. 메모리 동적 할당
- 개발 시점(Build = Compile + Link)때 모든 사용량을 예측할 수 없다. 사용자의 입력이 발생하는 RunTime에 사용하도록 확정할 수 없는 양을 사용
- Heap 영역을 사용하는 방법
- 프로그램 실행 중 필요한 메모리를 OS에 요청(할당)해 사용하며 반환(해제)의 책임이 있음
	- OS가 허가한 양 이내에서 사용가능
	- 반환은 필수
- 할당받은 메모리는 쓰레기 값이 들어있음
	- 할당 받고 비우거나(clear) 덮어 씌우거나(overwrite) 데이터에 영향을 받지 않도록 코드를 짜야 한다.
	- 용량에 따라 결정
	- 중요한 것은 쓰레기 값을 인지해야함
- 쓰레기값: 디버그 중 일때
	- 지역변수: cc
	- 동적할당한 메모리: cd
	- 동적할당한 메모리 앞 뒤: fd
- malloc() : stdlib.h 소속
	- returnType: 메모리 주소
	- parameterType: 
- free()
 	- returnType: 
	- parameterType: 메모리 주소(식별자)
	- free를 사용하면 사용한 양 + OS 준비량이 한번에 초기화됨
```c
	int* pList = NULL;

	pList = (int*)malloc(sizeof(int) * 3);
	//int 3개 크기의 메모리 3개를 준비해라
	// 개발시점에는 모름. runtime에서 파악
	pList[0] = 10;
	pList[1] = 20;
	pList[2] = 30;

	for (int i = 0; i < 3; i++)
		printf("%d %d\n", i, pList[i]);
	free(pList);// 메모리 반환
```

## B. 할당 단위와 페이지
- 자원 배분을 위한 단위
	- Allocation = 64 KB // 음료수 트럭
	- 한 번에 이동하는 크기 = 4KB // 음료수 상자
- 단위(4KB)를 다 쓰지 않는 경우 다른 곳에 대여하거나
- 단위를 조금 넘는(3KB, 2KB) 경우 새로운 단위를 가져온다 => 2단위

```c
int* pList = NULL, i = 0;

pList = (int*)malloc(sizeof(int) * 3);
//int 3개 크기의 메모리 3개를 준비해라
// 개발시점에는 모름. runtime에서 파악
pList[0] = 10;
pList[1] = 20;
pList[2] = 30;

for (i = 0; i < 3; i++)
	printf("%d %d\n", i, pList[i]);
free(pList);// 메모리 반환
```

# V. 메모리 초기화, 복사, 비교
# VI. 배열 연산자 풀어쓰기
# VII. 문자열 복사, 비교, 검색
# IX. 동적 할당된 메모리 구조와 realloc()
# X. 다중포인터(개념만)
- 싱글 포인터가 익숙해진 뒤에 볼 것
# XI. 다차원 배열에 대한 포인터
# XII. 정적 메모리와 기억불류 지정자 





[실습 예제](../c_basic/ch14Pointer/.c)


[메모리와 포인터 전체 코드](../c_basic/ch14Pointer)