#include <iostream>
#include "./Tree/binary_search_tree_balanced.h"

using namespace std;

int main()
{
    AVLTree Tree;
    TreeEntryArray a = {60,4,5,10,123,6,124,12,31,13, 15, 230};
    Tree.searchInsert(a, 12);
    Tree.print();

}
