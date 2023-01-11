## Linked List의 ADT

![linked list](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20200922124319/Singly-Linked-List1.png)



### Header file

```c
void list_init (List* plist);
void list_insert (List* plist, LData data);

int list_first (List* plist, LData* pdata);
int list_next (List* plist, LData* pdata);

LData list_remove (List* plist);
int list_count (List* plist);

void set_sort_rule (List* plist, int (*comp) (LData d1, LData d2));
```



### ADT

> Operation
>
> ```c
> void list_init (List* plist);	
>   - 초기화할 리스트의 주소값을 인자로 전달한다
> 	- 리스트 생성후 제일 먼저 호출되어야 하는 함수이다
>     
> void list_insert (List* plist, LData data);
> 	- 리스트에 데이터를 저장한다. 매개변수 data에 전달된 값을 전달한다.
>     
> int list_first (List* plist, LData* pdata);
> 	- 첫번째 데이터를 pdata가 가리키는 메모리공간에 저장한다.
> 	- 데이터의 참조를 위한 초기화가 진행된다.
> 	- 참조성공시 1, 실패시 0이 반환된다.
>     
> int list_next (List* plist, LData* pdata);
> 	- 참조된 데이터의 다음 데이터가 pdata가 가리키는 메모리공간에 저장된다.
> 	- 순차적인 참조를 위해서 반복호출이 가능하다.
> 	- 참조를 새로 시작하려면 LFirst함수를 호출해야 한다.
>   - 성공시 1, 실패시 0 리턴.
> 
> LData list_remove (List* plist);
> 	- LFirst혹은 LNext함수를 통해서 마지막으로 참조한 데이터를 참조한다.
> 	- 삭제된 데이터는 반환된다.
> 	- 마지막 참조데이터를 삭제하므로 연이은 함수호출이 불가능하다.
>     
> int list_count (List* plist);
> 	- 리스트에 저장되어 있는 데이터 수를 반환한다.
> ```
>
> 