#include <stdio.h>

int main ()
{
    FILE* fp = fopen("data", "wb");
    int num = 825177405;

    fwrite(&num, sizeof(num), 1, fp);

    return 0;
}