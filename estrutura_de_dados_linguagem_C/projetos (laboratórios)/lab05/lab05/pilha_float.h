/*Carlos Augusto Jardim Chiarelli 165685
Este arquivo é a interface da estrutura de dados para pilhas com vetores, contém o tipo abstrato de dados (struct) utilizado e os protótipos das funções que serão disponibilizadas ao cliente*/

typedef struct{
    float v[141];                      
    int topo;
}Pilha_float;

typedef Pilha_float * p_pilha_float;

p_pilha_float cria_pilha_float();

void empilhar_float(p_pilha_float pilha, float num);

float desempilhar_float(p_pilha_float pilha);

void destroi_pilha_float(p_pilha_float pilha);

float calcula_pos_fixa(p_pilha_float pilha);
