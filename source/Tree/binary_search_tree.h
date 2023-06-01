#ifndef binary_search_tree
#define binary_search_tree
#include "./binary_tree.h"
    class BinarySearchTree: public BinaryTree
    {
    public:
        TreeEntry minimun();
        TreeEntry maximum();

        bool remove(TreeEntry x);
        bool search(TreeEntry x);
        void insert(TreeEntry x);

    private:

        TreeEntry rMinimun(TreePointer &t);
        TreeEntry rMaximus(TreePointer &t);

        bool rSearch(TreeEntry x, TreePointer &t);
    };


#endif
