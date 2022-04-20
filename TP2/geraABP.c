#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "geraABP.h"


char* pegaChave(char *linha){
    char *chave;
    chave = strtok(linha, ",");
    return chave;
}

TNo* inserirArvore (TNo *no, int chave){
    if(no == NULL){
        no = (TNo *)malloc(sizeof(TNo));
        no -> chave = chave;
        no -> direita = NULL;
        no -> esquerda = NULL;
        no -> FatBal = NULL;
        printf("inseriu na arvore\n\n");
    }
    else{
        if(chave < no -> chave){
            no -> esquerda = inserirArvore(no  -> esquerda, chave);
            printf("foi pra esquerda\n");
        }
        if(chave > no -> chave){
            no -> direita = inserirArvore(no  -> direita, chave);
            printf("foi pra direita\n");
        }
    }
    return no;
}

TNo* carregaDados(FILE *arquivo){
    char linha[1024];
    printf("carregando dados...\n");
    TNo *raiz = NULL;
    while(fgets(linha,1024,arquivo) != NULL){
        char *copiaLinha = strdup(linha);
        char *chave;
        chave = pegaChave(linha);
        inserirArvore(raiz, chave);
        free (copiaLinha);
        free(chave);
    }

    return raiz;
}
