/*Carlos Augusto Jardim Chiarelli 165685
Este arquivo é a interface da estrutura de dados para vetores, contém o tipo abstrato de dados (struct) utilizado e os protótipos das funções que serão disponibilizadas ao cliente*/
#ifndef VETOR_H                /*fazemos isso para que não seja incluido a mesma biblioteca duas vezes*/
#define VETOR_H

typedef struct{
    char caracteres[41];
}nome;

typedef nome * nomes;

typedef struct{
    nomes vetor;
    int ocupado, alocado;
}dados_vetor_struct;

typedef dados_vetor_struct * dados_vetor;

dados_vetor cria_vetor();

void adiciona_elemento_vetor(dados_vetor v);

void apaga_vetor(dados_vetor vetor);


#endif                   /*fazemos isso para que não seja incluido a mesma biblioteca duas vezes*/
