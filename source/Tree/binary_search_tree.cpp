#include "./binary_search_tree.h"
#include <iostream>
using namespace std;

// max, min
TreeEntry BinarySearchTree::minimun()
{
    if (root == NULL)
    {
        cout << "Árvore Vazia" << endl;
        abort();
    }
    return rMinimun(root);
};

TreeEntry BinarySearchTree::maximum()
{
    if (root == NULL)
    {
        cout << "Árvore Vazia" << endl;
        abort();
    }
    return rMaximus(root);
};

// Remove, search, insert
bool BinarySearchTree::search(TreeEntry x)
{
    return rSearch(x, root);
};

void BinarySearchTree::insert(TreeEntry x)
{
    TreePointer p = NULL, q = root, r;

    // descendo o nível da árvore
    while (q != NULL)
    {
        p = q;
        if (x < q->entry)
            q = q->leftNode;
        else
            q = q->rightNode;
    }

    // declarando a nova inserção
    r = new TreeNode;
    if (r == NULL)
    {
        cout << "Sem memoria" << endl;
        abort();
    }
    r->entry = x;
    r->leftNode = NULL;
    r->rightNode = NULL;

    // inserindo novo nó
    // caso base
    if (p == NULL)
        root = r;
    // caso recursivo
    else if (x < p->entry)
        p->leftNode = r;
    else
        p->rightNode = r;

    cout << "Inserted: " << r-> entry << endl;
};

TreeEntry BinarySearchTree::rMinimun(TreePointer &t)
{
    if (t->leftNode == NULL)
        return t->entry;
    else
        rMinimun(t->leftNode);
};

TreeEntry BinarySearchTree::rMaximus(TreePointer &t)
{
    if (t->rightNode == NULL)
        return t->entry;
    else
        rMaximus(t->rightNode);
};

bool BinarySearchTree::rSearch(TreeEntry x, TreePointer &t)
{
    if (t == NULL){
        cout << "Arvore Vazia" << endl;
        return false;
    }
        
    if (x < t->entry)
        return rSearch(x, t->leftNode);
    else if (x > t->entry)
        return rSearch(x, t->rightNode);
    else
        return true;
};
