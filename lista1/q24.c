#include <stdio.h>
int main(){
    unsigned int segundos;

    puts("Digite o tempo em segundos");
    scanf("%u", &segundos);

    unsigned int horas = segundos / 3600;
    unsigned int minutos = (segundos % 3600) / 60;
    segundos = segundos % 60;

    printf("%uh %um %us", horas, minutos, segundos);

    return 0;

}