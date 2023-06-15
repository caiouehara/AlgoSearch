#include <iostream>
#include "./Tree/binary_search_tree.h"

using namespace std;

void cb(TreeEntry x)
{
    cout << x << ", ";
};

int main()
{
    BinarySearchTree Tree;

    Tree.insert(2);
    Tree.insert(3);
    Tree.insert(4);
    Tree.insert(5);
    Tree.insert(1);

    Tree.postOrder(cb);
}
