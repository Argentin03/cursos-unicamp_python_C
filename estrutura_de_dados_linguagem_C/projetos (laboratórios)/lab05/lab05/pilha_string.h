/*Carlos Augusto Jardim Chiarelli 165685
Este arquivo é a interface da estrutura de dados para pilhas com lista ligada, contém o tipo abstrato de dados (struct) utilizado e os protótipos das funções que serão disponibilizadas ao cliente*/

typedef struct No{
    char s[141];
    struct No *prox;
}No;

typedef No * p_no;

typedef struct{
    p_no topo;
}Pilha_caracteres;

typedef Pilha_caracteres * p_pilha_caracteres;

p_pilha_caracteres cria_pilha_caracteres();

void empilhar_caracteres(p_pilha_caracteres pilha, char *s);

char* desempilhar_caracteres(p_pilha_caracteres pilha);

void destroi_pilha_caracteres(p_pilha_caracteres pilha);

void destroi_lista(p_no lista);

void converte_infixa_posfixa();

void converte_posfixa_infixa();

void libera_desempilhado(char* desempilhado);
