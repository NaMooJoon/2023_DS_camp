#ifndef __LB_STACK_H__
#define __LB_STACK_H__

#define TRUE        1
#define FALSE       0

typedef int Data;

typedef struct _node {
    Data data;
    struct _node* next;
} Node;

typedef struct _listStack {
    Node* head;
} ListStack;

typedef ListStack Stack;


void stack_init(Stack* pstack);
/*
	- 스택의 초기화를 진행한다. 
	- 스택 생성 후 제일 먼저 호출되어야 하는 함수이다. 
*/
    
int s_is_empty(Stack* pstack);
/*
	- 스택이 빈 경우 True , 아닌 경우 False를 반환한다. 
*/
void s_push(Stack* pstack, Data data);
/*
	- 스택에 데이터를 저장한다 매개변수 data로 전달된 값을 저장한다. 
*/

Data s_pop(Stack* pstack);
/*
	- 마지막에 저장된 요소를 삭제한다. 
	- 삭제된 데이터는 반환이 된다. 
	- 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다. 
*/
Data s_peek(Stack* pstack);
/*
	- 마지막에 저장된 요소를 반환하되 삭제하지 않는다. 
	- 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야한다. 
*/




#endif