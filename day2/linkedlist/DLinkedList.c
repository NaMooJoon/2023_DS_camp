#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void list_init (List* plist)
{
    plist->head = (Node*) malloc (sizeof(Node));
    plist->head->next = NULL;
    plist->numOfData = 0;
}


void list_insert (List* plist, LData data)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->head->next;
    plist->head->next = newNode;

    (plist->numOfData)++;
}

int list_first (List* plist, LData* pdata)
{
    if (plist->head->next == NULL)
        return FALSE;
    
    plist->before = plist->head;
    plist->cur = plist->head->next;

    *pdata = plist->cur->data;
    return TRUE;
}

int list_next (List* plist, LData* pdata)
{
    if (plist->cur->next == NULL)
        return FALSE;
    
    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return TRUE;
}

LData list_remove (List* plist) 
{
    Node* rpos = plist->cur;
    LData rdata = rpos->data;

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;

    free(rpos);
    (plist->numOfData)--;
    return rdata;
}

int list_count(List* plist)
{
    return plist->numOfData;
}

