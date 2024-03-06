#include <stdio.h>
typedef struct IOBUF_TEST
{
	char* pCur;
	char* pBase;
	int bufSize;
} IOBUF_TEST;

void print_iobuf(IOBUF_TEST* pBuf) {
	printf("Base\t: %p\n",pBuf->pBase);
	printf("Current\t: %p\n", pBuf->pCur);
	printf("Buffer size\t: %d\n", pBuf->bufSize);
	printf("Written size\t: %zd\n\n",pBuf->pCur - pBuf->pBase);
}

int main(void) {
	FILE* fp = NULL;
	
	// 디버거 사용을 위한 구조체 포인터 변수
	IOBUF_TEST* ioAddr = (IOBUF_TEST*)fp;

	fopen_s(&fp, "CON", "w");
	print_iobuf((IOBUF_TEST*)fp);

	fputs("Hello", fp);
	print_iobuf((IOBUF_TEST*)fp);

	fputs(" World", fp);
	print_iobuf((IOBUF_TEST*)fp);

	fclose(fp);
	return 0;
}