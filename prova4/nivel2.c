#include <stdio.h>

struct horario{
    int hora;
    int minuto;
    int segundo;



    
};
void adicionarsegundos(struct horario *h, int s){
    h->segundo += s;

    int minutosextra = h->segundo / 60;
    h->segundo = h->segundo % 60;

    h->minuto += minutosextra;

    int horasextra = h->minuto / 60;
    h->minuto = h->minuto % 60;

    h->hora += horasextra;

    h->hora = h-> hora % 24;

}

int main(){

    struct horario agora;

    agora.hora = 10;
    agora.minuto = 20;
    agora.segundo = 10;

    int segundosadd;
    puts("Digite quantos segundos quer adicionar");
    scanf("%d", &segundosadd);



    adicionarsegundos(&agora ,segundosadd);

    printf("Hora: %d\nMinuto: %d\nSegundo: %d", agora.hora, agora.minuto, agora.segundo);

    return 0;



}