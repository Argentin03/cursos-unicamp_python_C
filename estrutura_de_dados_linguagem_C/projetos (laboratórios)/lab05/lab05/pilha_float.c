/*Carlos Augusto Jardim Chiarelli 165685
Este arquivo contém a implementação da interface para pilhas com vetores, ou seja, o conjunto de algoritmos que realizarão as operações disponibilizadas ao cliente*/


#include "pilha_float.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

p_pilha_float cria_pilha_float(){
    p_pilha_float novo;
    novo = malloc(sizeof(Pilha_float));
    if(novo == NULL)
        exit(1);
    novo->topo = 0;
    return novo;
}

void empilhar_float(p_pilha_float pilha, float num){
    pilha->v[pilha->topo] = num;
    pilha->topo++;
}

float desempilhar_float(p_pilha_float pilha){
    pilha->topo--;
    return pilha->v[pilha->topo];
}

void destroi_pilha_float(p_pilha_float pilha){
    free(pilha);
}

float calcula_pos_fixa(p_pilha_float pilha){
    float op1, op2;
    char s[15];
    scanf("%s", s);
    while(strcmp(s, "=") != 0){
        if(atof(s) == 0){
            op1 = desempilhar_float(pilha);
            op2 = desempilhar_float(pilha);
            switch(s[0]){
                case '+':{
                    op2 += op1;
                    break;
                }
                case '-':{
                    op2 -= op1;
                    break;
                }
                case '*':{
                    op2 *= op1;
                    break;
                }
                case '/':{
                    op2 /= op1;
                    break;
                }
            }
            empilhar_float(pilha, op2);
        }else
            empilhar_float(pilha, atof(s));
        scanf("%s", s);
    }
    return desempilhar_float(pilha);
}
