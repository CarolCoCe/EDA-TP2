//
// Created by amand on 25/02/2022.
//

#ifndef TP1_EDA_GP1_TP1_IDF_H
#define TP1_EDA_GP1_TP1_IDF_H

#endif //TP1_EDA_GP1_TP1_IDF_H

struct dicionario{
    char* palavra;
    int quantidade;
};
typedef struct dicionario Dicionario;

Dicionario* contaVocabulario(Dicionario* dicionario, char* palavra, int tamanho);
int verificaPalavra(char* palavra, Dicionario* dicionario, int tamanho);
Dicionario* substituiDicionario(Dicionario* dicionario, int tamanho, int posicao);