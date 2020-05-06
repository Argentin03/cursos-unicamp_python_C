/*Carlos Augusto Jardim Chiarelli 165685
Este arquivo contém a implementação da interface para vetores, ou seja, o conjunto de algoritmos que realizarão as operações disponibilizadas ao cliente*/

#include "vetor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

dados_vetor cria_vetor(){
    dados_vetor v;
    v = malloc(sizeof(dados_vetor_struct));
    if(v == NULL)
        exit (1);
    v->vetor = malloc(sizeof(nome));
    if(v->vetor == NULL)
        exit (1);
    v->ocupado = 0;
    v->alocado = 1;
    return v;
}

void adiciona_elemento_vetor(dados_vetor v){
    int i;
    nomes aux;
    nome adicionado;
    if(v->ocupado == v->alocado){
        aux = v->vetor;
        v->alocado *= 2;
        v->vetor = malloc(v->alocado * sizeof(nome));
        if(v->vetor == NULL)
            exit (1);
        for(i = 0; i < v->ocupado; i++)
            v->vetor[i] = aux[i];
        free(aux);
    }
    scanf("%s", adicionado.caracteres);
    strcpy((v->vetor[v->ocupado]).caracteres, adicionado.caracteres);
    v->ocupado++;
}

void apaga_vetor(dados_vetor v){
    free(v->vetor);
    free(v);
}
