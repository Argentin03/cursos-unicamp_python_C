/*Carlos Augusto Jardim Chiarelli 165685
Este arquivo é o cliente para manipulação das estruturas de dados para uma árvore binária que compacta e descompacta textos, contém o código que utiliza/chama as operações disponibilizadas ao cliente*/

#include <stdlib.h>
#include <stdio.h>
#include "fp.h"
#include "arvore_binaria.h"

#define MAX_CARACTERES 95

int main (int argc, char* argv[]) {
  int escolha, quant_tweets;
  char c;
  p_fp fila_prio;
  p_no raiz;
  fila_prio = fp_cria(MAX_CARACTERES);
  scanf("%d", &quant_tweets);
  while((c = getchar()) != '\n' && c != EOF);
  absorve_frequencia_caracteres(quant_tweets, fila_prio);
  raiz = criar_arvore(fila_prio);
  fp_destroi(fila_prio);
  do{
    scanf("%d", &escolha);
    while((c = getchar()) != '\n' && c != EOF);
    switch(escolha){
      case 1:{
        compactar_txt(raiz);
        printf("\n");
        break;
      }
      case 2:{
        descompactar_txt(raiz);
        printf("\n");
        break;
      }
    }
  }while(escolha != 0);
  destroi_arvore(raiz);
  printf("Sistema encerrado.");
  return 0;
}
