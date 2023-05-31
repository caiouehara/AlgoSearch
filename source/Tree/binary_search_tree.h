#ifndef binary_search_tree
#define binary_search_tree
    typedef int TreeEntry;

    class BinarySearchTree
    {
    public:
        BinarySearchTree();

        TreeEntry minimun();
        TreeEntry maximum();

        bool remove(TreeEntry x);
        bool search(TreeEntry x);
        void insert(TreeEntry x);

    private:
        struct TreeNode;
        typedef TreeNode *TreePointer;

        struct TreeNode
        {
            TreeEntry entry;
            int count;
            TreePointer leftNode, rightNode;
        };

        TreeEntry rMinimun(TreePointer &t);
        TreeEntry rMaximus(TreePointer &t);

        bool rSearch(TreeEntry x, TreePointer &t);

        TreePointer root;
    };


#endif
