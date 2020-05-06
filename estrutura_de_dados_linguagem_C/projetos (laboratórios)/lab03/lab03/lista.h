/*Carlos Augusto Jardim Chiarelli 165685
Este arquivo é a interface da estrutura de dados para listas ligadas, contém o tipo abstrato de dados (struct) utilizado e os protótipos das funções que serão disponibilizadas ao cliente*/

typedef struct Base{               /*1 base = 1 nó*/
    char letra;
    struct Base *prox;
}Base;

typedef Base * p_base;

p_base cria_genoma();                                                  /*o GENOMA inteiro corresponde à LISTA*/

void apaga_genoma(p_base genoma);

p_base adiciona_base(p_base genoma);

void imprime_genoma(p_base genoma);

p_base inverte_inicio(p_base genoma);

p_base inverte_fim(p_base genoma);

p_base inverte_sequencia(p_base genoma, int ini, int fim);            /*função que inverte (iterativamente) de fato */

void transpoe_genoma(p_base genoma);                       

p_base remove_base(p_base genoma);

void imprime_contrario(p_base ini, p_base fim);
