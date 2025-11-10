/*Escreva um programa que copie uma string para outra usando ponteiros.*/
#include <stdio.h>
#include <string.h>
#define TAM 30
int main(){
    
    puts("Digite uma string");
    char str[TAM];
    fgets(str, TAM, stdin);
    str[strcspn(str, "\n")] = '\0';

    char strc[TAM];
    char *p = str;
    char *pc = strc;

    while((*pc++ = *p++) != '\0'){

    }

    printf("String inicial: %s\n", str);


    printf("String cópia: %s", strc);

    return 0;





}