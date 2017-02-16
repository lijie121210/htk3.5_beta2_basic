#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>


#define BUFLEN 1024


// EProm inputpath outputpath


int main(int argc, const char *argv[]) {

	FILE *fout;
	FILE *fin;
	char fibuf[BUFLEN+1];
	char fobuf[BUFLEN+1];
	int i;
	int j;
	int t;
	char senbuf[BUFLEN+1];

	fin = fopen(argv[1], "r");
	if (fin == NULL) {
		printf("Open file error: %s", argv[1]);
		return 0;
	}

	fout = fopen( argv[2], "w" );
	if (fout == (FILE *)NULL) {
		printf("fail to create file\n");
		return 0;
	}

	while ( fgets(fibuf, BUFLEN, fin) ) {

		if (fibuf != NULL && strlen(fibuf) >= 11 && fibuf[6] == '.' && fibuf[7] == 'l' && fibuf[8] == 'a' && fibuf[9] == 'b') {
			fobuf[0] = '\"';
			fobuf[1] = '*';
			fobuf[2] = '/';

			t = 3;
			j = 1;
			while ( fibuf[j] != '\0') {
				fobuf[t] = fibuf[j];
				++j;
				++t;
			}
			fobuf[t] = '\0';

			fputs(fobuf, fout);
		} else {
			fputs(fibuf, fout);
		}

	}

	fclose(fout);
	fclose(fin);

	printf("Done\n");

	return 0;
}