#include <stdio.h>
int main(){

    int dia = 0;
    while (dia < 1 || dia > 7){
        puts("Digite um dia (1-7): ");
        scanf("%d", &dia);

        switch (dia){
            case 1:
                puts("Domingo");
                break;
            case 2:
                puts("Segunda-feira");
                break;
            case 3:
                puts("Terca-feira");
                break;
            case 4:
                puts("Quarta-feira");
                break;
            case 5:
                puts("Quinta-feira");
                break;
            case 6:
                puts("Sexta-feira");
                break;
            case 7:
                puts("Sábado");
                break;
            default:
                puts("Dia inválido, tente novamente.");
        }

return  0;


}

}