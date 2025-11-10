#include <stdio.h>
#include <string.h>
#define TAM 30
int main(){
    char str[TAM];
    puts("Digite uma string:");
    fgets(str, TAM, stdin);

    str[strcspn(str, "\n")] = '\0';

    unsigned k = 0;
    while(str[k] != '\0'){
        k++;
    }

    printf("A quantidade de caracteres de %s é: %u",str, k);

    return 0;





}