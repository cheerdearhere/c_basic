# I. 전처리기(선행처리기/ preprocessor)?
- Compiler 실행 전에 선행처리
	- header 파일(.h)
	- 조건부 컴파일
	- 심볼릭 상수
	- 매크로 
- #pragma: 가장 전문적인 영역
	- 여기서 배운건 pack()
	- 나머지는 필요할때... 사용
- #기호로 시작

# II. Include
- 헤더 파일(선언 코드가 들어있는 파일)을 소스코드에 합쳐주는 기능
	- 선언: .h
	- 정의: .c
- #include 헤더파일
	- <헤더파일명.h>: 컴파일러가 정의하고있는 시스템 헤더파일
		- alt + F7 > VC++디렉터리 > 일반 > 포함 디렉터리 
		- stdio.h파일 위치(소속 메서드를 선택하고 F12를 누르면 위치를 볼 수 있음)
		- 자세한 코드는 볼수없음
		- 수정하면 visual studio를 재설치해야함
			- 공용 빌드는 손대지 않는 것이 일반적
			- 수정이 필요할 때도 매우 신중
		- 경로를 지정해서 사용도 가능하나 굳이 그러지않음
	- "헤더파일.h": 현재 경로기준 파일 검색(다른 디렉토리라면 경로 표기)
		- 절대경로, 상대경로 사용
		- 선언만 해놓고 정의하지 않으면 Link 에러 발생
		- 보통 솔루션 내 프로젝트 내에서 공유하는 코드들을 사용
		- #pragma once: include를 여러번하지 않고 공용으로 사용
			- 헤더 파일 내에서 다른 헤더파일이 인용되는데 여러번 중복 인용한 경우를 조심
			- pragma once를 안쓰면 중복 정의로 인한 에러가 발생할 수 있음
- 모듈???
	- 구조와 개념어로 언어마다 조금씩 다를 수 있다.
		-  Block, chunck, Stream 처럼 
	- .exe/ .lib 단위
		- runtime은 DLL
	- java에서는 .class 단위로 JVM을 위한 언어 모듬
		- C/C++과는 개념이 조금 다름
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
- 형한정어 const처럼 심볼릭 상수를 정의할 수 있는 전처리기
- 정의한 상수는 컴파일 전에 적용되어 소스코드를 치환
- 매크로를 정의할때도 사용됨

## A. 매크로
- #define 전처리기로 정의
- 형태는 함수처럼 보이지만 함수가 아니다.
- legercy code에서는 사용되고있으나 현재는 큰 매리트가 없다. 

## B. 함수와의 차이
- call과 stack memory 사용...
- 함수 호출로인한 overhead가 발생
- 이를 보완하기 위해 사용되던 것이 매크로
- 단, 컴파일러 최적화로 overhead 발생량이 줄어들면서 매크로도 사용빈도가 줄어듦

## C. 매크로 선언
```c

#define ADD_MACRO(a,b)( a + b )

```
## D. 매크로 사용
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
- 결과는 같음

## E. 매크로 특수화 연산자
- 특수화 연산자(#) 하나가 붙으면 뒤의 데이터를 문자열로 변환
- a##b: a 뒤에 b를 붙임
	- 문자열을 붙이는 것이 아닌 소스코드 자체를 붙임
```c
#define STRING(a) #a
#define PASTER(a, b) a##b
```
- 실행 예시
```c
	int nData = 10; 

	printf("nData\t: %d\n", nData);
	printf("nDa##ta\t: %d\n", PASTER(nDa, ta));// 문자열이 아닌 소스코드 자체를 붙임
	printf("#nData\t: %s\n", STRING(nData));//"nData"
```
>console)
```
nData   : 10
nDa##ta : 10
#nData  : nData
```
- 이처럼 꼭 필요한 경우가 아니라면 그냥 있는 매크로부터 잘쓰자

## F. 조건부 컴파일
- 조건을 배타적으로 처리해서 조건에 따라 코드를 변환시킴
- 상수 정의 여부에 따라 실제 컴파일되는 코드가 달라짐.
	- JSP의 action tag와 같은 기능
- #ifdef, #else, #endif로 구성
- 프로젝트 설정 화면에서 속성을 변경했던 것들
	- Debug/Release 빌드 선택
	- 문자열 처리시(MBCS, Unicode) 선택
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
	
	puts(MODEMESSAGE);// 실행 방식(debug/ runtime)에 따라 출력 메세지가 달라짐

	return 0;
}
```
- 조건부 컴파일을 가장 자주 사용하는 분야: unicode
	- 한글은 ASCII가 아니기때문에 unicode를 사용.
	- 한글은 2bytes이기때문에 길이는 6이지만 글자수는 3개가 되어버림
- 코덱이 변경되면서 
	- char > wchrt_t 
	- printf() > wprintf()
- 이를 처리하기위한 전처리(조건부 컴파일)
- MYUNICODE의 상태에 따라 일반 문자열인지 유니코드인지 처리를 다르게함
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
- 설정 변경에따라 처리가 변경됨
```
	TCHAR szData[16] = _T("Test string");
	PRINT(_T("%s\n"), szData);
	PRINT(_T("%zd, %zd\n"), sizeof(TCHAR), sizeof(szData));
```
- 물론 빌드분야를 다루는 것은 신입이 쓰지는 않으니 이런게 있다 정도만
- 더 공부하고 싶다면 #pragma


[전처리기 전체 코드](../c_basic/ch19Preprocessor)