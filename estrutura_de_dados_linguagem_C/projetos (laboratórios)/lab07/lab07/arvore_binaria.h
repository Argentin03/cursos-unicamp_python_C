/*Carlos Augusto Jardim Chiarelli 165685
Este arquivo é a interface da estrutura de dados para uma árvore binária que compacta e descompacta textos, contém o tipo abstrato de dados (struct) utilizado e os protótipos das funções que serão disponibilizadas ao cliente*/

#include "fp.h"

void absorve_frequencia_caracteres(int quant_tweets, p_fp fila_prio);

p_no criar_arvore(p_fp fila_prio);

void compactar_txt(p_no raiz);

void codifica_char(p_no raiz, char caractere, int bits, int* marcador);

void descompactar_txt(p_no raiz);

void decodifica_char(p_no raiz, int* indice, char* bits);

void destroi_arvore(p_no raiz);

void imprime_bits(int* vetor, int fim);
