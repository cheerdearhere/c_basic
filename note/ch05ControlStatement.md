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

[제어문 전체 코드](../c_basic/ch11ControlStatement)