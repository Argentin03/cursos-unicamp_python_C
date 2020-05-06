/*Carlos Augusto Jardim Chiarelli 165685
Este arquivo contém a implementação da interface para matrizes, ou seja, o conjunto de algoritmos que realizarão as operações disponibilizadas ao cliente*/

#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

dados_matriz cria_matriz(){
    dados_matriz m;
    m =  malloc(sizeof(dados_matriz_struct));
    if(m == NULL)
        exit (1);
    m->matriz = malloc(sizeof(int*));
    if(m->matriz == NULL)
        exit (1);
    m->matriz[0] = calloc(1, sizeof(int));
    if(m->matriz[0] == NULL)
        exit (1);
    m->matriz[0][0] = 0;
    m->linha_ocupada = 0;
    m->linha_alocada = 1;
    m->coluna_ocupada = 0;
    m->coluna_alocada = 1;
    return m;
}

void adiciona_linha(dados_matriz m){                                           /*linhas correspondem aos livros*/
    int i, j, **matriz_aux;
    if(m->linha_ocupada == m->linha_alocada){
        matriz_aux = m->matriz;
        m->matriz = malloc(m->linha_alocada*2 * sizeof(int*));
        if(m->matriz == NULL)
            exit (1);
        for(i = 0; i < m->linha_alocada*2; i++){
            m->matriz[i] = calloc(m->coluna_alocada, sizeof(int));
            if(m->matriz[i] == NULL)
                exit (1);
        }
        for(i = 0; i < m->linha_ocupada; i++)             /*ACESSANDO ESPAÇO MEMÓRIA INVÁLIDO: mudar linha_ocupada e coluna_ocupada*/
            for(j = 0; j < m->coluna_ocupada; j++)
                m->matriz[i][j] = matriz_aux[i][j];
        for(i = 0; i < m->linha_alocada; i++)
            free(matriz_aux[i]);
        free(matriz_aux);
        m->linha_alocada *= 2;
    }
    m->linha_ocupada++;
}

void adiciona_coluna(dados_matriz m){                                           /*linhas correspondem aos livros*/
    int i, j, **matriz_aux;
    if(m->coluna_ocupada == m->coluna_alocada){
        matriz_aux = m->matriz;
        m->matriz = malloc(m->linha_alocada * sizeof(int*));
        if(m->matriz == NULL)
            exit (1);
        for(i = 0; i < m->linha_alocada; i++){
            m->matriz[i] = calloc(m->coluna_alocada*2, sizeof(int));
            if(m->matriz[i] == NULL)
                exit (1);
        }
        for(i = 0; i < m->linha_ocupada; i++)
            for(j = 0; j < m->coluna_ocupada; j++)
                m->matriz[i][j] = matriz_aux[i][j];
        for(i = 0; i < m->linha_alocada; i++)
            free(matriz_aux[i]);
        free(matriz_aux);
        m->coluna_alocada *= 2;
    }
    m->coluna_ocupada++;
}

void pedido(dados_matriz m, dados_vetor livros, dados_vetor universidades){
    char caracteres[41];
    int r, i, j, pos_uni, pos_liv, quant_livros, exemplares;
    scanf("%s %d", caracteres, &quant_livros);
    for(i = 0; i < universidades->ocupado; i++){
        r = strcmp(universidades->vetor[i].caracteres, caracteres);
        if(!r)
            break;
    }
    pos_uni = i;
    for(i = 1; i <= quant_livros; i++){
        scanf("%s %d", caracteres, &exemplares);
        for(j = 0; j < livros->ocupado; j++){
            r = strcmp(livros->vetor[j].caracteres, caracteres);
            if(!r)
                break;
        }
        pos_liv = j;
        m->matriz[pos_liv][pos_uni] += exemplares;
    }
}

int quant_livros_por_universidade(dados_matriz m, dados_vetor livros, dados_vetor universidades){
    char caracteres[41];
    int i, r, pos_uni, total;
    scanf("%s", caracteres);
    for(i = 0; i < universidades->ocupado; i++){
        r = strcmp(universidades->vetor[i].caracteres, caracteres);
        if(!r)
            break;
    }
    pos_uni = i;
    total = 0;
    for(i = 0; i < m->linha_ocupada; i++)
        total += m->matriz[i][pos_uni];
    return total;
}

int quant_universidades_por_livro(dados_matriz m, dados_vetor livros, dados_vetor universidades){
    char caracteres[41];
    int i, r, pos_liv, total;
    scanf("%s", caracteres);
    for(i = 0; i < livros->ocupado; i++){
        r = strcmp(livros->vetor[i].caracteres, caracteres);
        if(!r)
            break;
    }
    pos_liv = i;
    total = 0;
    for(i = 0; i < m->coluna_ocupada; i++)
        total += m->matriz[pos_liv][i];
    return total;
}

int total_livros(dados_matriz m){
    int total, i ,j;
    total = 0;
    for(i = 0; i < m->linha_ocupada; i++)
        for(j = 0; j < m->coluna_ocupada; j++)
            total += m->matriz[i][j];
    return total;
}

void apaga_matriz(dados_matriz m){
    int i;
    for(i = 0; i < m->linha_alocada; i++)
        free(m->matriz[i]);
    free(m->matriz);
    free(m);
}
