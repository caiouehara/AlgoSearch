#ifndef binary_tree
#define binary_tree

template <class TreeEntry> using callback = void (*) (TreeEntry); 
template <class TreeEntry> using TreeEntryArray = TreeEntry[]; 

template <class TreeEntry> class BinaryTree
{
public:
    BinaryTree();

    void clear();
    bool empty();
    bool full();
    int nodes();
    int leaves();
    int height();

    void preOrder(callback<TreeEntry> cb);
    void inOrder(callback<TreeEntry> cb);
    void postOrder(callback<TreeEntry> cb);

    
    void print();

protected:
    // declaração de tipos
    struct TreeNode;               
    typedef TreeNode* TreePointer; // TreePointer é um ponteiro para estrutura TreeNode

    struct TreeNode
    {
        TreeEntry entry;  //chave
        TreePointer leftNode, rightNode; // subárvores
        int count; //frequência
        int bal; //fator de balanceamento (-1,0,1)
    };
    
    // declaração de campos
    TreePointer root;

private:
    void rClear(TreePointer &t);
    int rNodes(TreePointer &t);
    int rLeaves(TreePointer &t);
    int rHeight(TreePointer &t);
    void rPrint(TreePointer &t, int s);

    void rPreOrder(TreePointer &t, callback<TreeEntry> cb);
    void rInOrder(TreePointer &t, callback<TreeEntry> cb);
    void rPostOrder(TreePointer &t, callback<TreeEntry> cb);

};

#endif