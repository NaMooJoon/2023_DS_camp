#include <stdio.h>
#include "ListBasedStack.h"

int main (void)
{
    /* Stack의 생성 및 초기화 */
    Stack stack;
    stack_init(&stack);

    /* 5개의 데이터를 넣어주기 */
    s_push(&stack, 11);
    s_push(&stack, 22);
    s_push(&stack, 33);
    s_push(&stack, 44);
    s_push(&stack, 55);

    /* 데이터를 꺼내서 출력하기 */
    while (!s_is_empty(&stack))
        printf("%d ", s_pop(&stack));


    return 0;
}