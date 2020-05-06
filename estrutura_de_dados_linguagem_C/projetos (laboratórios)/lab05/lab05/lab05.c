/*Carlos Augusto Jardim Chiarelli 165685
Este arquivo é o cliente para manipulação das estruturas de dados de pilhas, contém o código que utiliza/chama as operações disponibilizadas ao cliente*/

#include "pilha_string.h"
#include "pilha_float.h"
#include <stdio.h>

int main (int argc, char* argv[]) {
    int escolha;
    p_pilha_float pilha_float;
    pilha_float = cria_pilha_float();
    do{
        scanf("%d", &escolha);
        switch(escolha){
            case 1:{                                                  /*avalia pós-fixa e calcula*/
                printf("%.4f\n", calcula_pos_fixa(pilha_float));
                break;
            }
            case 2:{                                                  /*converte infixa para pós-fixa*/
                converte_infixa_posfixa();
                break;
            }
            case 3:{                                                  /*converte pós-fixa para infixa*/
                converte_posfixa_infixa();
                break;
            }
        }
    }while(escolha != 0);
    destroi_pilha_float(pilha_float);
    printf("Sistema encerrado.");
    return 0;
}
