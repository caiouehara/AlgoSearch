#include "./binary_search_tree.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <set>
#include <cmath>
#include <vector>        // Biblioteca para uso de vetores
#include <algorithm>     // Biblioteca para uso de algoritmos como sort
#include <unordered_map> // Biblioteca para uso de mapas não ordenados
#include <typeinfo>

using namespace std;

template <class TreeEntry>
BinarySearchTree<TreeEntry>::BinarySearchTree()
{
    root = NULL;
    comparisonCount = 0;
    cout << "ABB created" << endl;
};

// max, min
template <class TreeEntry>
TreeEntry BinarySearchTree<TreeEntry>::minimun()
{
    if (root == NULL)
    {
        cout << "Árvore Vazia" << endl;
        abort();
    }
    return rMinimun(root);
};

template <class TreeEntry>
TreeEntry BinarySearchTree<TreeEntry>::maximum()
{
    if (root == NULL)
    {
        cout << "Árvore Vazia" << endl;
        abort();
    }
    return rMaximus(root);
};

// Remove, search, insert
template <class TreeEntry>
bool BinarySearchTree<TreeEntry>::search(TreeEntry x)
{
    return rSearch(x, root);
};

template <class TreeEntry>
void BinarySearchTree<TreeEntry>::insert(TreeEntry x)
{
    TreePointer p = NULL, q = root, r;

    // descendo o nível da árvore
    while (q != NULL)
    {
        p = q;
        if (x < q->entry)
            q = q->leftNode;
        else
            q = q->rightNode;
    }

    // declarando a nova inserção
    r = new TreeNode;
    if (r == NULL)
    {
        cout << "Sem memoria" << endl;
        abort();
    }
    r->entry = x;
    r->leftNode = NULL;
    r->rightNode = NULL;

    // inserindo novo nó
    // caso base
    if (p == NULL)
        root = r;
    // caso recursivo
    else if (x < p->entry)
        p->leftNode = r;
    else
        p->rightNode = r;
};

template <class TreeEntry>
void BinarySearchTree<TreeEntry>::insert(TreeEntryArray<TreeEntry> array, int size)
{
    for (int i = 0; i < size; i++)
    {
        insert(array[i]);
    }
};

template <class TreeEntry>
TreeEntry BinarySearchTree<TreeEntry>::rMinimun(TreePointer &t)
{
    if (t->leftNode == NULL)
        return t->entry;
    else
        rMinimun(t->leftNode);
};

template <class TreeEntry>
TreeEntry BinarySearchTree<TreeEntry>::rMaximus(TreePointer &t)
{
    if (t->rightNode == NULL)
        return t->entry;
    else
        rMaximus(t->rightNode);
};

template <class TreeEntry>
bool BinarySearchTree<TreeEntry>::rSearch(TreeEntry x, TreePointer &t)
{
    
    if (t == NULL)
    {          
        cout << "Arvore Vazia" << endl;
        return false;
    }

    if (x < t->entry)
        return rSearch(x, t->leftNode);
    else if (x > t->entry)
        return rSearch(x, t->rightNode);
    else
        return true;
};

template <class TreeEntry>
void BinarySearchTree<TreeEntry>::searchInsert(TreeEntry x)
{
    rSearchInsert(x, root);
}

template <class TreeEntry>
void BinarySearchTree<TreeEntry>::rSearchInsert(TreeEntry x, TreePointer &t)
{
    comparisonCount += 2;
    if (t == NULL) // x não encontrado; inserir
    {
        t = new TreeNode;
        t->entry = x;
        t->count = 1; // primeira ocorrência de x
        t->leftNode = t->rightNode = NULL;
        comparisonCount -= 2;
    }
    else if (x < t->entry) { // procurar x na subárvore esquerda
        comparisonCount--;
        rSearchInsert(x, t->leftNode);
    }
    else if (x > t->entry) { // procurar x na subárvore direita
        rSearchInsert(x, t->rightNode);
    }
    else // x encontrado, atualizar contador
        t->count++;
}

template <class TreeEntry>
bool BinarySearchTree<TreeEntry>::remove(TreeEntry x)
{
    return rRemove(x, root);
};

