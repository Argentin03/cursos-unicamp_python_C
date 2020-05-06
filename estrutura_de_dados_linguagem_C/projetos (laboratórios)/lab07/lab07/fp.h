#ifndef FP_H
#define FP_H

/* Definição da estrutura No, que será utilizada para criar uma árvore binária.
 * */
typedef struct No{
  char simbolo;
  int freq;
  struct No *esq, *dir;
} No;

/* Define um alias para um ponteiro de No */
typedef No * p_no;

/* Define a estrutura de heap para implementar a fila de prioridade */
typedef struct {
  p_no *v;
  int n, tamanho;
} FP;

/* Define um alieas para um ponteiro de FP */
typedef FP* p_fp;

/* Cria a fila de prioridade, alocando o espaço necessário de acordo com o
 * parâmetro tam. Retorna um ponteiro para FP. */
p_fp fp_cria(int tam);

/* Libera a toda a memória alocada para FP. Não libera a memória dos nós
 * contidos na FP. */
void fp_destroi(p_fp);

/* Insere um ponteiro para No na fila de prioridades. O ponteiro para No
 * recebido deve ter sido alocado dinamicamente. */
void fp_insere(p_fp fp, p_no item);

/* Retorna um ponteiro para o nó que possui menor número de ocorrência dentre
 * os nós que foram inseridos na fila de prioridade. A memória dos ponteiros
 * retornados deve ser desalocada pelo usuário.*/
p_no fp_extrai_minimo(p_fp fp);

/* Retorna a quantidade de elementos contidos na fila de prioridade */
int fp_tamanho(p_fp fp);

/* Funções auxiliares da utilizadas na implementação da fila de prioridades */
void sobe_no_heap(p_fp, int k);
void desce_no_heap(p_fp, int k);
void troca(p_no* v1, p_no* v2);

#endif
