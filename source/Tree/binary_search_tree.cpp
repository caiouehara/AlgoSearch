#include "./binary_search_tree.h"
#include <iostream>
using namespace std;

// max, min
TreeEntry BinarySearchTree::minimun()
{
    if (root == NULL)
    {
        cout << "Árvore Vazia" << endl;
        abort();
    }
    return rMinimun(root);
};

TreeEntry BinarySearchTree::maximum()
{
    if (root == NULL)
    {
        cout << "Árvore Vazia" << endl;
        abort();
    }
    return rMaximus(root);
};

// Remove, search, insert
bool BinarySearchTree::search(TreeEntry x)
{
    return rSearch(x, root);
};

void BinarySearchTree::insert(TreeEntry x)
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

void BinarySearchTree::insert(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        insert(array[i]);
    }
};

TreeEntry BinarySearchTree::rMinimun(TreePointer &t)
{
    if (t->leftNode == NULL)
        return t->entry;
    else
        rMinimun(t->leftNode);
};

TreeEntry BinarySearchTree::rMaximus(TreePointer &t)
{
    if (t->rightNode == NULL)
        return t->entry;
    else
        rMaximus(t->rightNode);
};

bool BinarySearchTree::rSearch(TreeEntry x, TreePointer &t)
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
        cout << "Found: " << t->entry << endl;
    return true;
};

void BinarySearchTree::searchInsert(TreeEntry x)
{
    rSearchInsert(x, root);
}
void BinarySearchTree::rSearchInsert(TreeEntry x, TreePointer &t)
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

bool BinarySearchTree::remove(TreeEntry x)
{
    return rRemove(x, root);
};

bool BinarySearchTree::rRemove(TreeEntry x, TreePointer &p)
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

void BinarySearchTree::removeMin(TreePointer &q, TreePointer &r)
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