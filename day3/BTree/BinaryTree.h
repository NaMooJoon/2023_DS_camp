#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _bTreeNode
{
    BTData data;
    struct _bTreeNode* left;
    struct _bTreeNode* right;
} BTreeNode;

BTreeNode* make_btree_node(void);

BTData get_data(BTreeNode* bt);

void set_data(BTreeNode* bt, BTData data);
BTreeNode* get_left_sub_tree(BTreeNode* bt);
BTreeNode* get_right_sub_tree(BTreeNode* bt);

void make_left_sub_tree(BTreeNode* main, BTreeNode* sub);
void make_right_sub_tree(BTreeNode* main, BTreeNode* sub);

#endif