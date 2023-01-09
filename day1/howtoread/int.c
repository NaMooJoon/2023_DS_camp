#include <stdio.h>

int main ()
{
    FILE* fp = fopen("data", "rb");
    int num;
    fread(&num, sizeof(int), 1, fp);

    printf("result %d\n", num);

    return 0;
}