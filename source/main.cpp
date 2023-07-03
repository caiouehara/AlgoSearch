#include <iostream>
#include "./Tree/Tree.h"

using namespace std;

int main()
{
    BinaryAVLTree<int> avl;
    TreeEntryArray<int> a = {60,4,5,10,123,6,124,12,31,13, 15, 230};
    avl.insert(a, 12);
    avl.print();

}
