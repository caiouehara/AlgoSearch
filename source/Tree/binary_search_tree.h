#ifndef binary_search_tree
#define binary_search_tree
#include "./binary_tree.h"

template <class TreeEntry>
class BinarySearchTree : public BinaryTree<TreeEntry>
{
public:
    TreeEntry minimun();
    TreeEntry maximum();

    bool remove(TreeEntry x);
    void searchInsert(TreeEntry x);
    bool search(TreeEntry x);
    void insert(TreeEntry x);
    void insert(TreeEntryArray<TreeEntry> array, int size);
    // predecessor e sucessor

protected:
    using typename BinaryTree<TreeEntry>::TreeNode;
    using typename BinaryTree<TreeEntry>::TreePointer; 
    using BinaryTree<TreeEntry>::root; 
    
private:    
    TreeEntry rMinimun(TreePointer &t);
    TreeEntry rMaximus(TreePointer &t);

    void rSearchInsert(TreeEntry x, TreePointer &t);
    bool rSearch(TreeEntry x, TreePointer &t);

    bool rRemove(TreeEntry x, TreePointer &p);
    void removeMin(TreePointer &q, TreePointer &r);

};

#endif