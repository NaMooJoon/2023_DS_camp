#include <stdio.h>

int main ()
{
    FILE* fp = fopen("data", "rb");
    char str[4];
    for (int i = 0; i < 4; i++) {
        str[i] = fgetc(fp);
    }

    printf("%c %c %c %c \n", str[0], str[1], str[2], str[3]);

    return 0;
}