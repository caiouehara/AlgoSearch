#include "./Tree/Tree.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <set>
#include <cmath>

using namespace std;

int main()
{
    cout << endl
         << "------------------------------------------------" << endl
         << "TRABALHO 4 - ALGORITMO E ESTRUTURA DE DADOS" << endl
         << "--- CONSTRUCAO DE ABB A PARTIR DE TEXTOS ---" << endl
         << endl
         << "ALUNOS: ANDRE LUIZ DE SOUZA MURAKAMI N USP 5631500" << endl
         << "        CAIO UEHARA MARTINS N USP 1367202" << endl;
    cout << endl;

    BinarySearchTree<string> bst;

    string word;
    ifstream theInput("./data/mam-na-np-lo.txt"); // Abre o arquivo para leitura "mam-na-np-lo.txt"/ "exame_10000-na-np-lo.txt" / "biblia-na-np-lo.txt"

    float count_B = 0; // Resultado item B - número de palavras

    while (theInput >> word)
    {
        bst.insert(word);
        count_B++;                // contador de palavras totais
        bst.search(word) ? 1 : 0; // contador de comparações de palavras na busca com inserção ABB
    }

    theInput.close();

    // TABELA COM OS RESULTADOS OBTIDOS - ABB:
    cout << "mam-na-np-lo.txt" << endl;

    cout << "-------- TABELA COM OS RESULTADOS OBTIDOS - ABB ---------" << endl;

    // A) Palavras distintas
    // cout << "A) PALAVRAS DISTINTAS: " << bst.countDistinctWords() << endl;

    // B) Palavras
    cout << "B) PALAVRAS: " << count_B << endl;

    // C) Altura da árvore mínima
    // cout << "C) ALTURA DA ARVORE MINIMA: " << bst.alturaArvoreMinima() << endl;

    // D) Altura ABB
    cout << "D) ALTURA ABB: " << bst.height() << endl;

    // E) Folhas ABB
    cout << "E) FOLHAS ABB: " << bst.leaves() << endl;

    // F) Comparações de palavras na busca com inserção ABB
    // cout << "F) COMPARACOES DE PALAVRAS NA BUSCA COM INSERCAO ABB: " << count_F << endl;

    // G) Altura AVL
    // cout << "G) ALTURA AVL: " <<  << endl;

    // H) Folhas AVL
    // cout << "H) FOLHAS AVL: " <<  << endl;

    // I) Comparações de palavras na busca com inserção AVL
    // cout << "I) COMPARACOES DE PALAVRAS NA BUSCA COM INSERCAO AVL: " <<  << endl;

    // J) Rotações na busca com inserção AVL
    // cout << "J) ROTACOES NA BUSCA COM INSERCAO AVL: " <<  << endl;

    // ------------------------------- ESTATÍSTICAS ABB --------------------------------------------
    cout << "----------- ESTATISTICAS ---------- " << endl;
    // Preencha a tabela seguinte com os resultados da tabela anterior. Represente números com duas casas decimais.

    // 1) Média de comparações por palavra ABB = F/B
    // float media1 = round(count_F / count_B * 100) / 100;
    // cout << "1) Media de comparacoes por palavra ABB = " << media1 << endl
    //     << endl;

    BinarySearchTree<string> bst2;

    string word2;
    ifstream theInput2("./data/exame_10000-na-np-lo.txt"); // Abre o arquivo para leitura "mam-na-np-lo.txt"/ "exame_10000-na-np-lo.txt" / "biblia-na-np-lo.txt"

    count_B = 0; // Resultado item B - número de palavras

    while (theInput2 >> word2)
    {
        bst2.insert(word2);
        count_B++;                  // contador de palavras totais
        bst2.search(word2) ? 1 : 0; // contador de comparações de palavras na busca com inserção ABB
    }

    theInput2.close();

    // TABELA COM OS RESULTADOS OBTIDOS - ABB:
    cout << "exame_10000-na-np-lo" << endl;
    cout << "-------- TABELA COM OS RESULTADOS OBTIDOS - ABB ---------" << endl;

    // A) Palavras distintas
    // cout << "A) PALAVRAS DISTINTAS: " << bst.countDistinctWords() << endl;

    // B) Palavras
    cout << "B) PALAVRAS: " << count_B << endl;

    // C) Altura da árvore mínima
    // cout << "C) ALTURA DA ARVORE MINIMA: " << bst.alturaArvoreMinima() << endl;

    // D) Altura ABB
    cout << "D) ALTURA ABB: " << bst2.height() << endl;

    // E) Folhas ABB
    cout << "E) FOLHAS ABB: " << bst2.leaves() << endl;

    // F) Comparações de palavras na busca com inserção ABB
    // cout << "F) COMPARACOES DE PALAVRAS NA BUSCA COM INSERCAO ABB: " << count_F << endl;

    // G) Altura AVL
    // cout << "G) ALTURA AVL: " <<  << endl;

    // H) Folhas AVL
    // cout << "H) FOLHAS AVL: " <<  << endl;

    // I) Comparações de palavras na busca com inserção AVL
    // cout << "I) COMPARACOES DE PALAVRAS NA BUSCA COM INSERCAO AVL: " <<  << endl;

    // J) Rotações na busca com inserção AVL
    // cout << "J) ROTACOES NA BUSCA COM INSERCAO AVL: " <<  << endl;

    // ------------------------------- ESTATÍSTICAS ABB --------------------------------------------
    cout << endl
         << "----------- ESTATISTICAS ---------- " << endl;
    // Preencha a tabela seguinte com os resultados da tabela anterior. Represente números com duas casas decimais.

    // 1) Média de comparações por palavra ABB = F/B
    // float media1 = round(count_F / count_B * 100) / 100;
    // cout << "1) Media de comparacoes por palavra ABB = " << media1 << endl
    //     << endl;

    cout << "biblia-na-np-lo" << endl;
    cout << "-------- TABELA COM OS RESULTADOS OBTIDOS - ABB ---------" << endl;

    BinarySearchTree<string> bst3;

    string word3;
    ifstream theInput3("./data/biblia-na-np-lo.txt"); // Abre o arquivo para leitura "mam-na-np-lo.txt"/ "exame_10000-na-np-lo.txt" / "biblia-na-np-lo.txt"

    count_B = 0; // Resultado item B - número de palavras

    while (theInput3 >> word3)
    {
        bst3.insert(word3);
        count_B++;                  // contador de palavras totais
        bst3.search(word3) ? 1 : 0; // contador de comparações de palavras na busca com inserção ABB
    }

    theInput3.close();

    // A) Palavras distintas
    // cout << "A) PALAVRAS DISTINTAS: " << bst.countDistinctWords() << endl;

    // B) Palavras
    cout << "B) PALAVRAS: " << count_B << endl;

    // C) Altura da árvore mínima
    // cout << "C) ALTURA DA ARVORE MINIMA: " << bst.alturaArvoreMinima() << endl;

    // D) Altura ABB
    cout << "D) ALTURA ABB: " << bst3.height() << endl;

    // E) Folhas ABB
    cout << "E) FOLHAS ABB: " << bst3.leaves() << endl;

    // F) Comparações de palavras na busca com inserção ABB
    // cout << "F) COMPARACOES DE PALAVRAS NA BUSCA COM INSERCAO ABB: " << count_F << endl;

    // G) Altura AVL
    // cout << "G) ALTURA AVL: " <<  << endl;

    // H) Folhas AVL
    // cout << "H) FOLHAS AVL: " <<  << endl;

    // I) Comparações de palavras na busca com inserção AVL
    // cout << "I) COMPARACOES DE PALAVRAS NA BUSCA COM INSERCAO AVL: " <<  << endl;

    // J) Rotações na busca com inserção AVL
    // cout << "J) ROTACOES NA BUSCA COM INSERCAO AVL: " <<  << endl;

    // ------------------------------- ESTATÍSTICAS ABB --------------------------------------------
    cout << endl
         << "----------- ESTATISTICAS ---------- " << endl;
    // Preencha a tabela seguinte com os resultados da tabela anterior. Represente números com duas casas decimais.

    // 1) Média de comparações por palavra ABB = F/B
    // float media1 = round(count_F / count_B * 100) / 100;
    // cout << "1) Media de comparacoes por palavra ABB = " << media1 << endl
    //     << endl;

    return 0;
}
