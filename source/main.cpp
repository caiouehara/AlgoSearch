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
    TreeEntryArray a = {2,4,5,6,10,123,124,12,31,13, 15, 230};
    Tree.insert(a, 12);
    Tree.print();
}
