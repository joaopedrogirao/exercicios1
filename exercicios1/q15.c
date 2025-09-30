#include <stdio.h>
int main(){

    float valoraula, inss, salariob, salariol;
    int horastrabalhadas;

    puts("Digite o valor da hora aula: ");
    scanf("%f", &valoraula);

    puts("Digite a quantidade de horas trabalhadas: ");
    scanf("%d", &horastrabalhadas);

    puts("Digite o valor do percentual do INSS: ");
    scanf("%f", &inss);

    salariob = valoraula * horastrabalhadas;
    salariol = salariob - (salariob * (inss / 100));

    printf("O salário líquido é: R$%.2f", salariol);

    return 0;




}