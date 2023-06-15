#include "./binary_tree.h"
#include <iostream> 
using namespace std;
#include <iomanip>

BinaryTree::BinaryTree()
{
    root = NULL;
    cout << "Tree created" << endl;
};

bool BinaryTree::empty()
{
    return (root == NULL);
}

bool BinaryTree::full()
{
    // caso haja limite, deverá ser adicionado aqui
    return false;
}

int BinaryTree::nodes()
{
    return rNodes(root);
}

int BinaryTree::rNodes(TreePointer &t)
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

int BinaryTree::leaves()
{
    return rLeaves(root);
    ;
}

int BinaryTree::rLeaves(TreePointer &t)
{
    if (t == NULL)
        return 0;
    else if (t->leftNode == NULL && t->rightNode == NULL)
        return 1;
    else
        return rLeaves(t->leftNode) + rLeaves(t->rightNode);
}

void BinaryTree::clear()
{
    rClear(root);
    root = NULL;
    cout << "Tree deleted" << endl;
};

void BinaryTree::rClear(TreePointer &t)
{
    if (t != NULL)
    {
        rClear(t->leftNode);
        rClear(t->rightNode);
        delete t;
    }
};

void BinaryTree::preOrder(callback cb)
{
    rPreOrder(root, cb);
};

void BinaryTree::rPreOrder(TreePointer &t, callback cb)
{
    if (t != NULL)
    {
        cb(t->entry);
        rPreOrder(t->leftNode, cb);
        rPreOrder(t->rightNode, cb);
    }
};

void BinaryTree::inOrder(callback cb)
{
    rInOrder(root, cb);
};

void BinaryTree::rInOrder(TreePointer &t, callback cb)
{
    if (t != NULL)
    {
        rInOrder(t->leftNode, cb);
        cb(t->entry);
        rInOrder(t->rightNode, cb);
    }
};

void BinaryTree::postOrder(callback cb)
{
    rPostOrder(root, cb);
};

void BinaryTree::rPostOrder(TreePointer &t, callback cb)
{
    if (t != NULL)
    {
        rPostOrder(t->leftNode, cb);
        rPostOrder(t->rightNode, cb);
        cb(t->entry);
    }
};

int BinaryTree::height()
{
    return rHeight(root);
};

int BinaryTree::rHeight(TreePointer &t)
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

void BinaryTree::print()
{
    rPrint(root, 0);
}

void BinaryTree::rPrint(TreePointer &t, int s)
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