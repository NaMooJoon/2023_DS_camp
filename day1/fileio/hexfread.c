#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[])
{
	FILE * pFile;
	long lSize;
	char* buffer;
	size_t result;

	pFile = fopen ( argv[1], "rb" );
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

	for (int i = 0 ; i < lSize; i++) {
		printf("%02x", buffer[i]);
		if((i+1) % 2 == 0)
			printf(" ");
		if((i+1) % 16 == 0)
			printf("\n");
	}
	printf("\n");


	fclose(pFile);
	free(buffer);

	return 0;
}
