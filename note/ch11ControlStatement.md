제어문(Control statement)
- 프로그래밍 언어를 가르는 핵심 근거가 될 정도로 중요한 내용
- ASCII code(사용할 수 있는 문자)를 사용해 제작
	- 항 : 상수 , 변수(메모리), 연산자
	- 식(평가): 항의 모임
	- 구문; : 식의 모임
	- 함수\{ } : 구문의 모임
- 모든 프로그램은 절차지향이고 기본적으로 위에서 아래로 흐름을 따라간다
	- 객체지향도 객체를 중시하는 것이지 절차지향이 전혀 없음을 의미하지 않는다
	- 변수는 값이 정해지지 않은 미지수이고 개발은 compile에서만 이뤄진다.
	- 사용자 입력을 받는 런타임 상황에서의 경우의 수를 고민해 입력에 따라 흐름을 조절해야한다
	- 그 흐름을 조절하는 것이 제어문

# I. if
- 분기문(Branching statement)
- 조건식이 true(1)일때만 코드블럭을 진행
- 삼항연산자와 논리적으로 유사하나 삼항연산자는 항 단위의 리턴이라면 if문은 구문 단위로 처리한다. 
## A. if
- if문 실습시 주의사항
	- 조건식 괄호 뒤에 ;를 붙여 구문을 닫지않기
	- 실행구문이 여러줄인경우 꼭 \{}로 묶고 내부의 들여쓰기를 일치시키기
```c
if(조건식) ~~~;
//조건식과 문장을 나눠서 써도 됨
if(조건식) 
	~~~;
// 코드블럭이 여러 구문인 경우 {}로 스코프를 지정한다
if(조건식){
	// 여러 구문
}
```

```dockerfile
문제1 
사용자로부터 입력 받은 정수 중 가장 큰 수를 출력하는 프로그램을 작성. 
제한사항
	정수는 부호가 있는 32비트 정수로 한정
	scanf_s함수로 한번에 한 값만 입력
	내부적으로 최댓값을 계속 갱신하는 구조로 작성
	if문 사용
출력 예시
	10
	20
	30
	MAX : 30
```
[실습코드](../c_basic/ch11ControlStatement/control_01Question.c)
3항연산자가 항 단위라면 if문은 구문 단위에서 분기를 처리한다는 차이가 있음
```dockerfile
문제2 사용자로부터 나이를 입력받아 최종요금을 계산하는 프로그램
제한사항
	정수는 부호가 있는 32비트 정수로 한정
	버스 기본요금은 1000원으로 가정
	20세 미만인 경우 25% 할인
	20세 이상인 성인은 할인 없음
	나이가 20세 이상인 경우 20으로만 출력
	if문 사용
출력 예시
	15
	나이: 15, 최종요금: 750원
	25
	나이: 20, 최종요금: 1000원 
```
[실습코드](../c_basic/ch11ControlStatement/control_02Question.c)
## B. if else
- 조건식을 만족하는 경우와 만족하지 않는 경우 수행되는 식을 배타적으로 기술 할 수 있는 제어문
- else도 ;를 사용하지 않고 여러줄인 경우 \{}로 블럭을 생성
```c 
	if (nInput <= 10)
		nSelect = 10;
	else
		nSelect = 20;
	// 3항 연산자로도 가능
	nSelect = nInput <= 10 ? 10 : 20;
```
- 사용자 입력에 있어서 범위를 처리할 수 있음
	- if 블럭 아래에서 10 초과의 nInput을 고려할 필요가 없어진다
	- 어떤 기준을 근거로 2분할 됨
	- 자료구조의 binary tree
## C. if else 중첩
- 각종 제어문 내부에 다시 제어문을 넣어서 사용할 수 있음
- 여러 밸상가능한 경위 수를 나열한 후 피라미드 식으로 분류
- 조건에 의한 분류와 선택
```
if(nInput >= 80){//대분류
	if(nInput >= 90)
		ch = 'A';
	else
		ch = 'B';
}
else{
	if(nInput >= 70)
		ch = 'C';
	else{
		if(nInput < 60)
		ch = 'F';
	}
}
```

```dockerfile
문제3: 버스 기본요금을 1000원으로 가정하고 나이에 따라 다음과 같이 할인율을 적용.
할인
	0~3		영유아		100%(무료)
	4~13	어린이		50%
	14~19	청소년		25%
	20~		성인			0%
출력 예시
	나이: 20
	요금: 1000
시작전 tip: 우선 2분할을 먼저하고 상세 분할로 나눈다
```
[실습코드](../c_basic/ch11ControlStatement/control_03Question.c)
- 구간이 특정되어있을때 다중 2분할로 2진트리를 생성할 수 있다
## D. 다중 if
- if else를 여럿 연이어 기술한 것과 같은 형식
- 여러 조건식을 사용해 범위를 점점 줄여감
- 제안되는 범위가 잘 정렬되어있는 상태에서 유용
- short circuit과 유사한 조건 판별
```c
if(nInput >= 90){
	...
}
else if(nInput >= 80) {
	...
}
else if(nInput >= 70){
	...
}

	...여러 조건...

else {
	...
}
```
- 여러 조건 중 하나인 경우 : if-else if
- 여러 조건 중 해당되는 모두인 경우 : if 여러 개

