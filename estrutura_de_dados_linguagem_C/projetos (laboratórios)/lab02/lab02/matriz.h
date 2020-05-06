/*Carlos Augusto Jardim Chiarelli 165685
Este arquivo é a interface da estrutura de dados para matrizes, contém o tipo abstrato de dados (struct) utilizado e os protótipos das funções que serão disponibilizadas ao cliente*/
#include "vetor.h"

typedef struct{
    int **matriz;
    int linha_ocupada, linha_alocada, coluna_ocupada, coluna_alocada;
}dados_matriz_struct;

typedef dados_matriz_struct * dados_matriz;

dados_matriz cria_matriz();

void adiciona_linha(dados_matriz matriz);                                            /*linhas correspondem aos livros*/

void adiciona_coluna(dados_matriz matriz);                                           /*colunas correspondem as universidades*/

void pedido(dados_matriz m, dados_vetor livros, dados_vetor universidades);

int quant_livros_por_universidade(dados_matriz m, dados_vetor livros, dados_vetor universidades);

int quant_universidades_por_livro(dados_matriz m, dados_vetor livros, dados_vetor universidades);

int total_livros(dados_matriz m);

void apaga_matriz(dados_matriz m);
