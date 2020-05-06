/*Carlos Augusto Jardim Chiarelli 165685
Este arquivo contém a implementação da interface para pilhas com lista ligada, ou seja, o conjunto de algoritmos que realizarão as operações disponibilizadas ao cliente*/

#include "pilha_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

p_pilha_caracteres cria_pilha_caracteres(){
    p_pilha_caracteres novo;
    novo = malloc(sizeof(Pilha_caracteres));
    if(novo == NULL)
        exit(1);
    novo->topo = NULL;
    return novo;
}

void empilhar_caracteres(p_pilha_caracteres pilha, char *s){
    p_no novo;
    novo = malloc(sizeof(No));
    if(novo == NULL)
        exit(1);
    strcpy(novo->s, s);
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

char* desempilhar_caracteres(p_pilha_caracteres pilha){
    char *p_s;
    p_no topo;
    p_s = malloc(141*sizeof(char));
    if(p_s == NULL)
        exit(1);
    topo = pilha->topo;
    strcpy(p_s, topo->s);
    pilha->topo = pilha->topo->prox;
    free(topo);
    return p_s;
}

void libera_desempilhado(char* desempilhado){
    free(desempilhado);
}



void converte_infixa_posfixa(){
    p_pilha_caracteres pilha;
    char *aux_s, s[15];
    aux_s = NULL;
    pilha = cria_pilha_caracteres();
    scanf("%s", s);
    while(strcmp(s, "=") != 0){
        if(atof(s) == 0){              /*se não é número faça...*/
            if(s[0] != ')')
                empilhar_caracteres(pilha, s);
            else{
                do{
                    if(aux_s != NULL)
                        libera_desempilhado(aux_s);
                    aux_s = desempilhar_caracteres(pilha);
                    if(aux_s[0] != '(')
                        printf("%c ", aux_s[0]);
                }while(aux_s[0] != '(');
            }
        }else
            printf("%s ", s);
        scanf("%s ", s);
    }
    printf("\n");
    destroi_pilha_caracteres(pilha);
}

void converte_posfixa_infixa(){
    p_pilha_caracteres pilha;
    char *aux_s1, *aux_s2, s[15], abre_parent[2], fecha_parent[2], abre_parent_aux[141];
    int i;
    aux_s1 = NULL;
    aux_s2 = NULL;
    pilha = cria_pilha_caracteres();
    abre_parent[0] = '(';
    abre_parent[1] = '\0';
    fecha_parent[0] = ')';
    fecha_parent[1] = '\0';
    strcpy(abre_parent_aux, abre_parent);
    scanf("%s", s);
    while(strcmp(s, "=") != 0){
        if(atof(s) == 0){                     /*se não é número faça...*/
            abre_parent_aux[1] = '\0';
            if(aux_s1 != NULL)
                libera_desempilhado(aux_s1);
            if(aux_s2 != NULL)
                libera_desempilhado(aux_s2);
            aux_s1 = desempilhar_caracteres(pilha);
            aux_s2 = desempilhar_caracteres(pilha);
            strcat(abre_parent_aux, aux_s2);
            strcat(abre_parent_aux, s);
            strcat(abre_parent_aux, aux_s1);
            strcat(abre_parent_aux, fecha_parent);
            empilhar_caracteres(pilha, abre_parent_aux);
        }else
            empilhar_caracteres(pilha, s);
        scanf("%s", s);
    }
    aux_s1 = desempilhar_caracteres(pilha);
    for(i = 0; aux_s1[i] != '\0'; i++){
        if(aux_s1[i] != '(' && aux_s1[i] != ')' && aux_s1[i] != '+' && aux_s1[i] != '-' && aux_s1[i] != '*' && aux_s1[i] != '/'){
            printf("%c", aux_s1[i]);
            if(aux_s1[i + 1] == '(' || aux_s1[i + 1] == ')' || aux_s1[i + 1] == '+' || aux_s1[i + 1] == '-' || aux_s1[i + 1] == '*' || aux_s1[i + 1] == '/')
                printf(" ");
        }else{
            printf("%c ", aux_s1[i]);
        }
    }
    printf("\n");
    if(aux_s1 != NULL)
        libera_desempilhado(aux_s1);
    destroi_pilha_caracteres(pilha);
}

void destroi_pilha_caracteres(p_pilha_caracteres pilha){
    if(pilha->topo != NULL)
        destroi_lista(pilha->topo);
}

void destroi_lista(p_no lista){
    if(lista != NULL)
        destroi_lista(lista->prox);
    free(lista);
}
