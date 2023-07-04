#include "./Tree/Tree.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <set>
#include <cmath>

using namespace std;

int main()
{
    //Apresentação do trabalho
    cout << endl
         << "------------------------------------------------" << endl
         << "TRABALHO 4 - ALGORITMO E ESTRUTURA DE DADOS" << endl
         << "--- CONSTRUCAO DE ABB A PARTIR DE TEXTOS ---" << endl
         << endl
         << "ALUNOS: ANDRE LUIZ DE SOUZA MURAKAMI N USP 5631500" << endl
         << "        CAIO UEHARA MARTINS N USP 1367202" << endl;
    cout << endl;




    cout << "################### mam-na-np-lo.txt ###############################" << endl;

    //arquivo: mam-na-np-lo.txt
    //Declaração da estrutura
    BinarySearchTree<string> bst1;
    BinaryAVLTree<string> avl1;
    cout << endl;

    //Leitura do arquivo
    string word1;
    ifstream theInput1("./data/mam-na-np-lo.txt"); // Abre o arquivo para leitura "mam-na-np-lo.txt"/ "exame_10000-na-np-lo.txt" / "biblia-na-np-lo.txt"

    float nPalavras = 0; // Resultado item B - número de palavras
    while (theInput1 >> word1)
    {
        bst1.searchInsert(word1);
        avl1.searchInsert(word1);

        nPalavras++;
    }
    theInput1.close();

    //Impressão dos dados
    cout << "-------- TABELA COM OS RESULTADOS OBTIDOS ---------" << endl;

    cout << "A) PALAVRAS DISTINTAS: " << bst1.countDistinctWords() << endl;
    cout << "B) PALAVRAS: " << nPalavras << endl;
    cout << "C) ALTURA DA ARVORE MINIMA: " << bst1.alturaArvoreMinima() << endl;
    cout << "D) ALTURA ABB: " << bst1.height() << endl;
    cout << "E) FOLHAS ABB: " << bst1.leaves() << endl;
    cout << "F) COMPARACOES DE PALAVRAS NA BUSCA COM INSERCAO ABB: " << bst1.comparisonCount << endl;
    cout << "G) ALTURA AVL: " << avl1.height() << endl;
    cout << "H) FOLHAS AVL: " << avl1.leaves() << endl;
    cout << "I) COMPARACOES DE PALAVRAS NA BUSCA COM INSERCAO AVL: " << avl1.comparisonCount << endl;
    cout << "J) ROTACOES NA BUSCA COM INSERCAO AVL: " << avl1.rotationCount << endl;

    cout << "----------- ESTATISTICAS ---------- " << endl;

    float media1 = round( float(bst1.comparisonCount) / float(nPalavras) * 100) / 100;
    float media2 = round( float(avl1.rotationCount) / float(nPalavras) * 100) / 100; 
    float media3 = round( float(avl1.rotationCount) / float(bst1.countDistinctWords()) * 100) / 100;   

    cout << "1) Media de comparacoes por palavra ABB = " << media1 << endl;
    cout << "2) Media de comparacoes por palavra AVL = " << media2 << endl; //tem que ser float com 2 casas
    cout << "3) Media de rotacoes por palavra distinta AVL = " << media3 << endl << endl; //tem que ser float com 2 casas

    cout << "----------- Palavras mais frequentes ---------- " << endl;
    
    bst1.showFrequency();
    vector<pair<string, int>> topFrequencies = bst1.getTopFrequencies(10);
    int i = 0;
    for (const auto& pair : topFrequencies) {
        i++;
        cout << i <<") " <<  pair.first << ": " << pair.second << " ocorrencias" << endl;
    }
    cout << endl;





    
    cout << "################### exame_10000-na-np-lo.txt ###############################" << endl;

    //arquivo: exame_10000-na-np-lo.txt
    //Declaração da estrutura
    BinarySearchTree<string> bst2;
    BinaryAVLTree<string> avl2;
    cout << endl;

    //Leitura do arquivo
    string word2;
    ifstream theInput2("./data/exame_10000-na-np-lo.txt"); // Abre o arquivo para leitura "mam-na-np-lo.txt"/ "exame_10000-na-np-lo.txt" / "biblia-na-np-lo.txt"

    nPalavras = 0; // Resultado item B - número de palavras
    while (theInput2 >> word2)
    {
        bst2.searchInsert(word2);
        avl2.searchInsert(word2);

        nPalavras++;
    }
    theInput2.close();

    //Impressão dos dados
    cout << "-------- TABELA COM OS RESULTADOS OBTIDOS ---------" << endl;

    cout << "A) PALAVRAS DISTINTAS: " << bst2.countDistinctWords() << endl;
    cout << "B) PALAVRAS: " << nPalavras << endl;
    cout << "C) ALTURA DA ARVORE MINIMA: " << bst2.alturaArvoreMinima() << endl;
    cout << "D) ALTURA ABB: " << bst2.height() << endl;
    cout << "E) FOLHAS ABB: " << bst2.leaves() << endl;
    cout << "F) COMPARACOES DE PALAVRAS NA BUSCA COM INSERCAO ABB: " << bst2.comparisonCount << endl;
    cout << "G) ALTURA AVL: " << avl2.height() << endl;
    cout << "H) FOLHAS AVL: " << avl2.leaves() << endl;
    cout << "I) COMPARACOES DE PALAVRAS NA BUSCA COM INSERCAO AVL: " << avl2.comparisonCount << endl;
    cout << "J) ROTACOES NA BUSCA COM INSERCAO AVL: " << avl2.rotationCount << endl;

    cout << "----------- ESTATISTICAS ---------- " << endl;

    media1 = round( float(bst2.comparisonCount) / float(nPalavras) * 100) / 100;
    media2 = round( float(avl2.rotationCount) / float(nPalavras) * 100) / 100; 
    media3 = round( float(avl2.rotationCount) / float(bst2.countDistinctWords()) * 100) / 100;   

    cout << "1) Media de comparacoes por palavra ABB = " << media1 << endl;
    cout << "2) Media de comparacoes por palavra AVL = " << media2 << endl; //tem que ser float com 2 casas
    cout << "3) Media de rotacoes por palavra distinta AVL = " << media3 << endl << endl; //tem que ser float com 2 casas

    cout << "----------- Palavras mais frequentes ---------- " << endl;
    
    bst2.showFrequency();
    topFrequencies = bst2.getTopFrequencies(10);
    i = 0;
    for (const auto& pair : topFrequencies) {
        i++;
        cout << i <<") " <<  pair.first << ": " << pair.second << " ocorrencias" << endl;
    }
    cout << endl;







    cout << "################### biblia-na-np-lo.txt ###############################" << endl;

    //arquivo: biblia-na-np-lo.txt
    //Declaração da estrutura
    BinarySearchTree<string> bst3;
    BinaryAVLTree<string> avl3;
    cout << endl;

    //Leitura do arquivo
    string word3;
    ifstream theInput3("./data/biblia-na-np-lo.txt"); // Abre o arquivo para leitura "mam-na-np-lo.txt"/ "exame_10000-na-np-lo.txt" / "biblia-na-np-lo.txt"

    nPalavras = 0; // Resultado item B - número de palavras
    while (theInput3 >> word3)
    {
        bst3.searchInsert(word3);
        avl3.searchInsert(word3);

        nPalavras++;
    }
    theInput3.close();

    //Impressão dos dados
    cout << "-------- TABELA COM OS RESULTADOS OBTIDOS ---------" << endl;

    cout << "A) PALAVRAS DISTINTAS: " << bst3.countDistinctWords() << endl;
    cout << "B) PALAVRAS: " << nPalavras << endl;
    cout << "C) ALTURA DA ARVORE MINIMA: " << bst3.alturaArvoreMinima() << endl;
    cout << "D) ALTURA ABB: " << bst3.height() << endl;
    cout << "E) FOLHAS ABB: " << bst3.leaves() << endl;
    cout << "F) COMPARACOES DE PALAVRAS NA BUSCA COM INSERCAO ABB: " << bst3.comparisonCount << endl;
    cout << "G) ALTURA AVL: " << avl3.height() << endl;
    cout << "H) FOLHAS AVL: " << avl3.leaves() << endl;
    cout << "I) COMPARACOES DE PALAVRAS NA BUSCA COM INSERCAO AVL: " << avl3.comparisonCount << endl;
    cout << "J) ROTACOES NA BUSCA COM INSERCAO AVL: " << avl3.rotationCount << endl;

    cout << "----------- ESTATISTICAS ---------- " << endl;

    media1 = round( float(bst3.comparisonCount) / float(nPalavras) * 100) / 100;
    media2 = round( float(avl3.rotationCount) / float(nPalavras) * 100) / 100; 
    media3 = round( float(avl3.rotationCount) / float(bst3.countDistinctWords()) * 100) / 100;   

    cout << "1) Media de comparacoes por palavra ABB = " << media1 << endl;
    cout << "2) Media de comparacoes por palavra AVL = " << media2 << endl; //tem que ser float com 2 casas
    cout << "3) Media de rotacoes por palavra distinta AVL = " << media3 << endl << endl; //tem que ser float com 2 casas

    cout << "----------- Palavras mais frequentes ---------- " << endl;
    
    bst3.showFrequency();
    topFrequencies = bst3.getTopFrequencies(10);
    i = 0;
    for (const auto& pair : topFrequencies) {
        i++;
        cout << i <<") " <<  pair.first << ": " << pair.second << " ocorrencias" << endl;
    }
    cout << endl;









    return 0;
}
