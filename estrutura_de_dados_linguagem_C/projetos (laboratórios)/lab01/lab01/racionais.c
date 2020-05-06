/*Carlos Augusto Jardim Chiarelli 165685
Este arquivo contém a implementação da interface, ou seja, o conjunto de algoritmos que realizarão as operações disponibilizadas ao cliente*/

#include "racionais.h"
#include <stdio.h>
#include <stdlib.h>

int mmc(int num1, int num2){                    /*esta função calcula o mmc*/
    int i, dividiu, resto1, resto2, mmc;
    mmc = 1;
    if(num1 < 0)
        num1 *= -1;
    if(num2 < 0)
        num2 *= -1;
    while((num1 != 1) || (num2 != 1)){
        for(i = 2, dividiu = 0; !dividiu; i++){
            resto1 = num1 % i;
            resto2 = num2 % i;
            if((resto1 == 0) && (resto2 == 0)){
                num1 /= i;
                num2 /= i;
                mmc *= i;
                dividiu = 1;
            }else if(resto1 == 0){
                num1 /= i;
                mmc *= i;
                dividiu = 1;
            }else if(resto2 == 0){
                num2 /= i;
                mmc *= i;
                dividiu = 1;
            }
        }
    }
    return mmc;
}

racional racional_cria(){                                    /*cria um número racional sem valores*/
    racional novo = malloc(sizeof(racional_struct));
    if(novo == NULL)
        exit (1);
    return novo;
}

racional racional_le(){                                      /*lê um número racional desejado pelo cliente*/
    racional lido = racional_cria();
    scanf("%d %d", &lido->num, &lido->den);
    return lido;
}

racional racional_simplifica(racional rac){
    int i, dividiu, resto1, resto2;
    i = 1;
    if(rac->num == 0)
        rac->den = 1;
    else while(rac->den != 1 && i <= rac->den){
        for(i = 2, dividiu = 0; !dividiu && i <= rac->den; i++){
            resto1 = rac->num % i;
            resto2 = rac->den % i;
            if(resto1 == 0 && resto2 == 0){
                rac->num /= i;
                rac->den /= i;
                dividiu = 1;
                i--;
            }
        }
    }
    if(rac->den < 0){
        rac->den *= -1;
        rac->num *= -1;
    }
    return rac;
}

racional racional_adiciona(racional rac1, racional rac2){
    racional soma = racional_cria();
    soma->den = mmc(rac1->den, rac2->den);
    soma->num = ((soma->den / rac1->den) * rac1->num) + ((soma->den / rac2->den) * rac2->num);
    return racional_simplifica(soma);
}

racional racional_subtrai(racional rac1, racional rac2){
    rac2->den *= -1;
    return racional_adiciona(rac1, rac2);
}

racional racional_multiplica(racional rac1, racional rac2){
    rac1->den *= rac2->den;
    rac1->num *= rac2->num;
    if(rac1->den < 0){
        rac1->den *= -1;
        rac1->num *= -1;
    }
    return racional_simplifica(rac1);
}

racional racional_divide(racional rac1, racional rac2){
    int aux;
    if(rac2->den < 0){                                  /*para o sinal ficar no denominador quando inverter*/
        rac2->den *= -1;
        rac2->num *= -1;
    }
    aux = rac2->num;                                    /*aqui invertemos o número*/
    rac2->num = rac2->den;
    rac2->den = aux;
    return racional_multiplica(rac1, rac2);
}

void racional_imprime(racional rac){
    printf("%d/%d\n", rac->num, rac->den);
}

int racional_compara(racional rac1, racional rac2){             /*compara dois números racionais*/
    double valor1, valor2;
    valor1 = (double)rac1->num / rac1->den;
    valor2 = (double)rac2->num / rac2->den;
    if(valor1 > valor2)
        return 1;
    else if(valor1 == valor2)
        return 0;
    else
        return -1;
}