template <class TreeEntry>
bool BinarySearchTree<TreeEntry>::rRemove(TreeEntry x, TreePointer &p)
// entendi mais ou menos
{
    // search
    if (p == NULL)
        return false; // elemento inexistente
    if (x < p->entry)
        return rRemove(x, p->leftNode);
    else if (x > p->entry)
        return rRemove(x, p->rightNode);
    else
    // remover p->
    {
        TreePointer q;
        q = p;

        if (q->leftNode == NULL)
            p = q->rightNode; // caso A
        else if (q->rightNode == NULL)
            p = q->leftNode; // caso B
        else                 // caso C.1
            removeMin(q, q->rightNode);
        delete q;
        return true; // elemento removido
    }
}

template <class TreeEntry>
void BinarySearchTree<TreeEntry>::removeMin(TreePointer &q, TreePointer &r)
{
    if (r->leftNode != NULL)
        removeMin(q, r->leftNode);
    else
    {
        q->entry = r->entry;
        q->count = r->count; // somente necessário se busca com inserção
        q = r;
        r = r->rightNode;
    }
}

template <class TreeEntry>
int BinarySearchTree<TreeEntry>::countDistinctWords()
{
    set<TreeEntry> distinctWords;             // Conjunto para armazenar palavras distintas
    rCountDistinctWords(root, distinctWords); // Chama a função recursiva para preencher o conjunto
    return distinctWords.size();              // Retorna o tamanho do conjunto de palavras distintas
}

// Função recursiva para contar palavras distintas
template <class TreeEntry>
void BinarySearchTree<TreeEntry>::rCountDistinctWords(TreePointer &t, set<TreeEntry> &distinctWords)
{
    if (t == NULL)
    { // Se o nó for nulo, retorna
        return;
    }

    distinctWords.insert(t->entry); // Insere a palavra no conjunto de palavras distintas

    rCountDistinctWords(t->leftNode, distinctWords);  // Recursivamente processa a subárvore esquerda
    rCountDistinctWords(t->rightNode, distinctWords); // Recursivamente processa a subárvore direita
}

template <class TreeEntry>
int BinarySearchTree<TreeEntry>::alturaArvoreMinima()
{                                        // Retorna a altura mínima da árvore
    int n = countDistinctWords();        // Número de palavras distintas na árvore
    return rAlturaArvoreMinima(root, n); // Chama a função recursiva a partir da raiz da árvore com o número de palavras distintas
}

// Função recursiva para calcular a altura mínima da árvore
template <class TreeEntry>
int BinarySearchTree<TreeEntry>::rAlturaArvoreMinima(TreePointer &t, int n)
{
    int height = static_cast<int>(log2(n + 1)) - 1; // Conforme dado em aula de arvore binaria, pela fórmula log2(n+1) - 1 se calcula a altura mínima
    return height;                                  // Retorna a altura mínima da árvore
}

template <class TreeEntry>
void BinarySearchTree<TreeEntry>::showFrequency()
{
    rShowFrequency(root);
};

template <class TreeEntry>
void BinarySearchTree<TreeEntry>::rShowFrequency(TreePointer &t)
{
    if (t != NULL)
    {
        rShowFrequency(t->leftNode);
        wordMap[t->entry] = t;
        rShowFrequency(t->rightNode);
    }
};

template <class TreeEntry>
vector<pair<string, int>> BinarySearchTree<TreeEntry>::getTopFrequencies(int numWords) 
{                                          // Obtém as n palavras mais frequentes
    vector<pair<string, int>> frequencies; // Vetor para armazenar as frequências
    for (const auto &pair : wordMap)
    {                                                                     // Percorre o mapa de palavras
        frequencies.push_back(make_pair(pair.first, pair.second->count)); // Adiciona a palavra e a contagem ao vetor
    }

    // Ordena o vetor com base na contagem em ordem decrescente
    sort(frequencies.begin(), frequencies.end(), [](const pair<string, int> &a, const pair<string, int> &b)
         {
            if (a.second != b.second) {
                return a.second > b.second;
            }
            return a.first < b.first; });
    if (frequencies.size() > numWords)
    { // Reduz o tamanho do vetor para n elementos
        frequencies.resize(numWords);
    }
    return frequencies; // Retorna as palavras mais frequentes
}

template class BinarySearchTree<string>;