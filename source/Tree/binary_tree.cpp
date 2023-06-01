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