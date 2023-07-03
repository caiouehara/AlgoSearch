#include <iostream>
#include "./Tree/binary_search_tree_balanced.h"

using namespace std;

int main()
{
    AVLTree<int> Tree;
    TreeEntryArray<int> a = {60,4,5,10,123,6,124,12,31,13, 15, 230};
    Tree.insert(a, 12);
    Tree.print();

}
