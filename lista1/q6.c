#include <stdio.h>

int main() {
    int horas, minutos, segundos;
    int tsegundos;

    puts("Digite a quantidade de horas: ");
    scanf("%d", &horas);

    puts("Digite a quantidade de minutos: ");
    scanf("%d", &minutos);

    puts("Digite a quantidade de segundos: ");
    scanf("%d", &segundos);

    tsegundos = (horas * 3600) + (minutos * 60) + segundos;

    printf("Total em segundos: %d\n", tsegundos);

    return 0;
}
