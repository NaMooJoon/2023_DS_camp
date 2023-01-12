#include <stdio.h>
#include "BinaryTree.h"

int main(void)
{
    BTreeNode* bt1 = make_btree_node();
    BTreeNode* bt2 = make_btree_node();
    BTreeNode* bt3 = make_btree_node();
    BTreeNode* bt4 = make_btree_node();


    set_data(bt1, 1);
    set_data(bt2, 2);
    set_data(bt3, 3);
    set_data(bt4, 4);

    make_left_sub_tree(bt1, bt2);
    make_right_sub_tree(bt1, bt3);
    make_left_sub_tree(bt2, bt4);

    printf("%d \n", get_data(get_left_sub_tree(bt1)));
    printf("%d \n", get_data(get_left_sub_tree(get_left_sub_tree(bt1))));

    return 0;
}