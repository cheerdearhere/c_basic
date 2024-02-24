C언어의 중요한 주제 3가지 
	Function, Pointer, File Input/Output

# I. int main(void) {\}
- C언어의 시작과 끝
	main함수로 시작해서 main으로 끝남
- 실행 단위
- 프로젝트 내에서 main()는 반드시 있어야한다
- 시스템 내에서 자동으로 호출하는 함수

# II. 사용자 정의 함수
- 사용자가 직접 작성한 함수
## A. 구조
- returnType functionName(parmeters...){\
	... 코드 블럭
}
```c
int main(void){
	return 0;
}
```
- 호출자 함수와 피호출자 함수로 관계를 규정할수 있음
	= binding
	- 바인딩 시점에 따라(수업범위를 벗어남)
		- static binding : compile/link time
		- dynamic binding : runtime
- 호출자는 피호출자 함수의 매개변수 초깃값을 기술해야할 의무가 있음
	= 매개변수가 정의되어있다면 필수 입력 
- 피호출자 함수는 호출자 함수에게 값을 반환
	= return 키워드로 표시
```c
int Add(int a, int b){
	int nData = 0;
	nData = a + b;
	return nData;
}
```
### 1. 매개변수(parameter)
- 보통 read 권한만 사용(write로 쓰는 경우는 거의..)
- void: 없음
- 여러개를 병기할 경우 나열연산자(,) 사용
- 적을때는 'type parameterName' 형식으로 표기
### 2. {\}과 return
- 제어구문때 살펴본 스코프와 같은 개념
- 단, returnType에 맞게 return 키워드를 사용해야 함
	- returnType이 void가 아니라면 반드시 return 필요 
- return을 통해 반환하는 것은 nData라는 메모리 주소가 아닌 그 메모리에 저장된 값을 반환.
	- 연산의 임시결과를 반환하는 것도 가능
```c
	return a + b;
```
- method가 반환된 값을 같은 타입의 변수에 대입연산자(=)를 사용해 보관할 수 있다. 
```c
int main(void){
	...

	int nResult = 0;
	nResult = Add(3,4);
	
	...
}
```
- 반환값을 보관할 변수를 지정하지 않으면 연산은 진행되지만 그 결과는 휘발됨(연산의 중간값처럼 처리)
```c
Add(3,4);//값은 저장안됨
```
### 3. 함수의 이름
- 이름은 식별자
	- 변수: 메모리
	- 배열: 배열의 0번째 요소의 주소
- 함수의 이름도 배열과 같이 주소 = R-value
- 데이터를 저장하는 것이 아닌 실행코드(기계어)가 보관됨: native code
	- read only 
### 4. 함수호출 연산자 '()'
- 함수를 호출할때 사용

## B. main과의 관계
- main 함수는 사용자가 호출하지 않음에 주의
- c언어는 기본적으로 절차지향이기때문에 선언 > 정의 > 사용순
	- 함수도 마찬가지로 main보다 윗줄에 선언되어야 main에서 사용할 수 있다
### 1. 용어 정리
- 보통 main 함수에서 다른 함수를 호출(call)해 사용
```c
int main(void){
	...

	int nResult = 0;
	nResult = Add(3,4);
	
	...
}
```
- 호출관계에서 
	- 호출을 한 함ㅅ수: Caller(호출자)
		- 매개변수 정의의 의무
	- 피호출 함수: Callee(피호출자)
		- 반환 값 정의의 의무 
- 디버거 메세지에서도 나오기때문에 기억해두자
### 2. 제어의 흐름
- main() 진행 
- main Add(매개변수) 호출
	- Add() 진행
	- Add return
- main의 Add 호출부에 반환
- main 진행
- main return

* 주의!! 
함수로 전달되는 배열(parameter로 전달)은 포인터로 전달되므로 
피호출자 함수에서 배열의 크기를 sizeof 연산자를 사용해구할 수 없다. 
* 배열의 크기를 매개변수로 따로 보내도록 해야함
* 나중에 포인터때 다시
### 3. 호출
- 변수에 결과를 넣어서 사용
```c
	max = GetMax(10, 15, 3);
	printf("max: %d\n", max);
```
- 함수를 바로 값처럼 사용
```c
	printf("%d\n",GetMax(2,3,1) * 2); // 함수를 직접 사용 가능
```
- 함수 결과를 변수에 저장하는 것과 값처럼 사용하는 방법
	- 가독성을 낮추고 문제를 야기할 가능성이 높아 권장하지 않는다
	- 가능하다는 것만 기억
```c
	printf("%d\n", max = GetMax(3,1,2));// 변수에 넣어서 그 결과를 입력할 수 있다
```

