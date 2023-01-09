#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int num ;
	struct node * next ;
} Node ;

int main () 
{
    Node n1, n2, n3;
    n1.num = 10;
    n1.next = &n2;

    n2.num = 20;
    n2.next = &n3;

    n3.num = 30;
    n3.next = &n1;


    Node* ptr = &n1;
    for (int i = 0; i < 5; i++) {
        printf("(%d) num: %d \n", i+1, ptr->num);
        ptr = ptr->next;
    }

    return 0;
}