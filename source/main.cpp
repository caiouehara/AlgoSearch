#include "./Tree/Tree.h"


#include <iostream>
#include <fstream>
#include <cstring>
#include <set>
#include <cmath>

using namespace std;

int main()
{
    BinarySearchTree<string> bst;

    string word;
    ifstream theInput("./data/mam-na-np-lo.txt");  // Abre o arquivo para leitura "mam-na-np-lo.txt"/ "exame_10000-na-np-lo.txt" / "biblia-na-np-lo.txt"

    

    while (theInput >> word) {
        bst.insert(word);
        
        bst.search(word) ? 1 : 0;  // contador de comparações de palavras na busca com inserção ABB
    }

    theInput.close();
}
