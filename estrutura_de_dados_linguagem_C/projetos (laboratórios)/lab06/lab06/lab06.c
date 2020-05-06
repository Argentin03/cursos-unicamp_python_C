/*Carlos Augusto Jardim Chiarelli 165685
Este arquivo é o cliente para manipulação das estruturas de dados para heap de mínimos inteiros, contém o código que utiliza/chama as operações disponibilizadas ao cliente*/
#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int tamanho_heap;
    p_heap heap_min;
    scanf("%d", &tamanho_heap);
    heap_min = criar_heap_min(tamanho_heap);
    absorve_dados_vetores(heap_min);
    intercala(heap_min);
    destroi_heap_min(heap_min);
    printf("\n");
    return 0;
}
