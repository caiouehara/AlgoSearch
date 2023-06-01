#ifndef binary_tree
#define binary_tree

typedef int TreeEntry;  // tipo de dado colocado na árvore
class BinaryTree
{
public:
    BinaryTree();

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

    // declaração de campos
    TreePointer root;
};

#endif