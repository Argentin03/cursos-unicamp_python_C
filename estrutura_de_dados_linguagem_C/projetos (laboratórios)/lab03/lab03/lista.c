/*Carlos Augusto Jardim Chiarelli 165685
Este arquivo contém a implementação da interface para listas ligadas, ou seja, o conjunto de algoritmos que realizarão as operações disponibilizadas ao cliente*/

#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

p_base cria_genoma(){
    return NULL;
}

void apaga_genoma(p_base genoma){
    if(genoma != NULL){
        apaga_genoma(genoma->prox);
        free(genoma);
    }
}

void imprime_genoma(p_base genoma){
    p_base atual;
    for(atual = genoma; atual != NULL; atual = atual->prox)
        printf("%c ", atual->letra);
    printf("\n");
}

p_base inverte_sequencia(p_base genoma, int ini, int fim){
    int i = 1;                                                /*o PRIMEIRO nó é 1, o SEGUNDO é 2, o TERCEIRO é 3...*/
    p_base inicio, ant, final, novo_ini, novo_fim, aux;
    for(inicio = genoma; i < ini; i++, inicio = inicio->prox);
    i = 1;
    for(final = genoma; i < fim; i++, final = final->prox);
    novo_ini = final->prox;
    novo_fim = inicio;
    for(aux = inicio; aux != final->prox; aux = aux->prox)
        printf("%c ", aux->letra);
    printf("- ");
    imprime_contrario(inicio, final);
    printf("\n");
    while(inicio != novo_ini){
        ant = inicio;
        inicio = ant->prox;
        ant->prox = final;
        final = ant;
    }
    if(ini == 1){
        novo_fim->prox = novo_ini;
        return final;
    }else{
        novo_fim->prox = novo_ini;
        for(novo_ini = genoma; novo_ini->prox != novo_fim; novo_ini = novo_ini->prox);
        novo_ini->prox = final;
        return genoma;
    }
}

p_base inverte_inicio(p_base genoma){
    int fim, ini = 1;
    scanf("%d", &fim);
    return inverte_sequencia(genoma, ini, fim);
}

p_base inverte_fim(p_base genoma){
    int tam, fim;
    p_base aux;
    scanf("%d", &tam);
    for(fim = 0, aux = genoma; aux != NULL; aux = aux->prox, fim++);
    tam = fim - tam + 1;
    return inverte_sequencia(genoma, tam, fim);
}

p_base adiciona_base(p_base genoma){
    int pos, i = 1;
    char caractere;
    p_base novo, aux;
    scanf(" %c %d", &caractere, &pos);
    printf("Nucleo-base adicionada na posicao %d da sequencia!\n", pos);
    novo = malloc(sizeof(Base));
    if(novo == NULL)
        exit(1);
    novo->letra = caractere;
    if(pos == 0){
        novo->prox = genoma;
        return novo;
    }else{
        for(aux = genoma; i < pos ; i++, aux = aux->prox);
        novo->prox = aux->prox;
        aux->prox = novo;
        return genoma;
    }
}

void transpoe_genoma(p_base genoma){
    int i, ini, fim, mov;
    p_base ini_buraco, fim_buraco, ant_buraco, pos_buraco, ant_adc, pos_adc, aux;
    scanf(" %d %d %d", &ini, &fim, &mov);
    for(i = 1, ant_buraco = genoma; i < ini; i++, ant_buraco = ant_buraco->prox);
    ini_buraco = ant_buraco->prox;
    for(i = 0, fim_buraco = genoma; i < fim; i++, fim_buraco = fim_buraco->prox);
    pos_buraco = fim_buraco->prox;
    for(aux = ini_buraco; aux != pos_buraco; aux = aux->prox)
        printf("%c ", aux->letra);
    if(mov != 0){
        if(mov > 0){
            for(i = 0, ant_adc = genoma; i < fim + mov; i++, ant_adc = ant_adc->prox);
            pos_adc = ant_adc->prox;
            printf("> %d\n", mov);
        }else{
            for(i = 1, ant_adc = genoma; i < ini + mov; i++, ant_adc = ant_adc->prox);
            pos_adc = ant_adc->prox;
            mov *= -1;
            printf("< %d\n", mov);
        }
        ant_buraco->prox = pos_buraco;
        ant_adc->prox = ini_buraco;
        fim_buraco->prox = pos_adc;
    }else
        printf("> 0\n");
}

p_base remove_base(p_base genoma){
    int pos, i;
    p_base aux, apagar;
    scanf(" %d", &pos);
    if(pos == 0){
        apagar = genoma;
        genoma = genoma->prox;
    }else{
        for(i = 0, aux = genoma; i < pos - 1; i++, aux = aux->prox);
        apagar = aux->prox;
        aux->prox = aux->prox->prox;
    }
    free(apagar);
    printf("Nucleo-base da posicao %d removida!\n", pos);
    return genoma;
}

void imprime_contrario(p_base ini, p_base fim){
    if(ini != fim)
        imprime_contrario(ini->prox, fim);
    printf("%c ", ini->letra);
}
