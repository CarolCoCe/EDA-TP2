#include "TP1-Vocabulario.h"
#include "TP1-IDF.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char string[10000000];      // uma frase de ate x caracteres
char vetor[10000000][30];   // x palavras de ate y caracteres cada
char vetorNota1[10000000][30], vetorNota2[10000000][30], vetorNota3[10000000][30], vetorNota4[10000000][30], vetorNota5[10000000][30];
int i, j, Npalavras, k, l;

int limpa(){
    for(int z = 0; z < 10000000; z++){
        string[z] = NULL;
        for(int y = 0; y < 30; y++){
            vetor[z][y] = NULL;
        }
    }

    return 0;
}

int copiar(char copia[10000000][30]){
    for(int x = 0; x < Npalavras - 1; x++){
        for(int y = 0; y < 30; y++){
            copia[x][y] = vetor[x][y];
        }
    }
    return 0;
}

/* FUNÇÃO UTILIZADA PRA GERAR OS ARQUIVOS .txt DOS VETORES CORRESPONDETES A CADA NOTA (UTILIZADO PARA ILUSTRAR O VETOR)
int voca(char copia[10000000][30], FILE *Vocabulario){
    for(i = 0; i < Npalavras - 1; i++){
        fputs(copia[i],Vocabulario);
        fputs("\n",Vocabulario);
    }
    return 0;
}*/

int gera_Vocabulario(){
    for(i = 0; i < strlen(string); i++){
        if(string[i] != ' ' && string[i] != ',' && string[i] != '.' && string[i] != '"' && string[i] != '\n' && string[i] != '\0'){
            if(string[i] != '1' && string[i] != '2' && string[i] != '3' && string[i] != '4' && string[i] != '5'){
                vetor[j][k] = string[i];
                k++;
            }
        }
        else if(string[i+1] != ' ' && string[i+1] != ',' && string[i+1] != '.' && string[i+1] != '"' && string[i] != '\n' && string[i] != '\0'){
            if(k > 3){
                for(l = 0; l < j; l++){
                    if(strcmp(vetor[l], vetor[j]) == 0){
                        for(l = 0; l < 30; l++){
                            vetor[j][l] = '\0';  //limpa todos os caracteres pra inserir a nova palavra no lugar da repetida
                        }
                        l = j;
                        j--;
                        Npalavras--;
                    }
                }
                j++;
                Npalavras++;  
            }
            k = 0;
        }  
    }

    k = 0;
    return 0;
}

int mainVocabulario(char arq[100], int nota){ // PARA GERAR OS ARQUIVOS .txt DO VOCABULARIO DEVE ADICIONAR O PARAMETRO: char voc[100]
    Npalavras = 1;
    FILE *Nota = fopen(arq, "r");
    //FILE *Vocabulario = fopen(voc, "w");
    Dicionario** dicionario;

    j = 0;
    while(!feof(Nota)){
        if(fgets(string, 100000, Nota)){
            gera_Vocabulario();
        };
    }

    switch (nota)
    {
    case 1:
        copiar(vetorNota1);
        //voca(vetorNota1, Vocabulario);
        break;
    case 2:
        copiar(vetorNota2);
        //voca(vetorNota2, Vocabulario);
        break;
    }

    for(int i = 0; i <= Npalavras; i++) {
        dicionario = contaVocabulario(dicionario, vetor[i], Npalavras);
    }

    limpa();
    //fclose(Vocabulario);
    fclose(Nota);
    return 0;
}