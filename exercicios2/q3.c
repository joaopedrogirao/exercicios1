#include <stdio.h>
int main(){

    unsigned long int fatorial = 1;
    unsigned int f;
    puts("Digite um número para calcular o fatorial: ");
    scanf("%u", &f);

    if (f < 0){
        puts("Fatorial não definido.");
        
    }else{
    for (unsigned int i = 1; i <= f; i++){
        fatorial *= i;
    }
    printf("O fatorial de %u é %lu\n", f, fatorial);
    
      }
    return 0;
}