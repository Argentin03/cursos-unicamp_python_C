/*Carlos Augusto Jardim Chiarelli 165685
Este arquivo é a interface da estrutura de dados, contém o tipo abstrato de dados (struct) utilizado e os protótipos das funções que serão disponibilizadas ao cliente*/

typedef struct{
    int num, den;
}racional_struct;

typedef racional_struct* racional;

int mmc(int num1, int num2);

racional racional_cria();

racional racional_le();

racional racional_adiciona(racional rac1, racional rac2);

void racional_imprime(racional rac);

racional racional_subtrai(racional rac1, racional rac2);

racional racional_multiplica(racional rac1, racional rac2);

racional racional_divide(racional rac1, racional rac2);

racional racional_simplifica(racional rac);

int racional_compara(racional rac1, racional rac2);
