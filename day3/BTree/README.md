## Binary Tree

![binary tree](https://miro.medium.com/max/1400/1*CMGFtehu01ZEBgzHG71sMg.webp)

### Header

```c
BTreeNode* make_btree_node(void);

BTData get_data(BTreeNode* bt);

void set_data(BTreeNode* bt, BTData data);
BTreeNode* get_left_sub_tree(BTreeNode* bt);
BTreeNode* get_right_sub_tree(BTreeNode* bt);

void make_left_sub_tree(BTreeNode* main, BTreeNode* sub);
void make_riht_sub_tree(BTreeNode* main, BTreeNode* sub);
```

---

### ADT

```c
BTreeNode* make_btree_node(void);
	- 이진 트리 노드를 생성하여 그 주소 값을 반환한다.
BTData get_data(BTreeNode* bt);
	- 노드에 저장된 데이터를 반환한다.

void set_data(BTreeNode* bt, BTData data);
	- 노드에 데이터를 저장한다. data로 전달된 값을 저장한다.
BTreeNode* get_left_sub_tree(BTreeNode* bt);
	- 왼쪽 서브 트리의 주소 값을 반환한다.
BTreeNode* get_right_sub_tree(BTreeNode* bt);
	- 오른쪽 서브 트리의 주소 값을 반환한다.

void make_left_sub_tree(BTreeNode* main, BTreeNode* sub);
	- 왼쪽 서브 트리를 연결한다.
void make_riht_sub_tree(BTreeNode* main, BTreeNode* sub);
	- 오른쪽 서브 트리를 연결한다.ㅠㅑㅜ
```

