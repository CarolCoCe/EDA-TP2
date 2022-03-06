#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

// TF = num de vezes que uma palavra aparece em um documento / num palavras do documento
// IDF = log(total de documentos / num de documentos com o termo)
// TFIDF = TF * IDF

//Esses vetores Notasx serão vetores de cada arquivo de nota, além do vocabulário geral
double calculaIDF(char palavra[30], char notas1[1000000], char notas2[1000000], char notas3[1000000], char notas4[1000000], char notas5[1000000]){
    double idf = 0;
    int numDoc = 0;

    if(strstr(notas1,palavra) != NULL){
        numDoc++;
    }
    if(strstr(notas2,palavra) != NULL){
        numDoc++;
    }
    if(strstr(notas3,palavra) != NULL){
        numDoc++;
    }
    if(strstr(notas4,palavra) != NULL){
        numDoc++;
    }
    if(strstr(notas5,palavra) != NULL){
        numDoc++;
    }
    //idf = log(5/numDoc);
    return idf;
}

// TF = num de vezes que uma palavra aparece em um documento / num palavras do documento
double calculaTF(char *palavra, int qtdPalavrasDoc, char *notas){
    printf("Entrou em calculatf\n");
    double tf = 0;
    int numRepeticoes = 0;
    int tamPalavra = 0;
    int tamNotas = 0;
    int cont = 0;

    tamPalavra = strlen(palavra);
    tamNotas = strlen(notas);
    // Esses dois laços pegam o numero de repetições da palavra no vetor de reviews de cada nota
    for(int i = 0; i == tamNotas; i++){
        if (notas + i == palavra){

            cont = 1;
            for(int j = 1; j == tamPalavra; j++){
                if(notas + (i+j) == palavra + j){
                    cont++;
                }
                else{
                    break;
                }
            }
            if (cont == tamPalavra){
                numRepeticoes++;
            }
        }
    }

    tf = numRepeticoes / qtdPalavrasDoc;
    return tf;
}
void exibeTFIDF(){

    printf("Vocabulário | Nota 1 | Nota 2 | Nota 3 | Nota 4 | Nota 5");

}

void ordenaVetor(int vetor[1000000], int tamanho) {

    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = i; j < tamanho - 1; j++) {
            if (vetor[i] < vetor[j]) {
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
}

int main(void)
{
    //Dessa página do codigo todo, ta faltando:
    //  testar se a função calcula idf e calcula tf estão funcionando
    //  Fazer a função de exibir tfidf pra ja colocar na main depois
    char *nota1 = NULL;
    char *palavra = NULL;
    int numPalavras = 6;
    int resultado = 0;
    resultado = calculaTF(palavra,numPalavras,nota1);
    printf("A quantidade de vezes que essa palavra aparece é %d vezes\n", resultado);

    return 0;
}
