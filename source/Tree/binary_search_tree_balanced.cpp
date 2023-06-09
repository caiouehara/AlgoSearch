#include "./binary_search_tree_balanced.h"

#include <iostream>
#include <iostream>
#include <fstream>
#include <cstring>
#include <set>
#include <cmath>

using namespace std;

template <class TreeEntry>
BinaryAVLTree<TreeEntry>::BinaryAVLTree()
{
    root = NULL;
    comparisonCount = 0;
    rotationCount = 0;
    cout << "AVL created" << endl;
};


template <class TreeEntry>
void BinaryAVLTree<TreeEntry>::searchInsert(TreeEntry x)
{
    bool h = false;
    rSearchInsert(x, root, h);
}

template <class TreeEntry>
void BinaryAVLTree<TreeEntry>::searchInsert(TreeEntryArray<TreeEntry> x, int n)
{
    for (int i = 0; i < n; i++)
    {
        searchInsert(x[i]);
    }
}

template <class TreeEntry>
void BinaryAVLTree<TreeEntry>::rSearchInsert(TreeEntry x, TreePointer &pA, bool &h)
{

    TreePointer pB, pC;

    comparisonCount += 2;

    //Caso nulo
    if (pA == NULL)
    {
        pA = new TreeNode;
        h = true;
        pA->entry = x;
        pA->count = 1;
        pA->leftNode = pA->rightNode = NULL;
        pA->bal = 0;

        comparisonCount -= 2;
    }

    else if (x < pA->entry)
    {
        comparisonCount--;
        rSearchInsert(x, pA->leftNode, h);
        if (h) // subárvore esquerda cresceu
        {
            switch (pA->bal)
            {
            case -1:
                pA->bal = 0;
                h = false;
                break;
            case 0:
                pA->bal = +1;
                break;
            case +1:
                pB = pA->leftNode;
                if (pB->bal == +1) // rotação LL
                {
                    rotationCount++;
                    pA->leftNode = pB->rightNode;
                    pB->rightNode = pA;
                    pA->bal = 0;
                    pA = pB;
                }
                else // rotação LR
                {
                    rotationCount++;
                    pC = pB->rightNode;
                    pB->rightNode = pC->leftNode;
                    pC->leftNode = pB;
                    pA->leftNode = pC->rightNode;
                    pC->rightNode = pA;
                    if (pC->bal == +1)
                        pA->bal = -1;
                    else
                        pA->bal = 0;
                    if (pC->bal == -1)
                        pB->bal = +1;
                    else
                        pB->bal = 0;
                    pA = pC;
                }
                
                pA->bal = 0;
                h = false;
            } // switch
        }
    }

    else
    {
        if (x > pA->entry)
        {
            rSearchInsert(x, pA->rightNode, h);

            if (h) // subárvore direita cresceu
            {
                switch (pA->bal)
                {
                case +1:
                    pA->bal = 0;
                    h = false;
                    break;
                case 0:
                    pA->bal = -1;
                    break;
                case -1:
                    pB = pA->rightNode;
                    if (pB->bal == -1) // rotação RR
                    {
                        rotationCount++;
                        pA->rightNode = pB->leftNode;
                        pB->leftNode = pA;
                        pA->bal = 0;
                        pA = pB;
                    }
                    else // rotação RL
                    {
                        rotationCount++;
                        pC = pB->leftNode;
                        pB->leftNode = pC->rightNode;
                        pC->rightNode = pB;
                        pA->rightNode = pC->leftNode;
                        pC->leftNode = pA;
                        pC->bal == -1 ? pA->bal = +1 : pA->bal = 0;
                        pC->bal == +1 ? pB->bal = -1 : pB->bal = 0;
                        pA = pC;
                    }

                    pA->bal = 0;
                    h = false;
                }
            }
        }
    }
}

template class BinaryAVLTree<string>;