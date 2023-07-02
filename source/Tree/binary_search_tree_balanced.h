#ifndef avltree
#define avltree
#include "./binary_search_tree.h"

class AVLTree: public BinarySearchTree
{

    public:
        void searchInsert(TreeEntry x);
        void searchInsert(TreeEntryArray x, int n);


    private:
        void rSearchInsert(TreeEntry x, TreePointer &pA, bool &h);





};



#endif