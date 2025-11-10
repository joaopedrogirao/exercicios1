#include <stdio.h>
#include <string.h>
#define TAM 30
int main(){
    puts("Digite a primera string:");
    char str1[TAM*2];
    fgets(str1, TAM*2, stdin);
    str1[strcspn(str1, "\n")] = '\0';

    puts("Digite a segunda string:");
    char str2[TAM];
    fgets(str2, TAM, stdin);
    str2[strcspn(str2, "\n")] = '\0';

    strcat(str1, str2);
    printf("%s", str1);
    
return 0;




}