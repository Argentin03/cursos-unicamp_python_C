/*Carlos Augusto Jardim Chiarelli 165685
Este arquivo é a interface da estrutura de dados para um heap de mínimos inteiros, contém o tipo abstrato de dados (struct) utilizado e os protótipos das funções que serão disponibilizadas ao cliente*/

typedef struct{
    int *numeros;
    int tamanho, ini;
}Vetor;

typedef struct{
    Vetor *v;
    int n, tamanho;
}HEAP;

typedef HEAP * p_heap;

p_heap criar_heap_min(int tam);

void insere(p_heap heap_min, Vetor vetor);

void destroi_heap_min(p_heap heap_min);

void intercala(p_heap heap_min);

void sobe_no_heap(p_heap heap_min, int k);

void desce_no_heap(p_heap heap_min, int k);

void troca(Vetor *a, Vetor *b);

void absorve_dados_vetores(p_heap heap_min);
