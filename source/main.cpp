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
    TreeEntryArray a = {60,4,5,10,123,6,124,12,31,13, 15, 230};
    Tree.insert(a, 12);
    Tree.print();
    Tree.remove(12);
    Tree.print();
}
