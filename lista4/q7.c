#include <stdio.h>
#include <string.h>
#define TAM 30

int main(){
    puts("Digite a primeira string:");
    char str1[TAM];
    fgets(str1, TAM, stdin);
    str1[strcspn(str1, "\n")] = '\0';

    puts("Digite a segunda string:");
    char str2[TAM];
    fgets(str2, TAM, stdin);
    str2[strcspn(str2, "\n")] = '\0';

    char *p1 = str1;
    char *p2 = str2;
    char strg[TAM*2];
    char *p3 = strg;
    while((*p3++ = *p1++) != '\0'){

    }
    p3--;
    
    while((*p3++ = *p2++) != '\0'){

    }



printf("%s", strg);
    
    
return 0;

}