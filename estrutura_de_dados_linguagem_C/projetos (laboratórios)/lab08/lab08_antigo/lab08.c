/*Carlos Augusto Jardim Chiarelli 165685
Este arquivo é o cliente para manipulação das estruturas de dados para uma árvore quaternária que realiza busca bidimensional, contém o código que utiliza/chama as operações disponibilizadas ao cliente*/

#include <stdlib.h>
#include <stdio.h>
#include "arvore_quaternaria.h"

int main (int argc, char* argv[]){
  int escolha, dimensao_x, dimensao_y;
  p_no raiz;
  scanf("%d %d", &dimensao_x, &dimensao_y);
  raiz = criar_arvore(dimensao_x, dimensao_y);
  do{
    scanf("%d", &escolha);
    switch(escolha){
      case 1:{                          /*adicionar ponto*/
        raiz = adiciona_ponto(raiz);
        break;
      }
      case 2:{
        raiz = remove_ponto(raiz);           /*remover ponto*/
        break;
      }
      case 3:{                          /*buscar ponto*/
        busca_ponto_cliente(raiz);
        break;
      }
      case 4:{                          /*busca regiao*/
        busca_regiao_cliente(raiz);
        printf("\n");
        break;
      }
      case 5:{                           /*imprime arvore*/
        imprime_arvore(raiz);
        printf("\n");
        break;
      }
    }
  }while(escolha != 0);
  destroi_arvore(raiz);
  printf("Sistema encerrado.");
  return 0;
}
