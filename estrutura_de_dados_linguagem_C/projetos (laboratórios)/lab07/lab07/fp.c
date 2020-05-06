#include <stdlib.h>
#include <stdio.h>
#include "fp.h"

#define PAI(i) ((i-1)/2)
#define FILHO_ESQUERDO(i) (2*i+1)

p_fp fp_cria(int tam) {
  p_fp fp = malloc(sizeof(FP));
  fp->v = malloc(tam * sizeof(p_no));
  fp->n = 0;
  fp->tamanho = tam;
  return fp;
}

void fp_destroi(p_fp fp) {
  free(fp->v);
  free(fp);
}

int fp_tamanho(p_fp fp) {
  return fp->n;
}

void fp_insere(p_fp fp, p_no item) {
  fp->v[fp->n] = item;
  fp->n++;
  sobe_no_heap(fp, fp->n-1);
}

void sobe_no_heap(p_fp fp, int k) {
  if (k > 0 && fp->v[PAI(k)]->freq > fp->v[k]->freq) {
    troca(&fp->v[k], &fp->v[PAI(k)]);
    sobe_no_heap(fp, PAI(k));
  }
}

p_no fp_extrai_minimo(p_fp fp) {
  p_no item;
  troca(&fp->v[0], &fp->v[fp->n-1]);
  item = fp->v[fp->n-1];
  fp->n--;
  desce_no_heap(fp,0);
  return item;
}

void desce_no_heap(p_fp fp, int k) {
  int filho = FILHO_ESQUERDO(k);
  if (filho < fp->n) {
    if (filho < fp->n-1 && fp->v[filho]->freq > fp->v[filho+1]->freq)
      filho++;
    if (fp->v[k]->freq > fp->v[filho]->freq) {
      troca(&fp->v[k], &fp->v[filho]);
      desce_no_heap(fp, filho);
    }
  }
}

void troca(p_no* v1, p_no* v2) {
  p_no temp = *v1;
  *v1 = *v2;
  *v2 = temp;
}

