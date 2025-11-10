#include <stdio.h>
#include <string.h>
#define TAM 30

int main(){

    char str[TAM];
    fgets(str, TAM, stdin);
    str[strcspn(str, "\n")] = '\0';

    char *p = str;
    char *pfim;
    int tamanho;
    
    
    pfim = p;
    while(*pfim != '\0'){
        pfim++;
    }
    
    tamanho = (int)(pfim - p);

    printf("%s - Tamanho: %d",str, tamanho);
    return 0;
}