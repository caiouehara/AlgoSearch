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

// float count_F = 0; // Resultado item F - número de comparações de palavras na busca com inserção ABB - tipo float para gerar "media1" com  casas decimais (casting)
template <class TreeEntry>
bool BinarySearchTree<TreeEntry>::rSearch(TreeEntry x, TreePointer &t)
{
    // count_F += 2; // Artificio para contagem de comparações***
    if (t == NULL)
    {
        // count_F-=2;                      // Não realiza nenhuma comparação (Saldo vide **
        cout << "Arvore Vazia" << endl;
        return false;
    }

    if (x < t->entry)
        // count_F--;
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
    if (t == NULL) // x não encontrado; inserir
    {
        t = new TreeNode;
        t->entry = x;
        t->count = 1; // primeira ocorrência de x
        t->leftNode = t->rightNode = NULL;
    }
    else if (x < t->entry) // procurar x na subárvore esquerda
        rSearchInsert(x, t->leftNode);
    else if (x > t->entry) // procurar x na subárvore direita
        rSearchInsert(x, t->rightNode);
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

template class BinarySearchTree<string>;