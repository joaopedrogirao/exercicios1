#include <stdio.h>

int main(){
    
    float altura;
    
    puts("Digite sua altura em metros: ");
    scanf("%f", &altura); 

    int sexo;
    puts("Escolha seu sexo (1) para masculino (2) para feminino: ");
    scanf(" %d", &sexo);
    
    switch(sexo){
        case 1:
        printf("Seu peso ideal é %.2f", altura * 72.7 - 58);
        break;
        case 2:    
        printf("Seu peso ideal é %.2f", altura * 62.1 - 44.7);
        break;
    default:
        puts("Valor inválido");
        break;
        
    }


    }

