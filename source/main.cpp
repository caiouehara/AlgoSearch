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


    //arquivo: mam-na-np-lo.txt
    //Declaração da estrutura
    BinarySearchTree<string> bst1;
    BinaryAVLTree<string> avl1;
    cout << endl;

    //Leitura do arquivo
    string word1;
    ifstream theInput1("./data/mam-na-np-lo.txt"); // Abre o arquivo para leitura "mam-na-np-lo.txt"/ "exame_10000-na-np-lo.txt" / "biblia-na-np-lo.txt"

    float count_B = 0; // Resultado item B - número de palavras
    while (theInput1 >> word1)
    {
        bst1.searchInsert(word1);
        avl1.searchInsert(word1);

        count_B++;
    }
    theInput1.close();

    //Impressão dos dados
    cout << "mam-na-np-lo.txt" << endl;
    cout << "-------- TABELA COM OS RESULTADOS OBTIDOS ---------" << endl;

    cout << "A) PALAVRAS DISTINTAS: " << bst1.countDistinctWords() << endl;
    cout << "B) PALAVRAS: " << count_B << endl;
    cout << "C) ALTURA DA ARVORE MINIMA: " << bst1.alturaArvoreMinima() << endl;
    cout << "D) ALTURA ABB: " << bst1.height() << endl;
    cout << "E) FOLHAS ABB: " << bst1.leaves() << endl;

    // F) Comparações de palavras na busca com inserção ABB
    // cout << "F) COMPARACOES DE PALAVRAS NA BUSCA COM INSERCAO ABB: " << count_F << endl;

    cout << "G) ALTURA AVL: " << avl1.height() << endl;
    cout << "H) FOLHAS AVL: " << avl1.leaves() << endl;

    // I) Comparações de palavras na busca com inserção AVL
    // cout << "I) COMPARACOES DE PALAVRAS NA BUSCA COM INSERCAO AVL: " <<  << endl;

    // J) Rotações na busca com inserção AVL
    // cout << "J) ROTACOES NA BUSCA COM INSERCAO AVL: " <<  << endl;

    cout << "----------- ESTATISTICAS ---------- " << endl;
    // Preencha a tabela seguinte com os resultados da tabela anterior. Represente números com duas casas decimais.

    // 1) Média de comparações por palavra ABB = F/B
    // float media1 = round(count_F / count_B * 100) / 100;
    // cout << "1) Media de comparacoes por palavra ABB = " << media1 << endl
    //     << endl;

    cout << "----------- Palavras mais frequentes ---------- " << endl;
    
    bst1.showFrequency();
    vector<pair<string, int>> topFrequencies = bst1.getTopFrequencies(10);
    cout << endl << "Palavras mais frequentes:" << endl;
    int i = 0;
    for (const auto& pair : topFrequencies) {
        i++;
        cout << i <<") " <<  pair.first << ": " << pair.second << " ocorrencias" << endl;
    }
    cout << endl;

    //arquivo: exame_10000-na-np-lo
    //Declaração da estrutura
    BinarySearchTree<string> bst2;
    BinaryAVLTree<string> avl2;
    cout << endl;

    //Leitura do arquivo
    string word2;
    ifstream theInput2("./data/exame_10000-na-np-lo.txt"); // Abre o arquivo para leitura "mam-na-np-lo.txt"/ "exame_10000-na-np-lo.txt" / "biblia-na-np-lo.txt"

    count_B = 0; // Resultado item B - número de palavras
    while (theInput2 >> word2)
    {
        bst2.searchInsert(word2);
        avl2.searchInsert(word2);

        count_B++;
    }
    theInput2.close();

    //Impressão dos dados
    cout << "exame_10000-na-np-lo.txt" << endl;
    cout << "-------- TABELA COM OS RESULTADOS OBTIDOS ---------" << endl;

    cout << "A) PALAVRAS DISTINTAS: " << bst2.countDistinctWords() << endl;
    cout << "B) PALAVRAS: " << count_B << endl;
    cout << "C) ALTURA DA ARVORE MINIMA: " << bst2.alturaArvoreMinima() << endl;
    cout << "D) ALTURA ABB: " << bst2.height() << endl;
    cout << "E) FOLHAS ABB: " << bst2.leaves() << endl;

    // F) Comparações de palavras na busca com inserção ABB
    // cout << "F) COMPARACOES DE PALAVRAS NA BUSCA COM INSERCAO ABB: " << count_F << endl;

    cout << "G) ALTURA AVL: " << avl2.height() << endl;
    cout << "H) FOLHAS AVL: " << avl2.leaves() << endl;

    // I) Comparações de palavras na busca com inserção AVL
    // cout << "I) COMPARACOES DE PALAVRAS NA BUSCA COM INSERCAO AVL: " <<  << endl;

    // J) Rotações na busca com inserção AVL
    // cout << "J) ROTACOES NA BUSCA COM INSERCAO AVL: " <<  << endl;

    cout << "----------- ESTATISTICAS ---------- " << endl;
    // Preencha a tabela seguinte com os resultados da tabela anterior. Represente números com duas casas decimais.

    // 1) Média de comparações por palavra ABB = F/B
    // float media1 = round(count_F / count_B * 100) / 100;
    // cout << "1) Media de comparacoes por palavra ABB = " << media1 << endl
    //     << endl;

    cout << "----------- Palavras mais frequentes ---------- " << endl;
    bst2.showFrequency();
    topFrequencies = bst2.getTopFrequencies(10);
    cout << endl << "Palavras mais frequentes:" << endl;
    i = 0;
    for (const auto& pair : topFrequencies) {
        i++;
        cout << i <<") " <<  pair.first << ": " << pair.second << " ocorrencias" << endl;
    }
    cout << endl;    

    //arquivo: biblia-na-np-lo
    //Declaração da estrutura
    BinarySearchTree<string> bst3;
    BinaryAVLTree<string> avl3;
    cout << endl;

    //Leitura do arquivo
    string word3;
    ifstream theInput3("./data/biblia-na-np-lo.txt"); // Abre o arquivo para leitura "mam-na-np-lo.txt"/ "exame_10000-na-np-lo.txt" / "biblia-na-np-lo.txt"

    count_B = 0; // Resultado item B - número de palavras
    while (theInput3 >> word3)
    {
        bst3.searchInsert(word3);
        avl3.searchInsert(word3);

        count_B++;
    }
    theInput3.close();

    //Impressão dos dados
    cout << "biblia-na-np-lo.txt" << endl;
    cout << "-------- TABELA COM OS RESULTADOS OBTIDOS ---------" << endl;

    cout << "A) PALAVRAS DISTINTAS: " << bst3.countDistinctWords() << endl;
    cout << "B) PALAVRAS: " << count_B << endl;
    cout << "C) ALTURA DA ARVORE MINIMA: " << bst3.alturaArvoreMinima() << endl;
    cout << "D) ALTURA ABB: " << bst3.height() << endl;
    cout << "E) FOLHAS ABB: " << bst3.leaves() << endl;

    // F) Comparações de palavras na busca com inserção ABB
    // cout << "F) COMPARACOES DE PALAVRAS NA BUSCA COM INSERCAO ABB: " << count_F << endl;

    cout << "G) ALTURA AVL: " << avl3.height() << endl;
    cout << "H) FOLHAS AVL: " << avl3.leaves() << endl;

    // I) Comparações de palavras na busca com inserção AVL
    // cout << "I) COMPARACOES DE PALAVRAS NA BUSCA COM INSERCAO AVL: " <<  << endl;

    // J) Rotações na busca com inserção AVL
    // cout << "J) ROTACOES NA BUSCA COM INSERCAO AVL: " <<  << endl;

    cout << "----------- ESTATISTICAS ---------- " << endl;
    // Preencha a tabela seguinte com os resultados da tabela anterior. Represente números com duas casas decimais.

    // 1) Média de comparações por palavra ABB = F/B
    // float media1 = round(count_F / count_B * 100) / 100;
    // cout << "1) Media de comparacoes por palavra ABB = " << media1 << endl
    //     << endl;

    cout << "----------- Palavras mais frequentes ---------- " << endl;
    
    bst3.showFrequency();
    topFrequencies = bst3.getTopFrequencies(10);
    cout << endl << "Palavras mais frequentes:" << endl;
   i = 0;
    for (const auto& pair : topFrequencies) {
        i++;
        cout << i <<") " <<  pair.first << ": " << pair.second << " ocorrencias" << endl;
    }
    cout << endl;    

    return 0;
}
