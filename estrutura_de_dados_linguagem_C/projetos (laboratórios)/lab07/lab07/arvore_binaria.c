/*Carlos Augusto Jardim Chiarelli 165685
Este arquivo contém a implementação da interface para uma árvore binária que compacta e descompacta textos, ou seja, o conjunto de algoritmos que realizarão as operações disponibilizadas ao cliente*/

#include <stdlib.h>
#include <stdio.h>
#include "arvore_binaria.h"

#define MAX_TWEET 142
#define MAX_BITS 128
#define INI_ASCII 32
#define FIM_ASCII 126

void absorve_frequencia_caracteres(int quant_tweets, p_fp fila_prio){
  char tweet[MAX_TWEET];
  int i, j, histograma_caracteres[FIM_ASCII];
  for(i = INI_ASCII; i <= FIM_ASCII; i++)
    histograma_caracteres[i] = 0;
  for(i = 1; i <= quant_tweets; i++){
    fgets(tweet, 142, stdin);
    for(j = 0; tweet[j] != '\n'; j++)
      histograma_caracteres[(int)tweet[j]]++;
  }
  for(i = INI_ASCII; i <= FIM_ASCII; i++){
    p_no caractere = (p_no)malloc(sizeof(No));
    if(caractere == NULL)
      exit(1);
    caractere->esq = NULL;
    caractere->dir = NULL;
    caractere->simbolo = i;
    caractere->freq = histograma_caracteres[i];
    fp_insere(fila_prio, caractere);
  }
}

p_no criar_arvore(p_fp fila_prio){
  p_no pai;
  while(fila_prio->n > 1){
    pai = (p_no)malloc(sizeof(No));
    if(pai == NULL)
      exit(1);
    pai->esq = fp_extrai_minimo(fila_prio);
    pai->dir = fp_extrai_minimo(fila_prio);
    pai->freq = pai->esq->freq + pai->dir->freq;
    fp_insere(fila_prio, pai);
  }
  return fp_extrai_minimo(fila_prio);
}

void compactar_txt(p_no raiz){
  char tweet[MAX_TWEET];
  int i, bits_convertido[MAX_BITS];
  fgets(tweet, 142, stdin);
  for(i = 0; tweet[i] != '\n'; i++)
    codifica_char(raiz, tweet[i], 0, bits_convertido);
}

void codifica_char(p_no raiz, char caractere, int indice, int* bits_convertido){
  if(raiz->esq == NULL){
    if(raiz->simbolo == caractere)
      imprime_bits(bits_convertido, indice);
  }else{
    bits_convertido[indice] = 0;
    codifica_char(raiz->esq, caractere, indice + 1, bits_convertido);
    bits_convertido[indice] = 1;
    codifica_char(raiz->dir, caractere, indice + 1, bits_convertido);
  }
}

void imprime_bits(int* vetor, int fim){
  int i;
  for(i = 0; i < fim; i++)
    printf("%d", vetor[i]);
}

void descompactar_txt(p_no raiz){
  char caractere;
  p_no aux = raiz;
  do{
    scanf("%c", &caractere);
    if(aux->esq == NULL){
      printf("%c", aux->simbolo);
      aux = raiz;
    }
    if(caractere == '0')
      aux = aux->esq;
    else if(caractere == '1')
      aux = aux->dir;
  }while(caractere != '\n');
}

void destroi_arvore(p_no raiz){
  if(raiz){
    destroi_arvore(raiz->esq);
    destroi_arvore(raiz->dir);
    free(raiz);
  }
}
