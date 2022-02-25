#include "TP1-Aglutina.h"
#include <stdio.h>
#include <stdlib.h>

char AcharNota(char *review){
    char nota;
    int i = 1;
    //percorrer review já tirando as primeiras aspas
    //diferente de 0 que é o final string
    while(review[i] != 0)
    {
        review[i-1] = review[i];
        if(review[i] == '"')
        {
            nota = review[i+2];
            break;
        }
        i++;
    }

    return nota;
}
void AglutinaPorNota(FILE *arquivoP, FILE *fNota1P, FILE *fNota2P,FILE *fNota3P,FILE *fNota4P, FILE *fNota5P ){
    char review[100000];
    char nota;
    char *linha;

    //pular o cabeçalho
    fseek(arquivoP,13,0);

    while(fgets(review,100000,arquivoP) != NULL)
    {
        nota = AcharNota(review);

        if(nota == '1'){
            fputs(review,fNota1P);
            fputs("\n", fNota1P);
            }
        if(nota == '2'){
            fputs(review,fNota2P);
            fputs("\n",fNota2P);
            }
        if(nota == '3'){
            fputs(review,fNota3P);
            fputs("\n",fNota3P);
            }
        if(nota == '4')
        {
            fputs(review,fNota4P);
            fputs("\n",fNota4P);
        }
            
        if(nota == '5'){
            fputs(review,fNota5P);
            fputs("\n", fNota5P);
        }
    }

    
    fclose(arquivoP);
    fclose(fNota1P);
    fclose(fNota2P);
    fclose(fNota3P);
    fclose(fNota4P);
    fclose(fNota5P);
    printf ("Arquivo lido e reviews aglutinadas com sucesso\n");

    }


/*int main(void) {
    FILE *arquivoP= fopen("ArquivoReviewsTeste.cvs", "r");
    FILE *fNota1P = fopen("Nota1.txt", "a");
    FILE *fNota2P = fopen("Nota2.txt", "a");
    FILE *fNota3P = fopen("Nota3.txt", "a");
    FILE *fNota4P = fopen("Nota4.txt", "a");
    FILE *fNota5P = fopen("Nota5.txt", "a");

    if (arquivoP == NULL){
        printf("Arquivo não encontrado\n");
    }
	AglutinaPorNota(arquivoP, fNota1P, fNota2P, fNota3P, fNota4P, fNota5P);
	return 0;
}*/

