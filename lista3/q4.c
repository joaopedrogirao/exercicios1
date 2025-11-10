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

    int iguais = 1;
    for(int i = 0; str1[i] != '\0' || str2[i] !='\0'; i++){

        if(str1[i] != str2[i]){
            iguais = 0;
            break;
        }

}
        if(iguais){
            puts("As strings são iguais");
        }else{
            puts("As strings são diferentes");
        }
        
    
return 0;




}