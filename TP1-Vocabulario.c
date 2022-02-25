#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char string[10000000];      // uma frase de ate x caracteres
char vetor[10000000][30];   // x palavras de ate y caracteres cada
int i, j, Npalavras, k, l;

int gera_Vocabulario(){
    for(i = 0; i < strlen(string); i++){
        if(string[i] != ' ' && string[i] != ',' && string[i] != '.' && string[i] != '"' && string[i] != '\n'){
            if(string[i] != '1' && string[i] != '2' && string[i] != '3' && string[i] != '4' && string[i] != '5'){
                vetor[j][k] = string[i];
                k++;
            }
        }
        else if(string[i+1] != ' ' && string[i+1] != ',' && string[i+1] != '.' && string[i+1] != '"' && string[i] != '\n'){
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

int main(){
    Npalavras = 1;
    FILE *Nota = fopen("Nota1.txt", "r");
    FILE *Vocabulario = fopen("vocabulario.txt", "w");

    while(!feof(Nota)){
        if(fgets(string, 100000, Nota)){
            gera_Vocabulario();
        };
    }
    
    for(i = 0; i < Npalavras - 1; i++){
        fputs(vetor[i],Vocabulario);
        fputs("\n",Vocabulario);
    }

    fclose(Vocabulario);
    fclose(Nota);
    return 0;
}