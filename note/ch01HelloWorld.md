
# I. 첫 프로젝트 만들어보기
## A. 프로젝트 생성

![프로젝트 구성](../img/initProject.png)

- - project name: 
- solution name:

## B. 프로젝트에 c 파일 생성
- 단축키: ctrl+shift+a
- 확장자 주의하기
	- .cpp -> C++로 컴파일
	- .c -> C로 컴파일

## C. 코딩
```C
#include <stdio.h>
// returnType functionName(parameterType){code}
int main(void) 
{//실행 코드 블럭
	printf("Hello, World\n");//문자열 콘솔 출력
	return 0;//반환값
}
```
- stdio : study, studio아님
	- standard input output의 약자

## D. 빌드 실행
- 컴파일 동작 후 링크 처리 
- 콘솔 출력 확인

```dockerfile
오후 12:40에 빌드를 시작함...
1>------ 빌드 시작: 프로젝트: HelloWorld, 구성: Debug x64 ------
1>HelloWorld.c
1>HelloWorld.vcxproj -> D:\developerFiles\workspace\c_basic\helloWorld\x64\Debug\HelloWorld.exe
========== 빌드: 1개 성공, 0개 실패, 0개 최신 상태, 0개 건너뜀 ==========
========== 빌드이(가) 오후 12:40에 완료되었으며, 01.469 초이(가) 걸림 ==========
```