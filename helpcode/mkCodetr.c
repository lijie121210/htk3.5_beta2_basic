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

	if (argc != 5) {
		printf("How many file names?");
	}

	char fcount[BUFLEN+1];
	char fprefix[BUFLEN+1];
	char fipath[BUFLEN+1];
	char fopath[BUFLEN+1];
	int count;
	int i;
	char fbuf[BUFLEN+1];

	FILE *fd;

	// first is file count
	strcpy(fcount, argv[1]);

	// 2. file type: S or T
	strcpy(fprefix, argv[2]);

	//3. input file path
	strcpy(fipath, argv[3]);

	//4. output file path
	strcpy(fopath, argv[4]);

	fd = fopen( "./codetr.scp", "w" );
	if (fd == (FILE *)NULL) {
		printf("fail to create file\n");
	}

	count = atoi( fcount );

	for (i=0; i<count; ++i) {
		snprintf(fbuf, BUFLEN, "%s%s%04d.wav %s%s%04d.mfc\n", fipath, fprefix, i+1, fopath, fprefix, i+1);

		fputs(fbuf, fd);

		printf("writing %s\n", fbuf);
	}

	fclose(fd);

	printf("Done\n");

	return 0;
}
