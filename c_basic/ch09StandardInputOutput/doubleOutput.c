#include <stdio.h>
int main(void) {
// 실수 자료 형식의 메모리 크기(바이트 단위) 출력
	printf("float size: %d\n", (int)sizeof(123.456F));
	printf("double size: %d\n", (int)sizeof(123.456));
// float 형식을 실수 형식으로 출력
	printf("F: %f\n", 123.456F); // float
// double 형식을 실수 형식으로 출력
	printf("D: %f\n", 123.456); // double
	printf("LD: %lf\n", 123.456); // long double
	printf("G: %g\n", 123.456); // long double
// 소수점 기준 반올림
	double dData = 123.456;
	printf("%f, %f\n", dData, -123.456);
	//소수점 2번째 자리에서 반올림해서 1자리까지 출력
	printf("%.1f\n", dData);
	//소수점 3번째 자리에서 반올림해서 2자리까지 출력
	printf("%.2f\n", dData);
	//소수점 4번째 자리에서 반올림해서 3자리까지 출력
	printf("%.3f\n", dData);

	printf("%8d\n", 123);

//	문제: 소수점을 포함해 12자리로 출력. 단 소수점 이하 4번째 자리에서 반올림하고 3자리까지 출력한다
	printf("%12.3f\n", dData);
	printf("%012.4f\n", dData);
	return 0;
}