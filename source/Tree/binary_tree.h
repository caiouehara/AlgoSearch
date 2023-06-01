#ifndef binary_tree
#define binary_tree

typedef int TreeEntry;  // tipo de dado colocado na árvore
class BinaryTree
{
public:
    BinaryTree();

    void clear();

    void preOrder();
    void inOrder();
    void postOrder();

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

    void rPreOrder(TreePointer &t);
    void rInOrder(TreePointer &t);
    void rPostOrder(TreePointer &t);

    // declaração de campos
    TreePointer root;
};

#endif