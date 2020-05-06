/*Carlos Augusto Jardim Chiarelli 165685
Este arquivo contém a implementação da interface para um heap de mínimos inteiros, ou seja, o conjunto de algoritmos que realizarão as operações disponibilizadas ao cliente*/

#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

#define PAI(i) ((i-1)/2)
#define F_ESQ(i) (2*i+1)
#define F_DIR(i) (2*i+2)

p_heap criar_heap_min(int tam){
    p_heap heap_min;
    heap_min = malloc(sizeof(HEAP));
    if(heap_min == NULL)
        exit(1);
    heap_min->v = malloc(tam * sizeof(Vetor));
    if(heap_min->v == NULL)
        exit(1);
    heap_min->n = 0;
    heap_min->tamanho = tam;
    return heap_min;
}

void troca(Vetor *a, Vetor *b){
    Vetor aux = *a;
    *a = *b;
    *b = aux;
}

void insere(p_heap heap_min, Vetor vetor){
    int i;
    heap_min->v[heap_min->n] = vetor;
    heap_min->v[heap_min->n].numeros = malloc(heap_min->v[heap_min->n].tamanho * sizeof(int));
    if(heap_min->v[heap_min->n].numeros == NULL)
        exit(1);
    for(i = 0; i < heap_min->v[heap_min->n].tamanho; i++)
        scanf("%d", &heap_min->v[heap_min->n].numeros[i]);
    heap_min->n++;
    sobe_no_heap(heap_min, heap_min->n - 1);
}

void sobe_no_heap(p_heap heap_min, int k){
    if(k > 0 && heap_min->v[PAI(k)].numeros[heap_min->v[PAI(k)].ini] > heap_min->v[k].numeros[heap_min->v[k].ini]){
        troca(&heap_min->v[PAI(k)], &heap_min->v[k]);
        sobe_no_heap(heap_min, PAI(k));
    }
}

void desce_no_heap(p_heap heap_min, int k){
    int menor_filho;
    if(F_ESQ(k) < heap_min->n){
        menor_filho = F_ESQ(k);
        if(F_DIR(k) < heap_min->n && heap_min->v[F_ESQ(k)].numeros[heap_min->v[F_ESQ(k)].ini] > heap_min->v[F_DIR(k)].numeros[heap_min->v[F_DIR(k)].ini])
            menor_filho = F_DIR(k);
        if(heap_min->v[k].numeros[heap_min->v[k].ini] > (heap_min->v[menor_filho].numeros[heap_min->v[menor_filho].ini])){
            troca(&heap_min->v[k], &heap_min->v[menor_filho]);
            desce_no_heap(heap_min, menor_filho);
        }
    }
}

void absorve_dados_vetores(p_heap heap_min){
    int i;
    Vetor vetor_aux;
    vetor_aux.ini = 0;
    for(i = 1; i <= heap_min->tamanho; i++){
        scanf("%d", &vetor_aux.tamanho);
        insere(heap_min, vetor_aux);
    }
}

void destroi_heap_min(p_heap heap_min){
    int i;
    for(i = 0; i < heap_min->tamanho; i++)
        free(heap_min->v[i].numeros);
    free(heap_min->v);
    free(heap_min);
}

void intercala(p_heap heap_min){
    while(heap_min->n > 0){
        printf("%d ", heap_min->v[0].numeros[heap_min->v[0].ini]);
        heap_min->v[0].ini++;
        if(heap_min->v[0].ini == heap_min->v[0].tamanho){                   /*caso acabe o elemento do vetor da raiz*/
            troca(&heap_min->v[0], &heap_min->v[heap_min->n - 1]);    /*tiramos ele do heap_min*/
            heap_min->n--;
        }
        desce_no_heap(heap_min, 0);
    }
}
