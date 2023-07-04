#ifndef binary_search_tree
#define binary_search_tree
#include "./binary_tree.h"


#include <cstring>
#include <set>
#include <cmath>
#include <iostream>         // Biblioteca para entrada/saída padrão
#include <fstream>          // Biblioteca para leitura/escrita de arquivos
#include <sstream>          // Biblioteca para manipulação de fluxos de strings
#include <string>           // Biblioteca para manipulação de strings
#include <vector>           // Biblioteca para uso de vetores
#include <algorithm>        // Biblioteca para uso de algoritmos como sort
#include <unordered_map>    // Biblioteca para uso de mapas não ordenados

using namespace std;

template <class TreeEntry>
class BinarySearchTree : public BinaryTree<TreeEntry>
{
protected:
    using typename BinaryTree<TreeEntry>::TreeNode;
    using typename BinaryTree<TreeEntry>::TreePointer; 
    using BinaryTree<TreeEntry>::root; 

public:
    TreeEntry minimun();
    TreeEntry maximum();

    bool remove(TreeEntry x);
    void searchInsert(TreeEntry x);
    bool search(TreeEntry x);
    void insert(TreeEntry x);
    void insert(TreeEntryArray<TreeEntry> array, int size);
    // predecessor e sucessor

    int countDistinctWords();
    int alturaArvoreMinima();

    void showFrequency();

    vector<pair<string, int>> getTopFrequencies(int numWords);

private:
    unordered_map<string, TreePointer> wordMap; 

    TreeEntry rMinimun(TreePointer &t);
    TreeEntry rMaximus(TreePointer &t);

    void rSearchInsert(TreeEntry x, TreePointer &t);
    bool rSearch(TreeEntry x, TreePointer &t);

    bool rRemove(TreeEntry x, TreePointer &p);
    void removeMin(TreePointer &q, TreePointer &r);

    void rCountDistinctWords(TreePointer &t, set<TreeEntry> &distinctWords);
    int rAlturaArvoreMinima(TreePointer &t, int n);
    
    void rShowFrequency(TreePointer &t);
    

};

#endif