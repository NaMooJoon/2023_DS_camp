#include <stdio.h>
#include <stdlib.h>

int main ()
{
	FILE * pFile;
	long lSize;
	char * buffer;
	size_t result;

	pFile = fopen ( "myfile.bin", "rb" );
	if (pFile == NULL) {
		fputs("File error", stderr);
		exit(1);
	}

	fseek(pFile, 0, SEEK_END);
	lSize = ftell(pFile);
	rewind(pFile);

	buffer = (char*) malloc(sizeof(char)*lSize);
	if (buffer == NULL) {
		fputs("Reading error", stderr);
		exit(2);
	}

	result = fread (buffer, 1, lSize, pFile);
	if (result != lSize) {
		fputs("Reading error", stderr);
		exit(3);
	}

	fclose(pFile);
	free(buffer);

	return 0;
}
