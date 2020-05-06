/*Carlos Augusto Jardim Chiarelli 165685
Este arquivo é a interface da estrutura de dados para listas circulares duplamentes ligadas, contém o tipo abstrato de dados (struct) utilizado e os protótipos das funções que serão disponibilizadas ao cliente*/

typedef struct processo{               /*1 processo = 1 nó*/
    int id, duracao;
    struct processo *prox;
    struct processo *ant;
}processo;

typedef processo * p_proc;

p_proc cria_proc();

p_proc insere_proc(p_proc processos);

p_proc remove_proc(p_proc processos);

void imprime_proc(p_proc processos);

p_proc prioriza_proc(p_proc processos);

p_proc executa_proc(p_proc processos);

void apaga_proc(p_proc processos);

void imprime_recursivo(p_proc ini, p_proc ant);

void apaga_recursivo(p_proc ini, p_proc ant);
