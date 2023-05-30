#include <iostream>
using namespace std;

typedef int TreeEntry;

class BinarySearchTree
{
public:
    BinarySearchTree(){
        root = NULL;

        cout << "Tree Created" << endl;        
    }

    bool remove(TreeEntry x);

    bool search(TreeEntry x){
        return rSearch(x, root);
    }

    void insert(TreeEntry x){
        TreePointer p = NULL, q = root, r;

        //descendo o nível da árvore
        while(q != NULL){
            p=q;
            if( x < q -> entry)
                q = q -> leftNode;
            else
                q = q -> rightNode;
        }

        //declarando a nova inserção
        r = new TreeNode;
        if(r == NULL){
            std::cout << "Sem memoria" << endl;
            abort();
        }
        r -> entry = x;
        r -> leftNode = NULL;
        r -> rightNode = NULL;

        // inserindo novo nó
        //caso base 
        if( p == NULL)
            root = r;
        //caso recursivo
        else
            if(x < p -> entry)
                p -> leftNode = r;
            else
                p -> rightNode = r;

    }

private:
    struct TreeNode;
    typedef TreeNode *TreePointer;

    struct TreeNode
    {
        TreeEntry entry;
        int count;
        TreePointer leftNode, rightNode;
    };

    bool rSearch(TreeEntry x, TreePointer &t){
        if(t == NULL){
            return false;
        }

        if(x < t -> entry)
            return rSearch(x, t -> leftNode);
        else
            if( x > t -> entry)
                return rSearch(x, t -> rightNode);
            else
                return true;
    };

    TreePointer root;
};

int main(int argc, const char * args[])
{
    BinarySearchTree tree1;
    tree1.insert(3);

    if(tree1.search(3) == true)
        std::cout << "Number founded\n";

    return 0;
}