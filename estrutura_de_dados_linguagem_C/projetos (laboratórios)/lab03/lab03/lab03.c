/*Carlos Augusto Jardim Chiarelli 165685
Este arquivo é o cliente para manipulação das estruturas de dados de listas simples, contém o código que utiliza/chama as operações disponibilizadas ao cliente*/

#include "lista.h"
#include <stdio.h>

int main (int argc, char* argv[]) {
    int escolha;
    p_base genoma;
    genoma = cria_genoma();
    do{
        scanf("%d", &escolha);
        switch(escolha){
            case 1:{                                                  /*inserção de uma base*/
                genoma = adiciona_base(genoma);
                break;
            }
            case 2:{                                                 /*remoção de uma base*/
                genoma = remove_base(genoma);
                break;
            }
            case 3:{                                                 /*inversão de um prefixo do DNA*/
                genoma = inverte_inicio(genoma);
                break;
            }
            case 4:{                                                  /*inversão de um sufixo do DNA*/
                genoma = inverte_fim(genoma);
                break;
            }
            case 5:{                                                  /*transpõe genoma*/
                transpoe_genoma(genoma);
                break;
            }
            case 6:{                                                    /*imprime genoma*/
                imprime_genoma(genoma);
                break;
            }
        }
    }while(escolha != 0);
    apaga_genoma(genoma);
    printf("Sistema encerrado.\n");
    return 0;
}
