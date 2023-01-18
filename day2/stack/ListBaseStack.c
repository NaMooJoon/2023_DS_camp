#include <stdio.h>
#include <stdlib.h>
#include "ListBasedStack.h"


void stack_init(Stack* pstack) 
{
    pstack->head = NULL;
}

void s_push(Stack* pstack, Data data)
{
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = pstack->head;

    pstack->head = new_node;
}

Data s_pop(Stack* pstack)
{
    Data rdata;
    Node* rnode;

    if (s_is_empty(pstack)) {
        printf("Stack memory error!");
        exit(-1); // 비 정상적인 종료
    }

    rdata = pstack->head->data;
    rnode = pstack->head;

    pstack->head = pstack->head->next;
    free(rnode);

    return rdata;
}

Data s_peek(Stack* pstack)
{ 
    if (s_is_empty(pstack)) {
        printf("Stack memory error!");
        exit(-1); // 비 정상적인 종료
    }

    return pstack->head->data;
}


int s_is_empty(Stack* pstack) 
{
    if (pstack->head == NULL) 
        return TRUE;
    else
        return FALSE;
}