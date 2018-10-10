
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
	/*
	for(int i=0; i<argc; i++) {
		printf("[ %2d ]: %s\n", i, argv[i]);
		continue;
	}
	*/
	struct stat fstat;
	stat(argv[0],&fstat);
	int retval;
	if(argc < 2) {
		retval = setuid(fstat.st_uid);
	} else {
		retval = setuid(atoi(argv[1]));
	}
	//printf("result: %d\n", retval);
	if(argc < 3) {
		execlp("sh", "$SHELL", NULL);
		return 0;
	}
	execvp(argv[2], &(argv[2]));
	return 0;
}
