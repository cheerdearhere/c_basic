#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main(int argc, char* argv[]) {

	//concatenation 예시: 경로 붙이기
		//file path: 절대 경로 공통부분
	char szPath[128] = { "C:\\Program Files\\" };
	//path입력
	char szBuffer[128] = { 0 };
	printf("Input path: ");
	gets_s(szBuffer, sizeof(szBuffer));
	// 문자열 합치기
	strcat_s(szPath, sizeof(szPath), szBuffer);
	puts(szPath);

	// 길이를 체크해서 연달아 사용하기
	strcpy_s(szPath, sizeof(szPath), "C:\\Program Files\\");
	//연속으로 합칠때마다 사이즈체크를 새로 해야함
	strcat_s(szPath, sizeof(szPath), "CHS\\");
	strcat_s(szPath, sizeof(szPath), "C programming");
	puts(szPath);

	//strcat: 보안 이슈로 아래로 대체(입력받는 문자열크기 입력)
		//strcpy_s(szPath, sizeof(szPath), "C:\\Program Files\\");
		//strcat(szPath + strlen("C:\\Program Files\\"), "CHS\\");
		//strcat(szPath + strlen("C:\\Program Files\\CHS\\"), "C programming");
		// puts(szPath);
	//strcat_s 
		// szPath + 길이 > index 0에서 이동
	strcpy_s(szPath, sizeof(szPath), "C:\\Program Files\\");
	strcat_s(szPath + strlen("C:\\Program Files\\"), sizeof(szPath) - 17, "CHS\\");
	strcat_s(szPath + strlen("C:\\Program Files\\CHS\\"), sizeof(szPath) - 25, "C programming");
	puts(szPath);
	//strcpy: 정확한 주소만 알고있다면 그냥 복사해서 사용
	strcpy_s(szPath, sizeof(szPath), "C:\\Program Files\\");
	strcpy_s(szPath + strlen("C:\\Program Files\\"), sizeof(szPath) - 17, "CHS\\");
	strcpy_s(szPath + strlen("C:\\Program Files\\CHS\\"), sizeof(szPath) - 25, "C programming");
	puts(szPath);
	//sprintf사용하기
	char szOriginPath[128] = { 0 };
	char szInputBuffer[128] = { 0 };

	printf("Input path: ");
	gets_s(szInputBuffer, sizeof(szInputBuffer));

	//sizeof가 아닌 _countof 사용함을 기억
	sprintf_s(
		szOriginPath, //저장할 곳
		_countof(szOriginPath),//크기
		"C:\\Program Files\\%s",// 형식화한 문자열
		szInputBuffer//입력
	);
	puts(szOriginPath);
}