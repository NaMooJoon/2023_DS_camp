#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int num ;
	struct node * next ;
} Node ;

Node list ;

int is_contained (int num)
{
	Node * itr = list.next ;
	while (itr != 0x0) {
		if (itr->num == num)
			return 1 ;
		itr = itr->next ;
	}
	return 0 ;
}

void insert_number (int num)
{
	if (is_contained(num))
		return ;

	Node * n = (Node *) malloc(sizeof(Node)) ;
	n->num = num ;
	n->next = list.next ;
	list.next = n ;
}

void print_numbers () 
{
	Node * itr = list.next ;
	while (itr != 0x0) {
		printf("%d ", itr->num) ;
		itr = itr->next ;
	}
	printf("\n") ;
}

int main () 
{
	int input ;
	list.next = 0x0 ;

	while (1) {
		scanf("%d", &input) ;
		if (input == 0) 
			break ;
		insert_number(input) ;
	}
	print_numbers() ;
	exit(0) ;
}
