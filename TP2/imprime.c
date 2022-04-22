#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Pegar o tipo TNo depois na gera abp ou main e apagar isso aqui
struct No
{
    int chave;
    struct No *esquerda;
    struct No *direita;
    int FatBal;
};
typedef struct No TNo;

void imprimeArvore(TNo *raiz){
    TNo *no;
    no = raiz;

    while (no -> esquerda != NULL){
        no = no ->esquerda;
    }
    printf(no ->esquerda);

}