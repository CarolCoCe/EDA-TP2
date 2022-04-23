#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "geraABP.h"

int main(void) {
    int resposta = 0;
    FILE *arquivo = NULL;
    TNo *raizMain = NULL;
    while (resposta != 4)
    {
        printf("\n\nMENU - Escolha uma das opções abaixo    \n\n");
        printf("'1' - Gera ABP (Arvore Binária de Pesquisa)\n");
        printf("'2' - Calcula Fator de Balanceamento\n");
        printf("'3' - Imprime ABP\n");
        printf("'4' - Sair do programa\n\n");
        scanf("%d", &resposta);

        if (resposta == 1){
            arquivo = fopen("DocTeste.cvs", "r");
            if(arquivo == NULL){
                printf("Erro ao abrir o arquivo\n");
            }
            else{
                printf("O arquivo foi encontrado...\n");
            
            }
            printf("\nGerando árvore...\n");
            raizMain = carregaDados(arquivo);
        }
        if (resposta == 2){
            printf("\nCalculando fator de balanceamento...\n");
            if (raizMain == NULL){
                printf("Os dados não foram carregados, selecione a opção 1 primeiro\n");
            }
            else{
                calculaFatorBalanceamento(raizMain);
            }
        }
        if (resposta == 3){
            printf("\nImprimindo árvore...\n");
            if (raizMain == NULL){
                printf("Os dados não foram carregados, selecione a opção 1 primeiro\n");
            }
            else{
                imprimir(raizMain,0);
            }
        }
        if (resposta == 4){
            fclose(arquivo);
            apaga(raizMain);
            printf("\nSaindo...\n");
            break;  
        }
    }
    
	return 0;
}
