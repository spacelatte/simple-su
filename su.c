
#include <stdio.h>
#include <errno.h>
//#include <error.h>
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
	int id = (argc < 2) ? fstat.st_uid : atoi(argv[1]);
	int retval = setuid(id);
	if(retval) {
		printf("result: %d\n", retval);
		perror("setuid");
		return retval;
	}
	seteuid(id);
	return (argc < 3) ? execlp("sh", "rt", NULL) : execvp(argv[2], &(argv[2]));
}
