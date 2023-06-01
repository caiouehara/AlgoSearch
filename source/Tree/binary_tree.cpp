#include "./binary_tree.h"
#include <iostream>
using namespace std;

BinaryTree::BinaryTree()
{
    root = NULL;
    cout << "Tree created" << endl;
};

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

void BinaryTree::preOrder()
{
    rPreOrder(root);
};

void BinaryTree::rPreOrder(TreePointer &t)
{
    cout << t -> entry << ", ";
    rPreOrder(t -> leftNode);
    rPreOrder(t -> rightNode);
};

void BinaryTree::inOrder()
{
    rInOrder(root);
};

void BinaryTree::rInOrder(TreePointer &t)
{
    rInOrder(t -> leftNode);
    cout << t -> entry << ", ";
    rInOrder(t -> rightNode);
};

void BinaryTree::postOrder()
{
    rPostOrder(root);
};

void BinaryTree::rPostOrder(TreePointer &t)
{
    if(t != NULL)
    {
        rPostOrder(t -> leftNode);
        rPostOrder(t -> rightNode);
        cout << t -> entry << endl;
    }
};