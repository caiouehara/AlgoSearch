#ifndef avltree
#define avltree
#include "./binary_search_tree.h"

template <class TreeEntry>
class AVLTree : public BinarySearchTree<TreeEntry>
{

public:
    void searchInsert(TreeEntry x);
    void searchInsert(TreeEntryArray<TreeEntry> x, int n);

private:
    using typename BinarySearchTree<TreeEntry>::TreeNode;
    using typename BinarySearchTree<TreeEntry>::TreePointer;
    using BinarySearchTree<TreeEntry>::root;

    void rSearchInsert(TreeEntry x, TreePointer &pA, bool &h);
};

#endif