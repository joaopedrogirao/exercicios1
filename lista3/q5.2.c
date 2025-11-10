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

    char strg[TAM*2];
    int k = 0;
    for(int i = 0; str1[i] != '\0'; i++){
        strg[k] = str1[i];
        k++;

    }

    for(int i = 0; str2[i] != '\0'; i++){
        strg[k] = str2[i];
        k++;
    }
    strg[k] = '\0';    
    printf("%s", strg);

return 0;




}