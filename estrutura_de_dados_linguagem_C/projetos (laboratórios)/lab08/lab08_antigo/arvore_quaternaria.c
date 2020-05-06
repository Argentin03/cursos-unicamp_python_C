/*Carlos Augusto Jardim Chiarelli 165685
Este arquivo é a implementação da estrutura de dados de uma árvore quaternária que realiza busca bidimensional*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "arvore_quaternaria.h"

p_no criar_arvore(int dimensao_x, int dimensao_y){               /* iniciamos a árvore como sendo um nó interno */
  int i;                                                        /* com o ponto central do espaço total, que contém */
  p_no novo;                                                    /* 4 filhos vazios */
  novo = (p_no)malloc(sizeof(No));
  if(novo == NULL)
    exit(1);
  novo->x = dimensao_x / 2;           /*aqui atualizamos o ponto central do quadrante*/
  novo->y = dimensao_y / 2;
  novo->tipo = 0;
  for(i = 0; i < 4; i++){                                /*aqui criamos os filhos do nó interno*/
    novo->filhos[i] = (p_no)malloc(sizeof(No));
    novo->filhos[i]->tipo = 2;
  }
  return novo;
}

p_no procura_ponto(p_no raiz, int Px, int Py){      /*fazemos a busca por ponto iterativamente, sempre retornando*/
  while(raiz->tipo == 0)                            /*um nó folha vazio ou com conteúdo*/
    if(Px < raiz->x){
      if(Py >= raiz->y)
        raiz = raiz->filhos[0];
      else
        raiz = raiz->filhos[2];
    }else{
      if(Py >= raiz->y)
        raiz = raiz->filhos[1];
      else
        raiz = raiz->filhos[3];
    }
  return raiz;
}

p_no adiciona_ponto(p_no raiz){
  p_no novo;
  novo = (p_no)malloc(sizeof(No));
  if(novo == NULL)
    exit(1);
  scanf("%d %d %s", &novo->x, &novo->y, novo->dado);
  novo->tipo = 1;
  printf("Ponto %s adicionado com coordenadas (%d,%d).\n", novo->dado, novo->x, novo->y);
  return adiciona_ponto_rec(raiz, raiz, novo);
}

p_no adiciona_ponto_rec(p_no raiz, p_no cabeca, p_no novo){
  if(raiz->tipo == 0){
    if(novo->x < raiz->x){
      if(novo->y >= raiz->y)
        raiz->filhos[0] = adiciona_ponto_rec(raiz->filhos[0], cabeca, novo);
      else
        raiz->filhos[2] = adiciona_ponto_rec(raiz->filhos[2], cabeca, novo);
    }else{
      if(novo->y >= raiz->y)
        raiz->filhos[1] = adiciona_ponto_rec(raiz->filhos[1], cabeca, novo);
      else
        raiz->filhos[3] = adiciona_ponto_rec(raiz->filhos[3], cabeca, novo);
    }
  }else if(raiz->tipo == 2){               /*caso seja uma folha sem conteúdo*/
    free(raiz);
    return novo;
  }else{
    raiz = (p_no)adiciona_no_interno(raiz, cabeca);
    raiz = adiciona_ponto_rec(raiz, cabeca, novo);
  }
  return raiz;
}

int encontra_filho(p_no pai, p_no filho){
  int i;
  for(i = 0; i < 4; i++)
    if(pai->filhos[i] == filho)
      break;
  return i;
}

p_no encontra_pai(p_no filho, p_no raiz){
  p_no pai;
  while(raiz->tipo == 0)
    if(filho->x < raiz->x){
      if(filho->y >= raiz->y){
        pai = raiz;
        raiz = raiz->filhos[0];
      }else{
        pai = raiz;
        raiz = raiz->filhos[2];
      }
    }else{
      if(filho->y >= raiz->y){
        pai = raiz;
        raiz = raiz->filhos[1];
      }else{
        pai = raiz;
        raiz = raiz->filhos[3];
      }
    }
  return pai;
}

p_no adiciona_no_interno(p_no raiz, p_no cabeca){      /*precisamos descobrir o "raio do ponto central do quandrante a ser inserido"*/
  int i, quadrante_filho, nivel_no_filho, extremo_quadrante = cabeca->x;
  p_no novo, pai;
  novo = (p_no)malloc(sizeof(No));
  if(novo == NULL)
    exit(1);
  novo->tipo = 0;
  for(i = 0; i < 4; i++){                                             /*aqui adicionamos um novo nó interno*/
    novo->filhos[i] = (p_no)malloc(sizeof(No));
    novo->filhos[i]->tipo = 2;
  }
  pai = encontra_pai(raiz, cabeca);
  nivel_no_filho = nivel_no(raiz, cabeca);
  quadrante_filho = encontra_filho(pai, raiz);
  for(i = 0; i < nivel_no_filho; i++)
    extremo_quadrante /= 2;
  if(quadrante_filho == 0){                                                       /*aqui atualizamos a ponto central do novo nó*/
    novo->x = pai->x - extremo_quadrante;
    novo->y = pai->y + extremo_quadrante;
  }else if(quadrante_filho == 1){
    novo->x = pai->x + extremo_quadrante;
    novo->y = pai->y + extremo_quadrante;
  }else if(quadrante_filho == 2){
    novo->x = pai->x - extremo_quadrante;
    novo->y = pai->y - extremo_quadrante;
  }else{
    novo->x = pai->x + extremo_quadrante;
    novo->y = pai->y - extremo_quadrante;
  }
  if(raiz->x < novo->x){                                           /*aqui colocamos os nó filho em seu nó interno*/
    if(raiz->y >= novo->y){
      free(novo->filhos[0]);
      novo->filhos[0] = raiz;
    }else{
      free(novo->filhos[2]);
      novo->filhos[2] = raiz;
    }
  }else{
    if(raiz->y >= novo->y){
      free(novo->filhos[1]);
      novo->filhos[1] = raiz;
    }else{
      free(novo->filhos[3]);
      novo->filhos[3] = raiz;
    }
  }
  pai->filhos[quadrante_filho] = novo;
  return novo;
}

