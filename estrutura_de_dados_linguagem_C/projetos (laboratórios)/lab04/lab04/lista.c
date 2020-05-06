/*Carlos Augusto Jardim Chiarelli 165685
Este arquivo contém a implementação da interface para listas circulares duplamente ligadas, ou seja, o conjunto de algoritmos que realizarão as operações disponibilizadas ao cliente*/

#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

p_proc cria_proc(){
    p_proc novo = NULL;
    return novo;
}

p_proc insere_proc(p_proc processos){
    int i, pos;
    p_proc novo, aux;
    novo = malloc(sizeof(processo));
    if(novo == NULL)
        exit (1);
    scanf(" %d %d %d", &novo->id, &novo->duracao, &pos);
    printf("Processo %d requisitado com duracao de %d ciclo(s)!\n", novo->id, novo->duracao);
    if(processos == NULL){
        novo->ant = novo;
        novo->prox = novo->ant;
        return novo;
    }else{
        aux = processos;
        for(i = 0; i < pos; i++){
            aux = aux->prox;
        }
        novo->prox = aux;
        novo->ant = aux->ant;
        novo->ant->prox = novo;
        novo->prox->ant = novo;
        if(pos == 0)
            return novo;
        else
            return processos;
    }
}

p_proc remove_proc(p_proc processos){   /*ESSA FUNÇÃO VOID FUNCIONA POR SER VOID????, pois o ponteiro está sendo passado por cópia. Pergunta: devo colocar '*' no parâmetro e utulizar o ponteiro com '&'? */
    int i, ID;
    p_proc aux;
    scanf(" %d", &ID);
    printf("Processo %d removido!\n", ID);
    if(processos == processos->prox){
        free(processos);
        return NULL;
    }else{
        for(aux = processos, i = 0; aux->id != ID; i++, aux = aux->prox);
        if(i == 0)
            processos = aux->prox;
        aux->prox->ant = aux->ant;
        aux->ant->prox = aux->prox;
        free(aux);
        return processos;
    }
}

void imprime_proc(p_proc processos){                   /*imprime iterativamente*/
    p_proc aux;
    printf("(%d,%d) ", processos->id, processos->duracao);
    for(aux = processos->prox; aux != processos; aux = aux->prox)
        printf("(%d,%d) ", aux->id, aux->duracao);
    printf("\n");
}

void imprime_recursivo(p_proc ini, p_proc ant){   /*quando passar como parâmetro, ant == ini->ant */
    if(ant != ini)
        imprime_recursivo(ini, ant->ant);
    printf("(%d,%d) ", ant->id, ant->duracao);
}

p_proc prioriza_proc(p_proc processos){
    int i, ID;
    p_proc aux;                                     /*aux é o nó (processo) a ser priorizado*/
    scanf(" %d", &ID);
    i = 0;
    for(aux = processos; aux->id != ID; aux = aux->prox){
        i++;
    }
    if(i != 0){
        aux->prox->ant = aux->ant;
        aux->ant->prox = aux->prox;
        aux->prox = processos;
        aux->ant = processos->ant;
        processos->ant->prox = aux;
        processos->ant = aux;
    }
    printf("Priorizando o processo %d!\n", ID);
    return aux;
}

p_proc executa_proc(p_proc processos){
    int i, ciclos;
    p_proc aux;
    scanf(" %d", &ciclos);
    for(i = 1; i <= ciclos && processos != NULL; i++){
        processos->duracao--;
        if(processos->duracao == 0){
            if(processos->prox == processos){
                free(processos);
                processos = NULL;
            }else{
                processos->ant->prox = processos->prox;
                processos->prox->ant = processos->ant;
                aux = processos;
                processos = processos->prox;
                free(aux);
            }
        }else
            processos = processos->prox;
    }
    if(processos == NULL)
        printf("Todos os processos terminaram!\n");
    else{
        imprime_recursivo(processos, processos->ant);
        printf("\n");
        /*imprime_proc(processos);*/
    }
    return processos;
}

void apaga_proc(p_proc processos){           /*apaga iterativamente*/
    p_proc aux;
    aux = processos->ant->ant->ant->prox;   /*aux aponta para o penúltimo processo (nó) da lista dupla*/
    do{
        free(aux->prox);
        aux = aux->ant;
    }while(aux != processos->prox);
    free(processos->prox);
    free(processos);
}

void apaga_recursivo(p_proc ini, p_proc ant){           /*apaga recursivamente*/
    if(ant != ini)
        apaga_recursivo(ini, ant->ant);
    free(ant);
}
