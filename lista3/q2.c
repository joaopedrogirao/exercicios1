#include <stdio.h>
#include <string.h>
#define TAM 30
int main(){

        puts("Digite uma string:");
        char str[TAM];
        fgets(str, TAM, stdin);

        puts("Digite uma letra:");
        char carac;
        scanf(" %c", &carac);

        int encontrou = 0;
        for(int i = 0; i < TAM; i++){
            if(str[i] == carac){
                encontrou = 1;
        }
        }
        
        if(encontrou){
            printf("A string tem a letra %c", carac);
        }else{
            printf("A string não tem a letra %c", carac);
        }
        
        
        return 0;

}