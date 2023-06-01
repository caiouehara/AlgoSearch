#include <iostream>
#include "./Tree/binary_search_tree.h"

using namespace std;


int main(){
    BinarySearchTree Tree;

    Tree.insert(5);
    for(int i=1; i <= 10; i++){
        if(i == 5) continue;
        Tree.insert(i);
    }

    Tree.search(7);

    Tree.preOrder();
    return 0;
}
