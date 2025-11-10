/*Escreva um programa que busque um caractere fornecido em uma string utilizando ponteiros.*/


#include <stdio.h>
#include <string.h>
#define TAM 30
int main(){

    char str[TAM];
    fgets(str, TAM, stdin);
    str[strcspn(str, "\n")] = '\0';

    char *p = str;
    char c;
    char *pc = &c;
    scanf(" %c", pc);
    int encontrado = 0;

    while(*p != '\0'){

        if(*p == *pc){
            encontrado = 1;
            break;
        }
        p++;
    }

    if(encontrado){
        puts("Caractere encontrado");
    }else{
        puts("Caractere não encontrado");
    }
return 0;

}