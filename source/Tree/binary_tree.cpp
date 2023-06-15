#include "./binary_tree.h"
#include <iostream>
using namespace std;

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
    //caso haja limite, deverá ser adicionado aqui
    return false;
}

int BinaryTree::nodes()
{
    return rNodes(root);
}

int BinaryTree::rNodes(TreePointer &t)
{
    if(t == NULL){ 
        return 0;
    }
    else {
        return 1 + rNodes(t -> leftNode) + rNodes(t -> rightNode);
    }
}

int BinaryTree::leaves()
{   
    return rLeaves(root);;
}

int BinaryTree::rLeaves(TreePointer &t)
{
    if(t == NULL)
        return 0;
    else
        if(t -> leftNode == NULL && t -> rightNode == NULL)
            return 1;
        else
            return rLeaves(t -> leftNode) + rLeaves(t -> rightNode);
}

void BinaryTree::clear()
{
    rClear(root);
    root = NULL;
    cout << "Tree deleted" << endl;
};

void BinaryTree::rClear(TreePointer &t)
{
    if( t != NULL){
        rClear(t -> leftNode);
        rClear(t -> rightNode);
        delete t;
    }

};

void BinaryTree::preOrder(callback cb)
{
    rPreOrder(root, cb);
};

void BinaryTree::rPreOrder(TreePointer &t, callback cb)
{
    if(t != NULL){
        cb(t -> entry);
        rPreOrder(t -> leftNode, cb);
        rPreOrder(t -> rightNode, cb);
    }
};

void BinaryTree::inOrder(callback cb)
{
    rInOrder(root, cb);
};

void BinaryTree::rInOrder(TreePointer &t, callback cb)
{
    if(t != NULL){
        rInOrder(t -> leftNode, cb);
        cb(t -> entry);
        rInOrder(t -> rightNode, cb);
    }
};

void BinaryTree::postOrder(callback cb)
{
    rPostOrder(root, cb);
};

void BinaryTree::rPostOrder(TreePointer &t, callback cb)
{
    if(t != NULL)
    {
        rPostOrder(t -> leftNode, cb);
        rPostOrder(t -> rightNode, cb);
        cb(t -> entry);
    }
};