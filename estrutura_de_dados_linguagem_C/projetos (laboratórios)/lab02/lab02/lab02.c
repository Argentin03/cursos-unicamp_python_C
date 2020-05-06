/*Carlos Augusto Jardim Chiarelli 165685
Este arquivo é o cliente para manipulação das estruturas de dados de vetores e matrizes, contém o código que utiliza/chama as operações disponibilizadas ao cliente*/
#include "vetor.h"
#include "matriz.h"
#include <stdio.h>

int main (int argc, char* argv[]) {
    int escolha;
    dados_vetor livros, universidades;
    dados_matriz exemplares;
    livros = cria_vetor();
    universidades = cria_vetor();
    exemplares = cria_matriz();
    do{
        scanf("%d", &escolha);
        switch(escolha){
            case 1:{                                                  /*inserção de um livro*/
                adiciona_elemento_vetor(livros);
                adiciona_linha(exemplares);
                printf("Livro cadastrado com sucesso!\n");
                break;
            }
            case 2:{                                                 /*inserção de uma universidade*/
                adiciona_elemento_vetor(universidades);
                adiciona_coluna(exemplares);
                printf("Universidade cadastrada com sucesso!\n");
                break;
            }
            case 3:{                                                 /*executa um pedido*/
                pedido(exemplares, livros, universidades);
                printf("Pedido registrado!\n");
                break;
            }
            case 4:{                                                  /*quantidade de livros por universidade*/
                printf("%d\n", quant_livros_por_universidade(exemplares, livros, universidades));
                break;
            }
            case 5:{                                                  /*quantidade de universidades por livro*/
                printf("%d\n", quant_universidades_por_livro(exemplares, livros, universidades));
                break;
            }
            case 6:{                                                    /*quantidade total de livros*/
                printf("%d\n", total_livros(exemplares));
                break;
            }
        }
    }while(escolha != 0);
    apaga_vetor(livros);
    apaga_vetor(universidades);
    apaga_matriz(exemplares);
    printf("Sistema encerrado.\n");
    return 0;
}
