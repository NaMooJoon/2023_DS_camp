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


void compress_file(char* filename) 
{
	FILE* input = 0x0;
	FILE* output = 0x0;
	int char_freq[ASCII_SIZE] = {0};

	count_ascii_freq(char_freq, filename);

	input = fopen(filename, "rb");
	output = fopen(strcat(filename, ".myzip"), "wb");
	if (input == NULL || output == NULL) {
		fprintf(stderr, "Failed to open file \n");
		return ;
	}

	my_encode_body(input, output);

	fclose(input);
	fclose(output);
}

void decompress_file(char* filename)
{
	FILE* input = 0x0;
	FILE* output = 0x0;
	
	input = fopen(filename, "rb");
	output = fopen(strcat(filename, ".unzip"), "wb");
	if (input == NULL || output == NULL) {
		fprintf(stderr, "Failed to open file \n");
		return ;
	}

	my_decode_body(input, output);

	fclose(input);
	fclose(output);
}


void my_encode_body(FILE* input, FILE* output)
{
	Buffer my_buffer;
	int byte;

	while (1)
	{
		byte = fgetc(input);
		if (byte == EOF) 
			break;

		switch (byte)
		{
		case 32:
			push_buffer(&my_buffer, output, 0b1011, 4);
			break;
		case 101:
			push_buffer(&my_buffer, output, 0b1101, 4);
			break;
		case 116:
			push_buffer(&my_buffer, output, 0b11110, 5);
			break;
		case 111:
			push_buffer(&my_buffer, output, 0b11101, 5);
			break;
		case 97:
			push_buffer(&my_buffer, output, 0b10011, 5);
			break;
		case 104:
			push_buffer(&my_buffer, output, 0b11001, 5);
			break;
		case 110:
			push_buffer(&my_buffer, output, 0b10001, 5);
			break;
		case 115:
			push_buffer(&my_buffer, output, 0b11100, 5);
			break;
		case 105:
			push_buffer(&my_buffer, output, 0b11000, 5);
			break;
		case 114:
			push_buffer(&my_buffer, output, 0b100001, 6);
			break;
		case 100:
			push_buffer(&my_buffer, output, 0b10010, 5);
			break;
		case 108:
			push_buffer(&my_buffer, output, 0b11111, 5);
			break;
		case 117:
			push_buffer(&my_buffer, output, 0b100000, 6);
			break;
		case 109:
			push_buffer(&my_buffer, output, 0b1010, 4);
			break;
		case EOF:
			push_buffer(&my_buffer, output, EOF, 8);
			push_buffer(&my_buffer, output, EOF, 8);
			break;
		default: /* Head bit is '0'. */
			push_buffer(&my_buffer, output, byte, 8);
			break;
		}

	}

}


void my_decode_body(FILE* input, FILE* output) 
{
	Buffer input_buf;
	Buffer my_buffer;
	int byte, ch;

	buffer_set(&input_buf, 0, 0);
	buffer_set(&my_buffer, 0, 0);
	while (1)
	{
		if (input_buf.idx == 0) {
			byte = fgetc(input);
			if (byte == EOF) {
				break;
			}
			buffer_set(&input_buf, byte, 8);
		}
		/* Get next bit */
		int bit = input_buf.data >> 7;
		buffer_set(&input_buf, input_buf.data << 1, input_buf.idx - 1);

		/* Push the bit into buffer */
		push_buffer(&my_buffer, output, bit, 1);

		if ((ch = get_character(&my_buffer)) != -1) {
			fputc(ch, output);
			buffer_set(&my_buffer, 0, 0);
		}
	}
}


int get_character(Buffer* buf) {
	if ((buf->data >> (buf->idx - 1)) == 0) // First bit is '0'
		return -1;
		
	switch (buf->data)
	{
	case 0b1011:
		return 32;
	case 0b1101:
		return 101;
	case 0b11110:
		return 116;
	case 0b11101:
		return 111;
	case 0b10011:
		return 97;
	case 0b11001:
		return 104; 
	case 0b10001:
		return 110;
	case 0b11100:
		return 115; 
	case 0b11000:
		return 105;
	case 0b100001:
		return 114;
	case 0b10010:
		return 100;
	case 0b11111:
		return 108;
	case 0b100000:
		return 117;
	case 0b1010:
		return 109;
	default:
		break;
	}
	return -1;
}


void buffer_set(Buffer* buf, int data, int idx)
{
	buf->data = data;
	buf->idx = idx;
}

void push_buffer (Buffer* buf, FILE* output, int data, int size)
{
	for (int i = size-1; i >= 0; i--) {
		buf->data = buf->data << 1;
		buf->data += ((data & (1 << i)) == 0)? 0 : 1;
		buf->idx++;

		if (buf->idx == 8) {
			fputc(buf->data, output);
			buffer_set(buf, 0, 0);
		}
	}
}


void count_ascii_freq (int* char_freq, char* filename) 
{
	FILE* fp = 0x0;
	char* buffer = 0x0;
	long lSize;
	size_t result;

	fp = fopen(filename, "rb");
	if (fp == NULL) {
		fprintf(stderr, "file open is failed\n");
		
	}
	
	fseek(fp, 0, SEEK_END);
	lSize = ftell(fp);
	rewind(fp);

	buffer = (char*) malloc(sizeof(char) * lSize);
	if (buffer == NULL) {
		fputs("Reading error", stderr);
		goto _error_file_read_;
	}

	result = fread(buffer, 1, lSize, fp);
	if (result != lSize) {
		fputs("Reading error", stderr);
		goto _error_file_read_;
	}

	for (int i = 0; i < lSize; i++) {
		char_freq[buffer[i]]++;
	}

_error_file_read_:
	if (fp != NULL)
		fclose(fp);
	if (buffer != NULL)
		free(buffer);
}