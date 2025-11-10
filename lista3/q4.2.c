#include <stdio.h>
#include <string.h>
#define TAM 30
int main(){
    puts("Digite a primera string:");
    char str1[TAM];
    fgets(str1, TAM, stdin);
    str1[strcspn(str1, "\n")] = '\0';

    puts("Digite a segunda string:");
    char str2[TAM];
    fgets(str2, TAM, stdin);
    str2[strcspn(str2, "\n")] = '\0';

    int iguais = strcmp(str1, str2);
    if (iguais == 0){
        puts("As strings são iguais");
    }else{
        puts("As strings são diferentes");
    }
    
return 0;




}