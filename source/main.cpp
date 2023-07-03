#include <iostream>
#include "./Tree/Tree.h"

using namespace std;

int main()
{
    BinaryAVLTree<string> avl;
    TreeEntryArray<string> a = {"a", "b"};
    avl.insert(a, 2);
    avl.print();

}
