#include "./binary_tree.h"
#include <iostream> 
#include <iomanip>
#include <fstream>
#include <cstring>
#include <set>
#include <cmath>

using namespace std;

template <class TreeEntry>
BinaryTree<TreeEntry>::BinaryTree()
{
    root = NULL;
    cout << "Tree created" << endl;
};

template <class TreeEntry>
bool BinaryTree<TreeEntry>::empty()
{
    return (root == NULL);
}

template <class TreeEntry>
bool BinaryTree<TreeEntry>::full()
{
    // caso haja limite, deverá ser adicionado aqui
    return false;
}

template <class TreeEntry>
int BinaryTree<TreeEntry>::nodes()
{
    return rNodes(root);
}

template <class TreeEntry>
int BinaryTree<TreeEntry>::rNodes(TreePointer &t)
{
    if (t == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + rNodes(t->leftNode) + rNodes(t->rightNode);
    }
}

template <class TreeEntry>
int BinaryTree<TreeEntry>::leaves()
{
    return rLeaves(root);
    ;
}

template <class TreeEntry>
int BinaryTree<TreeEntry>::rLeaves(TreePointer &t)
{
    if (t == NULL)
        return 0;
    else if (t->leftNode == NULL && t->rightNode == NULL)
        return 1;
    else
        return rLeaves(t->leftNode) + rLeaves(t->rightNode);
}

template <class TreeEntry>
void BinaryTree<TreeEntry>::clear()
{
    rClear(root);
    root = NULL;
    cout << "Tree deleted" << endl;
};

template <class TreeEntry>
void BinaryTree<TreeEntry>::rClear(TreePointer &t)
{
    if (t != NULL)
    {
        rClear(t->leftNode);
        rClear(t->rightNode);
        delete t;
    }
};

template <class TreeEntry>
void BinaryTree<TreeEntry>::preOrder(callback<TreeEntry> cb)
{
    rPreOrder(root, cb);
};

template <class TreeEntry>
void BinaryTree<TreeEntry>::rPreOrder(TreePointer &t, callback<TreeEntry> cb)
{
    if (t != NULL)
    {
        cb(t->entry);
        rPreOrder(t->leftNode, cb);
        rPreOrder(t->rightNode, cb);
    }
};

template <class TreeEntry>
void BinaryTree<TreeEntry>::inOrder(callback<TreeEntry> cb)
{
    rInOrder(root, cb);
};

template <class TreeEntry>
void BinaryTree<TreeEntry>::rInOrder(TreePointer &t, callback<TreeEntry> cb)
{
    if (t != NULL)
    {
        rInOrder(t->leftNode, cb);
        cb(t->entry);
        rInOrder(t->rightNode, cb);
    }
};

template <class TreeEntry>
void BinaryTree<TreeEntry>::postOrder(callback<TreeEntry> cb)
{
    rPostOrder(root, cb);
};

template <class TreeEntry>
void BinaryTree<TreeEntry>::rPostOrder(TreePointer &t, callback<TreeEntry> cb)
{
    if (t != NULL)
    {
        rPostOrder(t->leftNode, cb);
        rPostOrder(t->rightNode, cb);
        cb(t->entry);
    }
};

template <class TreeEntry>
int BinaryTree<TreeEntry>::height()
{
    return rHeight(root);
};

template <class TreeEntry>
int BinaryTree<TreeEntry>::rHeight(TreePointer &t)
{
    // não entendi
    if (t == NULL)
        return -1;
    else
    {
        int L, R;
        L = rHeight(t->leftNode);
        R = rHeight(t->rightNode);
        if (L > R)
            return L + 1;
        else
            return R + 1;
    }
};

template <class TreeEntry>
void BinaryTree<TreeEntry>::print()
{
    rPrint(root, 0);
}

template <class TreeEntry>
void BinaryTree<TreeEntry>::rPrint(TreePointer &t, int s)
{
    //não entendi
    int i;
    if (t != NULL)
    {
        rPrint(t->rightNode, s + 3); // escreve subárvore direita
        for (i = 1; i <= s; i++)
            cout << " ";                     // espaços
        cout << setw(6) << t-> entry << endl; // escreve a raiz
        rPrint(t->leftNode, s + 3);           // escreve subárvore esquerda
    }
}


template class BinaryTree<int>;
template class BinaryTree<string>;