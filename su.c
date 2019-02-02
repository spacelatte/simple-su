
#include <stdio.h>
#include <errno.h>
#include <error.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

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
		retval = seteuid(fstat.st_uid);
	} else {
		retval = seteuid(atoi(argv[1]));
	}
	if(retval)
		printf("result: %d\n", retval);
		perror("setuid");
		return retval;
	}
	if(argc < 3) {
		return execlp("sh", "$SHELL", NULL);
	}
	return execvp(argv[2], &(argv[2]));
}
