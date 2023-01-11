#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE    1
#define FALSE   0

typedef int LData;

typedef struct _node 
{
    LData data;
    struct _node* next;
} Node;

typedef struct _linkedList
{
    Node* head;
    Node* cur;
    Node* before;
    int numOfData;
} LinkedList;

typedef LinkedList List;

void list_init (List* plist);
void list_insert (List* plist, LData data);

int list_first (List* plist, LData* pdata);
int list_next (List* plist, LData* pdata);

LData list_remove (List* plist);
int list_count (List* plist);

#endif