p_no remove_ponto(p_no raiz){
  int x, y;
  scanf("%d %d", &x, &y);
  return remove_ponto_rec(raiz, raiz, x, y);
}

int filhos_conteudo(p_no pai){                 /*retorna -1 caso tenha mais de um filhos com conteúdo, mas caso*/
  int i, indice, quant_filhos_conteudo = 0;    /*tenha apenas um filho retorna o índice deste*/
  for(i = 0; i < 4; i++){
    if(pai->filhos[i]->tipo == 1){
      indice = i;
      quant_filhos_conteudo++;
    }else if(pai->filhos[i]->tipo == 0)
      break;
  }
  return quant_filhos_conteudo == 1 ? indice : -1;
}

p_no remove_ponto_rec(p_no raiz, p_no cabeca, int Px, int Py){
  int i, filho_conteudo;
  p_no aux;
  if(raiz->tipo == 0){
    if(Px < raiz->x){
      if(Py >= raiz->y)
        raiz->filhos[0] = remove_ponto_rec(raiz->filhos[0], cabeca, Px, Py);
      else
        raiz->filhos[2] = remove_ponto_rec(raiz->filhos[2], cabeca, Px, Py);
    }else{
      if(Py >= raiz->y)
        raiz->filhos[1] = remove_ponto_rec(raiz->filhos[1], cabeca, Px, Py);
      else
        raiz->filhos[3] = remove_ponto_rec(raiz->filhos[3], cabeca, Px, Py);
    }
  }else if(raiz->tipo == 1 && raiz->x == Px && raiz->y == Py){
    raiz->tipo = 2;
    printf("Ponto %s removido!\n", raiz->dado);
    return raiz;
  }
  if(raiz != cabeca && filhos_conteudo(raiz) != -1){  /*voltamos na recursão "arrumando a árvore caso a remoção"*/
    filho_conteudo = filhos_conteudo(raiz);
    aux = raiz->filhos[filho_conteudo];        /*gere pais que tenham apenas um filho com conteúdo*/
    for(i = 0; i < 4; i++)
      if(i != filho_conteudo)
        free(raiz->filhos[i]);
    free(raiz);
    return aux;
  }
  return raiz;
}

void imprime_arvore_rec(p_no raiz){
  if(raiz->tipo == 0){
    printf("I; ");
    imprime_arvore_rec(raiz->filhos[0]);
    imprime_arvore_rec(raiz->filhos[1]);
    imprime_arvore_rec(raiz->filhos[2]);
    imprime_arvore_rec(raiz->filhos[3]);
  }else if(raiz->tipo == 2)
    printf("V; ");
  else{
    printf("%s (%d,%d); ", raiz->dado, raiz->x, raiz->y);
  }
}

void imprime_arvore(p_no raiz){
  if(raiz->filhos[0]->tipo != 2 || raiz->filhos[1]->tipo != 2 || raiz->filhos[2]->tipo != 2 || raiz->filhos[3]->tipo != 2){
    if(filhos_conteudo(raiz) != -1)
      printf("%s (%d,%d); ", raiz->filhos[filhos_conteudo(raiz)]->dado, raiz->filhos[filhos_conteudo(raiz)]->x, raiz->filhos[filhos_conteudo(raiz)]->y);
    else
      imprime_arvore_rec(raiz);
  }
}

void destroi_arvore(p_no raiz){
  if(raiz->tipo == 0){
    destroi_arvore(raiz->filhos[0]);
    destroi_arvore(raiz->filhos[1]);
    destroi_arvore(raiz->filhos[2]);
    destroi_arvore(raiz->filhos[3]);
  }
  free(raiz);
}

void busca_regiao_cliente(p_no raiz){
  int x, y, raio;
  scanf("%d %d %d", &x, &y, &raio);
  procura_regiao_rec(raiz, x, y, raio);
}

void procura_regiao_rec(p_no raiz, int Px, int Py, int raio){
  if(raiz->tipo == 0){
    procura_regiao_rec(raiz->filhos[0], Px, Py, raio);
    procura_regiao_rec(raiz->filhos[1], Px, Py, raio);
    procura_regiao_rec(raiz->filhos[2], Px, Py, raio);
    procura_regiao_rec(raiz->filhos[3], Px, Py, raio);
  }
  if(raiz->tipo == 1){
    if(distancia(Px, Py, raiz->x, raiz->y) <= raio)
      printf("%s ", raiz->dado);
  }
}

void busca_ponto_cliente(p_no raiz){
  int Px, Py;
  p_no encontrado;
  scanf("%d %d", &Px, &Py);
  encontrado = procura_ponto(raiz, Px, Py);
  if(encontrado->tipo == 1 && encontrado->x == Px && encontrado->y == Py)
    printf("%s\n", encontrado->dado);
}

int distancia(int x1, int y1, int x2, int y2){
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int nivel_no(p_no no, p_no raiz){
  int i;
  for(i = 0; raiz->tipo == 0; i++){
    if(no->x < raiz->x){
      if(no->y >= raiz->y)
        raiz = raiz->filhos[0];
      else
        raiz = raiz->filhos[2];
    }else{
      if(no->y >= raiz->y)
        raiz = raiz->filhos[1];
      else
        raiz = raiz->filhos[3];
    }
  }
  return i;
}
