#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[]) {
	struct tm curtime = { 0 };
	time_t t = 0;

	t = time(NULL);
	//64bit unsigned int: 1970.1.1(세계협정시/ UTC, GMT) 부터의 seconds
	localtime_s(&curtime, &t);

	printf("%lld\n", t);// 초단위 출력

	char szBuffer[128] = { 0 };
	//ctime_s: 문자열로 출력(기본 폼)
	ctime_s(szBuffer, sizeof(szBuffer), &t);
	printf("%s\n", szBuffer);

	//원하는 포멧을 직접 지정
	printf("%04d-%02d-%02d\n",
		curtime.tm_year + 1900,
		curtime.tm_mon + 1,
		curtime.tm_mday);
	return 0;
}
