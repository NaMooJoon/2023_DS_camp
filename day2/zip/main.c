#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ASCII_SIZE	256
#define STR_SIZE	128

typedef enum {
	compress = 1,
	decompress,
} Menu;

typedef struct buffer {
	char data;
	int idx;
} Buffer;


void count_ascii_freq(int* char_freq, char* filename);
void buffer_set(Buffer* buf, int data, int idx);
void push_buffer (Buffer* buf, FILE* output, int data, int size);

/* compress */
void compress_file(char* filename);
void my_encode_body(FILE* input, FILE* output);

/* decompress */
void decompress_file(char* filename);
void my_decode_body(FILE* input, FILE* output) ;
int get_character(Buffer* buf);

void print_menu() 
{
	printf("=== HUFFMAN COMPRESS PROGRAM === \n");
	printf("Which mode do you want?\n");
	printf("(1) compress,  (2) decompress\n");
	printf("> ");
}

int main () {
	int menu;
	char filename[STR_SIZE];

	print_menu();
	scanf("%d", &menu);

	switch (menu) {
		case compress:
			printf("compress!\n");
			printf("Enter the target file > ");
			scanf("%s", filename);
			compress_file(filename);

			break;
		case decompress:
			printf("decompress!\n");
			printf("Enter the target file > ");
			scanf("%s", filename);
			decompress_file(filename);

			break;
		default:
			printf("Wrong input...\n");
			printf("Bye!!\n");
			break;
	}

	printf("Done..!!\n");

	return 0;
}