#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[]) {
	struct tm curtime = { 0 };
	time_t t = 0;

	t = time(NULL);
	//64bit unsigned int: 1970.1.1(����������/ UTC, GMT) ������ seconds
	localtime_s(&curtime, &t);

	printf("%lld\n", t);// �ʴ��� ���

	char szBuffer[128] = { 0 };
	//ctime_s: ���ڿ��� ���(�⺻ ��)
	ctime_s(szBuffer, sizeof(szBuffer), &t);
	printf("%s\n", szBuffer);

	//���ϴ� ������ ���� ����
	printf("%04d-%02d-%02d\n",
		curtime.tm_year + 1900,
		curtime.tm_mon + 1,
		curtime.tm_mday);
	return 0;
}
