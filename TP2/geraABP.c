#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "geraABP.h"


int pegaChave(char *linha){
    char *chave;
    int chaveint;
    chave = strtok(linha, ",");
    chaveint = (int)chave;
    return chaveint;
}

TNo* inserirArvore (TNo *no, int chave){
    if(no == NULL){
        no = (TNo *)malloc(sizeof(TNo));
        no -> chave = chave;
        no -> direita = NULL;
        no -> esquerda = NULL;
        no -> FatBal = 0;
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
        int chave;
        chave = pegaChave(linha);
        printf("%d", chave);
        inserirArvore(raiz, chave);
        free (copiaLinha);
    }

    return raiz;
}
