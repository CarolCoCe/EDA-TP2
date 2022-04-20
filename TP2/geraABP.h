/*
** Cabeçalhos das funções implementadas no módulo geraABP.c ,
** que lê um arquivo e gera uma árvore ABP
*/


#include <stdio.h>

/*
** Estrutura base da árvore
*/
struct No
    {
        int chave;
        struct No *esquerda;
        struct No *direita;
        int FatBal;
    };
    typedef struct No TNo;

/*
** Função que retorna uma chave da linha que recebe
** Entrada: *linha
** Saída: *chave
*/
char* pegaChave(char *linha);

/*
** Função que recebe um nó e uma chave e insere na árvore
** Entrada: *no, chave
** Saída: nó
*/
TNo* inserirArvore (TNo *no, int chave);

/*
** Funçãp que recebe um arquivo, lê os itens que o arquivo contém,
** faz a chamada para as funções pegaChave e inserirÁrvore e retorna a raiz
** Entrada: *arquivo
** Saída: raiz
*/
TNo* carregaDados(FILE *arquivo);