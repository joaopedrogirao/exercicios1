#include <stdio.h>
int main(){
    int n;

    puts("Digite um número de 3 dígitos para inverte-lo:");
    scanf("%d", &n);

    int centena = n / 100;
    int dezena = (n / 10) % 10;
    int unidade = n % 10;

    int invertido = unidade * 100 + dezena * 10 + centena;

    printf("Número invertido: %d", invertido);



}