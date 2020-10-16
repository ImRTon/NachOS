#include "syscall.h"

main() {
	int i;
	for (i = 0; i < 5; i++) {
        		PrintInt(1); // User : Im going to sleep!
		//printf(" User : Im going to sleep!\n");
		Sleep(1000000);
		//printf("User : Im up!\n");
        		PrintInt(0); // User : Im up!
	}
	return 0;
}