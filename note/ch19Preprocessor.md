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
# III. 매크로
## A. #define
## B. 매크로 특수화 연산자
## C. 조건부 컴파일






[전처리기 실습 코드](../c_basic/ch19Preprocessor/.c)

[전처리기 전체 코드](../c_basic/ch19Preprocessor)