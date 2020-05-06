/*Carlos Augusto Jardim Chiarelli 165685
Este arquivo é a interface da estrutura de dados de uma árvore quaternária que realiza busca bidimensional*/

typedef struct No{
  char dado[20];
  int x, y;
  short tipo;               /*0: nó interno, 1: nó folha conteúdo, 2: nó folha vazio*/
  struct No * filhos[4];
}No;

typedef No * p_no;

p_no criar_arvore(int dimensao_x, int dimensao_y);

p_no procura_ponto(p_no raiz, int Px, int Py);

void busca_ponto_cliente(p_no raiz);

void busca_regiao_cliente(p_no raiz);

void procura_regiao_rec(p_no raiz, int Px, int Py, int raio);

p_no adiciona_ponto(p_no raiz);

p_no remove_ponto(p_no raiz);

p_no remove_ponto_rec(p_no raiz, p_no cabeca, int Px, int Py);

void destroi_arvore(p_no raiz);

void imprime_arvore(p_no raiz);

void imprime_arvore_rec(p_no raiz);

int distancia(int x1, int y1, int x2, int y2);

p_no encontra_pai(p_no filho, p_no raiz);

p_no adiciona_no_interno(p_no raiz, p_no cabeca);

int nivel_no(p_no no, p_no raiz);

p_no adiciona_ponto_rec(p_no raiz, p_no cabeca, p_no novo);

int encontra_filho(p_no pai, p_no filho);

int filhos_conteudo(p_no pai);
