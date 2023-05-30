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

    //max, min
    TreeEntry minimun(){
        if(root == NULL){
            cout << "Árvore Vazia" << endl;
            abort();
        }
        return rMinimun(root);
    }   

    TreeEntry maximum(){
        if(root == NULL){
            cout << "Árvore Vazia" << endl;
            abort();
        }
        return rMaximus(root);
    }   

    //Remove, search, insert
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

        cout << "Inserted: " << r -> entry << endl;
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

    TreeEntry rMinimun(TreePointer &t){
        if(t -> leftNode == NULL)
            return t -> entry;
        else
            rMinimun(t -> leftNode);
    }

    TreeEntry rMaximus(TreePointer &t){
        if(t -> rightNode == NULL)
            return t -> entry;
        else
            rMaximus(t -> rightNode);
    }

    bool rSearch(TreeEntry x, TreePointer &t){
        if(t == NULL)
            return false;

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
    tree1.insert(5);
    tree1.insert(1);


    if(tree1.maximum() == 5)
        std::cout << "Number founded\n";
    if(tree1.minimun() == 1)
        std::cout << "Number founded\n";

    return 0;
}