# II. 스코프 중첩과 식별자 검색 순서
- 변수의 접근 가능 범위는 해당 변수가 선언된 스코프로 제한됨(지역변수)
- 현재까지 배우고 사용한 모든 변수는 지역변수 및 자동변수 
- 자동 변수는 선언된 스코프를 넘어서면 자동으로 소멸
- 식별자(변수의 name)가 같은 경우 최근 스코프가 우선
	- 가장 최근에 선언된
	- 같은 stack frame의 변수
	- 검색 순서는 stack memory의 LIFO를 따라 검색한다
```c
//교육을 위한 예제로 실제에서는 변수명을 굳이 중복으로 짓지 않음
int main(void){
	int x=1;//1
	printf("%d\n",x); //1 stack frame
	if(x>0){
		int x = 2;//2
		printf("%d\n",x); //2 stack frame
		if(x > 1 ){
			int x = 3;//3 
			printf("%d\n",x); //3 stack frame
		}
	}
//	printf("%d",b); // b는 접근 불가
	printf("%d\n",x);//2,3은 scope를 벗어나 stack frame이 사라져 함께 소멸됨 
	// 1 stack frame 호출
}
```
- 변수
	- 지역변수: 일정 스코프 내에서만 사용할 수 있는 변수
	- 자동변수: stack memory가 호출하는 변수로 해당 stack frame을 벗어나면 자동으로 사라진다

# III. switch - case
- if-else if와 유사한 기능
	- 조건식은 비교연산이 아닌 상등식만 사용(==)
- 정보를 분류하고 경우를 선택하는 제어문
- 각 case는 상등연산시 일치하는 값에 해당하는 정수
	- 실수가 안됨을 기억 
- case는 콜론으로 끝남
- 한 case에 대해 break문 조합(생략하면 아래 case도 순차적으로 진행)
- else처럼 그외 처리는 default
```c
char charOperator = 0;
switch(charOperator){
	case '+' : 
		...
		break;
	case '-' : 
		...
		break;
	case '*' : 
		...
		break;
	case '/' : 
		...
		break;
	default:
}
```
- break가 없으면 아래 case까지 실행
```c
	case '*' : 
		구문 A
//		break;
	case '/' : 
		구문 B
		break;
		=> 구문 A > 구문 B > switch break
```
# IV. goto
- 무조건 goto
- 남아있지만 왠만하면 안쓰는 제어문
- 프로그램의 흐름을 조건 없이 즉시 변경하는 제어문
- 프로그램의 흐림이 엉킬 수 있어 대부분 사용을 권하지 않음
	- 필요에 따라 쓰일 순 있겠지만 왠만하면 안씀
	- 즉시 개입이 필요할때는 쓰기도 함.
- 사용법
	- 라벨을 지정(개입할 시점)
	- 필요 조건에 따라 goto 라벨명;으로 개입

```c
	int nInput;
INPUT:
	printf("Input Number : ");;
	scanf_s("%d", &nInput);

	if (nInput < 0 || nInput > 10)
		goto INPUT;
		// 조건에 맞지 않는 경우 재입력 요청
	
	puts("END");
}
```
- 절차적 흐름에서 역행하는 첫 코드
- 횟수를 체크하면 반복을 제한해서 처리할 수 있음 
- 조건없는 goto는 안하기
	- stream이나 OS 자원 등을 사용할때 close/clear/clean 처리를 위해 사용하기도 함
	- exception handling, validation 등에서는 사용하기도...
# V. boolean 사용하기
- C언어에는 boolean이 없음
- 이를 쓰고 싶다면 stdbool 사용
```c
#include <stdbool.h>
```

# VI. while과 무한루프
## A. while문(조건 기반 반복)
- if문과 유사한 구조
```c
while(조건문){
	코드블럭
}
```
- 조건식이 참일 경우 구간 코드를 계속 반복해서 수행
- 반복 수행 구간코드 내부에서 반복을 멈추는 연산이 반드시 있어야함
	- 조건문의 결과가 항등식-1(true)-이면 직접 멈추기 전까지 무한루프
- 무한루프는 최악의 논리오류 중 하나
	- 계속 반복하다보니 cpu 점유율이 100%로 튀어버림

## B. while 실습
```dockerfile
문제: 
사용자로부터 정수를 입력받아 그 수만큼 '*'를 출력하는 프로그램을 작성. 
사용자 입력이 범위를 넘어서면 강제로 보정
제한사항
	1~9 범위의 정수를 입력
	*은 한 행에 이어서 출력하고 전체 출력이 끝나면 개행
출력예시
	3
	* * *
	5
	* * * * *
```
[실습 예제](../c_basic/ch11ControlStatement/control_04Question.c)

