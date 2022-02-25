//
// Created by amand on 25/02/2022.
//

#include "TP1-IDF.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
Função contaVocabulario verifica a quantidade de vezes que uma palavra aparece no vetor
de vocabulário. 
Argumentos: 
Dicionário - um vetor de struct para guardar a palavra e a quantidade de vezes que 
ela aparece no vocabulário.
Palavra - palavra do vetor de vocabulário, gerado no for da main
Tamanho - tamanho total do vetor
*/
Dicionario* contaVocabulario(Dicionario* dicionario, char* palavra, int tamanho) {

    //verifica se o vetor está vazio

    if(tamanho == 0) {
        dicionario = (Dicionario*) calloc(1, sizeof(Dicionario)); // aloca 1 possição para o vetor origem
        dicionario[0].palavra = (char*) calloc(strlen(palavra), sizeof(char)); // aloca o espaço da primeira possição do mesmo tamanho da nova palavra
        strcpy(dicionario[0].palavra, palavra); //copia a string-origem para a string- destino
        dicionario[0].quantidade++; // palavra inserida, portanto o numero minimo que ela aparece é
        return dicionario;
    } else {
        int posicao = verificaPalavra(palavra, dicionario, tamanho);
        if(posicao >= 0){
            dicionario = substituiDicionario(dicionario, tamanho, posicao); // aloca 1 nova posição para o vetor origem
            dicionario[posicao].palavra = (char*)calloc(strlen(palavra),sizeof(char)); //aloca espaço do mesmo tamanho da nova palavra no vetor origem
            strcpy(dicionario[posicao].palavra, palavra); //copia a nova palavra para o a posição de inserção do vetor origem
            dicionario[posicao].quantidade++; // palavra inserida, portanto o numero minimo que ela aparece é
        }
    }
    return dicionario;
}

/*
Função que verifica se a palavra já está no vetor de dicionario. 
Argumentos: 
Dicionário - um vetor de struct para guardar a palavra e a quantidade de vezes que 
ela aparece no vocabulário.
Palavra - palavra do vetor de vocabulário, gerado no for da main
Tamanho - tamanho total do vetor
*/
int verificaPalavra(char* palavra, Dicionario* dicionario, int tamanho) {
    int inicio = 0;
    int meio;
    int final = tamanho - 1;

    if(strcmp(palavra, dicionario[0].palavra) < 0) {
        return 0;
    }

    while(inicio <= final) {
        meio = (inicio + final)/2;

        if(strcmp(palavra, dicionario[meio].palavra) < 0) {
            final = meio - 1;
        } else {
            if(strcmp(palavra, dicionario[meio].palavra) > 0) {
                inicio = meio + 1;
            } else {
                dicionario[meio].quantidade++;
                return -1;
            }
        }
    }

    if(strcmp(palavra, dicionario[meio].palavra) < 0) {
        return meio;
    } else {
        return meio + 1;
    }
}


/*
Função substituiDicionario para alocar mais um espaço no vetor de dicionário
Argumentos: 
Dicionário - um vetor de struct para guardar a palavra e a quantidade de vezes que 
ela aparece no vocabulário.
Posicao - um inteiro para ser usado como index
Tamanho - tamanho total do vetor
*/
Dicionario* substituiDicionario(Dicionario* dicionario, int tamanho, int posicao){
    int index = 0;
    Dicionario* novoDicionario = (Dicionario*) calloc(tamanho + 1, sizeof(Dicionario)); //cria vetor de destino do tamanho do vetor atual(origem) + 1

    for(int i = 0; i < tamanho + 1; i++) {
        if(i == posicao) {
            continue;
        } else {
            novoDicionario[i].palavra = (char*) calloc(strlen(dicionario[index].palavra), sizeof(char)); //aloca espaço para palavra no vetor de destino do mesmo tamanho da palavra do vetor de origem
            strcpy(novoDicionario[i].palavra, dicionario[index].palavra); // copia a palavra na posição do index da origem no vetor de destino
            novoDicionario[i].quantidade = dicionario[index].quantidade; // atribui o numero de repetições de uma palavra do vetor origem para o vetor destino
            index++; // atrasa a posição dos valores do vetor de origem em relaçao aos do destino
        }
    }

    for(int i = 0; i < tamanho; i++)
        free(dicionario[i].palavra); // libera todos os char* do vetor de origem
    free(dicionario); // libera o vetor de origem // libera o vetor de origem, os dados ja estao copiados

    return novoDicionario;
}

int main(void) {
    int i = 0;
    int numPalavras = 0;
    char* palavras[50];
    char line[50];
    Dicionario* dicionario;

    FILE *arquivo;
    arquivo = fopen("teste.txt", "r");

    if (arquivo == NULL)
        return EXIT_FAILURE;

    while(fgets(line, sizeof line, arquivo) != NULL)
    {
        //Adiciona cada palavra no vetor
        palavras[i] = strdup(line);

        i++;

        //Conta a quantidade de palavras
        numPalavras++;
    }

     for(int i = 0; i <= numPalavras; i++){
        dicionario = contaVocabulario(dicionario, palavras[i], numPalavras);
    }
    
    fclose(arquivo);
}


