#include <stdio.h>

#ifdef _DEBUG
	#define MODEMESSAGE "Debug mode"
#else
	#define MODEMESSAGE "Release mode"
#endif

#define _HAS_KEY_ 
#ifdef _HAS_KEY_
#define USER_ROLE "KEY_MAN"
#else
#define USER_ROLE "ANNONYMOUS"
#endif 


int main(int argc, char* argv[]) {
	
	puts(MODEMESSAGE);
	puts(USER_ROLE);

	return 0;
}