# VII. for문(계수 기반 반복) 
## A. for문
- 계수기반 반복문
- 반복회수 조절에 관련된 코드를 한 행에서 볼 수 있어 와일문에 비해 상대적으로 실수 가능성이 적음
```c
for(계수 선언 ; 계수 비교 ; 계수 증감){
	// 코드 블럭
}
```
- for문의 parameter
	- 계수 선언: 코드 블럭에서 사용할 지역 변수를 선언, 초기화
	- 계수 비교: 조건식 
		- 조건식이 없으면 무한 loop
	- 계수 증감: 회차 반복시 수행할 계수 증감식
		- 단항식 : i++
		- 이항식 : i+=2
```c
for(int i = 0 ; i < 5 ; ++i){
	printf("%d\n",i);
}
```
- 특별히 회차를 외부에서 쓸일이 없는 이상 회차를 스코프 내에서만 사용하는 for문이 더 안전
## B. 실습예제
```c
문제1: 구구단
1~9단의 구구단표 출력
출력예시
	###1단 시작
	1 X 1 = 1
	...
	### 1단 끝
```
[실습 예제](../c_basic/ch11ControlStatement/control_05Question.c)
```c
문제2: 총합 출력
1~10까지 총합을 출력하는 프로그램을 작성.
제한사항
	while문과 for문으로 각각 작성
	반복회수는 10회
	총합을 누적하는 변수를 활용
출력예시
	Total: 55
```
[실습 예제](../c_basic/ch11ControlStatement/control_06Question.c)
# IX. 반복문 중첩
- 반복문도 구문이므로 다시 반복시킬 수 있다
- 1차원적 반복 출력코드를 다시 반복문으로 묶어 2차원적 구조를 출력
	- 1차원 반복 코드의 상수 중 어떤 부분을 변수로 처리할지 고민 필요
	- 규칙을 찾아 하나씩 반복처리하는 방법을 고민
- 반복에 대한 반복이 발생해 논리적으로 한층 더 복잡

# X. 실습 예제
```dockerfile
문제: 정사각형 출력
5행 5열 사각형을 *로 출력하는 프로그램 작성
그후 대각선으로 나눈 삼각형을 출력
제한사항
	for문 사용
출력예시
	*	*	*	*	*
	*	*	*	*	*
	*	*	*	*	*
	*	*	*	*	*
	*	*	*	*	*
	*	
	*	*	
	*	*	*	
	*	*	*	*
	*	*	*	*	*
```
[실습 예제](../c_basic/ch11ControlStatement/control_07Question.c)
```dockerfile
문제: * 출력 응용
아래 예처럼 삼각형을 *로 출력하는 프로그램을 작성
제한사항
	for문 사용
	*의 왼쪽 여백은 tab으로 조절
출력예시
					*
				*	*
			*	*	*
		*	*	*	*
	*	*	*	*	*
					*
				*	*	*
			*	*	*	*	*
		*	*	*	*	*	*	*
	*	*	*	*	*	*	*	*	*
```
[실습 예제](../c_basic/ch11ControlStatement/control_08Question.c)

# XI. do-while
- 반복 대상 구간코드가 조건식의 만족여부와 관계없이 무조건 한번은 실행하는 반복문
- 기존 while문과 달리 조건문 뒤에 세미콜론(;)이 있음
```c
do{
	... 코드블럭 // 실행 후
}
while(조건문); // 조건을 체크해 반복 결정
```
# XII. break와 continue
- 반복문과 switch-case문에서 사용되며 수행시 사용하는 키워드
## A. break
- 수행시 스코프를 즉시 벗어나 그 다음 구문으로 이동
- 조건과 관계없이 break가 속한 구문을 만나면 무조건 반복문 종료
```c
while(1){
	ch = getchar();
	if(ch == 'x')
		break; //여기서 스코프를 나가기때문에
	//종료
	putchar(ch); //이 부분을 수행하지 않음
}
puts("END");
```
>console)
```dockerfile
a
a
b
b
c
c
x
END
```

## B. continue
- 수행시 스코프의 해당 회차를 즉시 벗어나 그 다음 회차로 이동
- 조건과 관계없이 continue가 속한 구문을 만나면 무조건 해당회차를 넘기고 다음 회차로 이동
- 반복이 계속되기때문에 논리적으로 복잡해지는 원인이 될 수 있음에 주의
	- 정말 필요한 상황이 아니라면 안쓰는 로직 구성 권장 
```c
char ch = 0;
while (1) {
	ch = getchar();
	if (ch == 'x')
		continue; //여기서 해당 회차 스코프를 나가기때문에
	//다음회차(조건문 체크)로 이동
	putchar(ch); //이 부분을 수행하지 않음
}
puts("END");
```
>console)
```dockerfile
a
a
b
b
aaaxaaa
aaaaaa(x회차 제외)
x
(아무것도 안하고 입력대기)
x
(아무것도 안하고 입력대기)
x
(아무것도 안하고 입력대기)
```

## C. 중첩 반복문
- 반복문이 중첩됐을 경우 break/continue가 속한 반복문이 멈춤
	- 내부 반복문에서 break/continue를 수행하면 내부 반복만 멈춤 
```c
while(조건문){  // first loop
	while(조건문){ // second loop
		break; // second만 멈추고 first는 실행
	}		
}
```

[제어문 전체 코드](../c_basic/ch11ControlStatement)