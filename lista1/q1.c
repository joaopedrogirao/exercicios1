#include <stdio.h>

int main(){
    unsigned int n;
    
    puts("Escreva um número decimal: ");
    scanf("%u", &n);
    
    
    printf("Valor em octal: %o\n", n);
    printf("Valor em hexadecimal: %x\n", n);
   


    return 0;

}