#ifndef binary_tree
#define binary_tree

typedef int TreeEntry;  // tipo de dado colocado na árvore
typedef void (*callback) (TreeEntry); 
class BinaryTree
{
public:
    BinaryTree();

    void clear();
    bool empty();
    bool full();
    int nodes();
    int leaves();

    void preOrder(callback cb);
    void inOrder(callback cb);
    void postOrder(callback cb);

protected:
    // declaração de tipos
    struct TreeNode;               
    typedef TreeNode *TreePointer; // TreePointer é um ponteiro para estrutura TreeNode

    struct TreeNode
    {
        TreeEntry entry;                      
        TreePointer leftNode, rightNode; // subárvores
        int count;
    };

    void rClear(TreePointer &t);
    int rNodes(TreePointer &t);
    int rLeaves(TreePointer &t);

    void rPreOrder(TreePointer &t, callback cb);
    void rInOrder(TreePointer &t, callback cb);
    void rPostOrder(TreePointer &t, callback cb);

    // declaração de campos
    TreePointer root;
};

#endif