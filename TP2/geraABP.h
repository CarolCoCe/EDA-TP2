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
** Saída: int
*/
int pegaChave(char *linha);

/*
** Função que recebe um nó e uma chave e insere na árvore
** Entrada: *no, chave
** Saída: nó
*/
TNo* inserirArvore (TNo *no, int chave);

/*
** Função que recebe um arquivo, lê os itens que o arquivo contém,
** faz a chamada para as funções pegaChave e inserirÁrvore e retorna a raiz
** Entrada: *arquivo
** Saída: raiz
*/
TNo* carregaDados(FILE *arquivo);


/*
** Função para calcular a altura do nó,
** calcula a altura da árvore da esquerda e da fireira e retorna a maior delas
** Entrada: *no
** Saída: altura
*/
int calculaAlturaNo(TNo *no);

/*
** Função que calcula fator de balanceamento,
** Entrada: *no
*/
void calculaFatorBalanceamento(TNo *no);