# III. 라이브러리
## A. C Runtime Library(CRL)
- c언어의 실행을 돕는 함수 집합
- stdio.h: standard(std) input(i) and output(o). h(header에서 작동)
## B. Software Development Kit(SDK)
- 개발에 유용한 라이브러리, API 집합
## C. Application Programing Interface(API)
- 기능 제공을 위해 만들어진 함수

# IV. 기초적인 함수 설계 원칙
## A. UI와 기능은 반드시 분리(캡슐화)
- UI : client가 만나는 부분. input과 output만 표시
- 기능: 기능을 담당하는 부분으로 굳이 외부에 표시하지 않아도 될 부분
ex) front-end, back-end
## B. 재사용 가능한 단위 코드는 함수로 구현(DRY 원칙)
- Don't Repeat Yourself(DRY 원칙) : 자기 코드를 copy하다보면 어지러운 문제가 발생. 가능하면 단위 코드로 뽑아 관리
- 추후 유지보수에 있어서 단순 복붙은 복붙한 모든 곳을 수정해야한다 
- 같은 기능을 3번 이상 붙여넣기를 하고 있다면 고민이 필수다
## C. 함수명은 기능을 대변해야한다
- 함수의 이름은 함수가 무엇하는지를 표시해야한다. 
- 상세한 기능구분을 위해 이름이 너무 길어질것 같으면 주석 사용
- 하지만 가장 좋은 이름은 주석없이 이름으로만 이해할 수 있는 이름
- 물론 좋은 이름이라도 주석으로 추가하는 것이 좋음
```c
int GetFactorial(int nParam) {
	int nResult = 1, i = 0;
	if (nParam < 1 || nParam > 10) {
		puts("ERROR: 1~10 사이의 정수를 입력해야합니다.");
		return 0;
	}
	for (i = 1; i <= nParam; i++) {
		nResult *= i;
	}
	return nResult;
}
```
- 메세지는 UI의 기능. 메세지를 전달하는 것과 기능을 담당하는 것을 나누는 것이 더 좋은 함수
```c
/*private function == 기능 담당*/
int CalculateFactorial(int nParam) {
	int nResult = 1, i = 0;
	for (i = 1; i <= nParam; i++) {
		nResult *= i;
	}
	return nResult;
}
/*public function == UI 담당*/
void GetFactorial(void) {
	int nResult = 0, nInput = 0;
	printf("계승을 구할 정수(1 ~ 10)을 입력하세요: ");
	scanf_s("%d", &nInput);
	if (nInput < 1 || nInput > 10) {
		printf("ERROR: 1~10 사이의 정수를 입력해야합니다\n사용자 입력: %d\n",nInput);
	}
	else {
		nResult = CalculateFactorial(nInput);
		printf("%d! : %d\n", nInput, nResult);
	}
}
```
- main을 UI로 사용해도 됨

## D. 함수의 원형 선언
- 함수 원형(함수 시그니처): 
	returnType methodName(parameterType paramterName, ...)
```c
int main(void);//여기까지
```
- 코드블럭 구현은 진행하지 않은 상태
- 함수의 선언과 정의를 분리
- 함수 바디(코드블럭)없이 원형만 기술할 경우 함수 시그니처라고 부르기도함
- 함수 원형 선언에서는 매개변수 이름은 생략가능
- 굳이 하는 이유: 컴파일러에게 함수의 존재를 알리기위해 분리한 선언을 코드 상단에 기술
	- 컴파일을 할때 윗줄에서 아래로 내려가면서 진행
	- 이때 함수의 구체적 코드를 나중에
		- main함수보다 아래에 정의한 경우
		```c
		int Add(int, int); //시그니처 선언
		int main(void){
			printf("%d\n",Add(3,4));
			return 0;
		}
		int Add(int a, int b){//함수 정의
			return a+b;
		}
		```
		- 다른 파일에 함수를 넣은 경우(분할 컴파일): 아래에서
		```c			#include <stdio.h>// header파일도 하나의 분할 컴파일
			int Add(int, int); //시그니처 선언
			int main(void){
				printf("%d\n",Add(3,4));
			// 솔루션의 시작 프로젝트 내에 .c파일이 있다면 진행
				return 0;
		```
- 선언만 하고 정의를 하지 않은 경우 
	- 컴파일은 진행되지만 링크에서 오류가 발생
	- 컴파일과 에러를 동시에 하는 빌드는 당연히 에러
		- message: (대상) 함수에서 참조되는 확인할 수 없는 외부 기호
