#include <stdio.h>
int TestFunc(void); 
int main(int argc, char* argv[]) {

	TestFunc();
	TestFunc();
	TestFunc();
	TestFunc();

	return 0;
}
int TestFunc(void) {
	static int nStaticData = 10;// local, static
	int nLocalData = 10;// local
	++nLocalData;
	++nStaticData;
	printf("\tlocal: %d/ static local:  %d\n", nLocalData, nStaticData);
	return nLocalData;
}