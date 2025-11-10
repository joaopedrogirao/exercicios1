#include <stdio.h>
#include <string.h>
#define TAM 30

int main(){

    puts("Digite uma string:");
    char str[TAM];
    fgets(str, TAM, stdin);
    str[strcspn(str, "\n")] = '\0';

    int tamanho = strlen(str);
    for(int i = tamanho - 1; i >= 0; i--){

            printf("%c", str[i]);



        }


    
return 0;
    }