- 선언부와 정의부는 returmType과 parameter의 Type, 수가 같아야한다

### 1. 분할 컴파일
- 한 프로젝트에 여러 소스코드 파일(.c)을 운영하는 경우 각각을 개별 컴파일
```c
//분할 컴파일: 다른 소스파일에서 가져옴
int CalculateFactorial(int);

int main(void) {
	printf("from factorial.c: %d\n", CalculateFactorial(5));
	...
```
- 빌드를 통해 생성된 obj파일들이 모여 exe파일을 생성(compile + link = build)
- 개별 소스코드에 대한 목적파일 생성
- 변수나 함수 <b style="color:red">선언과 정의가 다른 파일로 분리</b> 될 수 있음
	- 컴파일은 따로하기때문에 놓치는 경우가 발생
- 링크 오류에 주의!!
- 개인은 관리용도이다보니 편할 수 있지만 협업때는 중요한 문제가 발생
- 모듈화나 그런 문제는 경험을 쌓고 생각
- 같은 프로젝트 내에 같은 이름에 메서드가 존재하면(솔루션의 시작프로젝트 내에) 다중 선언으로 에러 발생
- 선언부를 헤더에 선언해 놓으면 상단에 선언하지 않아도 링크가 처리된다
```c
#include "func.h"
```
>#pragma once
void GetFactorial(void);
- 우선은 이런게 있다.. 정도만

## E. 실습 문제
```dockerfile
사용자로부터 세 정수를 입력받아 최대값을 반환하는 프로그램
제한사항
	사용자 입력과 최댓값 계산 코드를 별도 함수로 분리
출력예시
	(입력은 자유롭게, 사용자 친화적으로)
	MAX: 5
작성 팁
	함수 원형부터 생각해보자
```
[실습 예제](../c_basic/ch13Function/function_01Question.c)

# V. 이벤트 루프 - event loop
- 명칭 해석
	- 이벤트: 주로 사용자의 하드웨어적 입력 발생을 가리킴
		ex) 키 입력, 마우스 입력 등
	- 루프: 반복
- main()에서 사용자 인터페이스 출력 및 사용자 입력을 반복하는 구조
- 보통 메뉴 출력과 사용자 선택을 확인
	- 반복문에서 이벤트를 대기
	- 반복문 내부에 switch-case로 처리
	- 그중 하나는 루프를 벗어날 로직 필수
- 메뉴 선택에 따라 기능을 수행
- 대부분의 응용 프로그램이 채택하는 일반적 구조
	- 특히 GUI는 더욱 
- 당연한 것이지만 반드시 고려
- cmd에서 유용한 코드
	- 기존 메세지 지움: system("cls");
- 사용자 입력에 대해 어떤 문제가 생긴 경우 
	- 연산이 지연(suspanded)되다가 
	- OS의 판단에 의해 응답 없음이 출력된다 

# VI. 전역변수와 식별자 검색 순서
## A. 전역변수(<-> 지역변수)
- 함수 바디(코드블럭) 밖에서 선언
- 접근 범위가 제한되면 지역변수
## B. 식별자 검색 순서
- 제어문 scope와 같은 방식. 
	1. 지역 스코프
	2. 최대 함수 바디
	3. 최대 로컬 파일
	4. 외부 파일
## C. 전역변수를 어떻게 쓸까?
- <b style="color:red">꼭 필요하지 않은 경우 굳이 쓰지 않는다</b>
- 지역변수는 스코프의 lifecycle을 따르기때문에 자동으로 관리되는 자동변수
- 전역변수는 정적 영역으로 관리를 직접 진행해야한다
- 특정 전역변수에 대해 여러 함수들이 의존하게되면 문제가 발생한다
- 전역 변수가 없는 프로그램이 좋은 프로그램이라 할 정도 
- C# 같은 언어들도 전역변수라는 문법 자체가 없을정도
	- java에도 있으나 static final이 아닌이상 가능한 쓰지 않음
- 내부에 선언이 없어도 동작...
	- 편해보이겠지만 다른 모든 함수가 접근하기에 위험
	- 전역변수와 같은 이름으로 초기화하면 변수명 중복 에러
	- remote(external)... 
		- 정말 쓰고싶다면 extern 키워드로 표시.
		- 생략 가능하지만 문제가 발생할 수 있음
		- extern을 함수 바디에 쓰면 지역변수처럼 쓸 수 있긴함(같은 파일의 다른 함수에서는 접근 x) 
```c
	//다른 곳에서 전역변수에 접근하는 경우
	extern int g_input;
```
- 역시 가능한 안쓰는게...

[함수 전체 코드](../c_basic/ch13Function)