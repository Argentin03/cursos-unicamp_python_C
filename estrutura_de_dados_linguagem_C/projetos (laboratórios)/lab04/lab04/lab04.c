/*Carlos Augusto Jardim Chiarelli 165685
Este arquivo é o cliente para manipulação das estruturas de dados de listas circulares duplamente ligadas, contém o código que utiliza/chama as operações disponibilizadas ao cliente*/

#include "lista.h"
#include <stdio.h>

int main (int argc, char* argv[]) {
    int escolha;
    p_proc processos;
    processos = cria_proc();
    do{
        scanf("%d", &escolha);
        switch(escolha){
            case 1:{                                                  /*inserção de um processo*/
                processos = insere_proc(processos);
                break;
            }
            case 2:{                                                 /*remoção de um processo*/
                processos = remove_proc(processos);
                break;
            }
            case 3:{                                                 /*impressão de uma lista de processos*/
                /*imprime_proc(processos);*/
                imprime_recursivo(processos, processos->ant);
                printf("\n");
                break;
            }
            case 4:{                                                  /*priorizar um processo*/
                processos = prioriza_proc(processos);
                break;
            }
            case 5:{                                                  /*executar um processo*/
                processos = executa_proc(processos);
                break;
            }
        }
    }while(escolha != 0);
    if(processos != NULL)
        apaga_recursivo(processos, processos->ant);
    printf("Sistema encerrado.\n");
    return 0;
}
