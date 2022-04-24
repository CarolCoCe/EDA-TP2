#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "geraABP.h"

TNo *inserirArvore(TNo *no, int chave)
{
    if (no == NULL)
    {
        no = (TNo *)malloc(sizeof(TNo));
        no->chave = chave;
        no->direita = NULL;
        no->esquerda = NULL;
        no->FatBal = 0;
        printf("inseriu na arvore\n\n");
    }
    else
    {
        if (chave < no->chave)
        {
            no->esquerda = inserirArvore(no->esquerda, chave);
            printf("foi pra esquerda\n");
        }
        if (chave > no->chave)
        {
            no->direita = inserirArvore(no->direita, chave);
            printf("foi pra direita\n");
        }
    }
    return no;
}

TNo *carregaDados(FILE *arquivo)
{
    char linha[1024];
    printf("carregando dados...\n");
    TNo *raiz = NULL;
    int chaves[1024];
    int i = 0;
    while (fscanf(arquivo, "%d,", &chaves[i]) != -1)
    {
        printf("%d\n", chaves[i]);
        raiz = inserirArvore(raiz, chaves[i]);
        i++;
    }
    return raiz;
}

int calculaAlturaNo(TNo *no)
{
    if (no == NULL)
        return 0;

    int alturaEsquerda = calculaAlturaNo(no->esquerda);
    int alturaDireita = calculaAlturaNo(no->direita);

    if (alturaEsquerda < alturaDireita)
    {
        alturaDireita++;
        return alturaDireita;
    }
    else
    {
        alturaEsquerda++;
        return alturaEsquerda;
    }
}

void calculaFatorBalanceamento(TNo *no)
{
    if (no == NULL)
        return;

    int alturaEsquerdaFatBal = calculaAlturaNo(no->esquerda);
    int alturaDireitaFatBal = calculaAlturaNo(no->direita);

    int fatorBalanceamento = alturaEsquerdaFatBal - alturaDireitaFatBal;

    no->FatBal = fatorBalanceamento;

    calculaFatorBalanceamento(no->esquerda);
    calculaFatorBalanceamento(no->direita);
}

void imprimir(TNo *raiz, int nivel)
{
    int i;
    if (raiz)
    {
        imprimir(raiz->esquerda, nivel + 1);
        printf("\n\n");

        for (i = 0; i < nivel; i++)
            printf("\t");

        printf("chave: %d, fator balanceamento: %d", raiz->chave, raiz->FatBal);
        imprimir(raiz->direita, nivel + 1);
    }
}

void apaga(TNo *raiz)
{
    if (raiz != NULL)
    {
        apaga(raiz->esquerda);
        apaga(raiz->direita);
        free(raiz);
    }
}