#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>


#define BUFLEN 1024

int main(int argc, const char *argv[]) {

	if (argc != 3) {
		printf("How many file names?");
	}

	char fcount[BUFLEN+1];
	char fprefix[BUFLEN+1];
	int count;
	int i;
	char fbuf[BUFLEN+1];
	char fpath[BUFLEN+1];
	FILE *fd;

	// first is file count
	strcpy(fcount, argv[1]);

	// 2. file type: S or T
	strcpy(fprefix, argv[2]);

	if (strcmp("S", fprefix) == 0) {
		strcpy(fpath, "./trainsoundfeatures/");
	} else {
		strcpy(fpath, "./testsoundfeatures/");
	}

	fd = fopen( "./train.scp", "w" );
	if (fd == (FILE *)NULL) {
		printf("fail to create file\n");
	}

	count = atoi( fcount );

	for (i=0; i<count; ++i) {
		snprintf(fbuf, BUFLEN, "%s%s%04d.mfc\n", fpath, fprefix, i+1);

		fputs(fbuf, fd);

		printf("writing %s\n", fbuf);
	}

	fclose(fd);

	printf("Done\n");

	return 0;
}
