#include <stdio.h>
#define TAM 5

void testar_int() {
    int vetor[TAM];
    int *p = vetor;
    
    puts("\n--- Teste com Tipo: int ---");
    puts("Digite 5 números inteiros:");
    
    for(int i = 0; i < TAM; i++){
        printf("Vetor[%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    puts("\nResultados (int):");
    for(int i = 0; i < TAM; i++){
        printf("Endereço: %p | Vetor[%d] = %d\n", (void *)(p + i), i, vetor[i]);
    }
}

void testar_char() {
    char vetor[TAM];
    char *p = vetor;
    
    puts("\n--- Teste com Tipo: char ---");
    puts("Digite 5 caracteres:");
    
    for(int i = 0; i < TAM; i++){
        printf("Vetor[%d]: ", i);
        scanf(" %c", &vetor[i]);
    }

    puts("\nResultados (char):");
    for(int i = 0; i < TAM; i++){
        printf("Endereço: %p | Vetor[%d] = %c\n", (void *)(p + i), i, vetor[i]);
    }
}

void testar_double() {
    double vetor[TAM];
    double *p = vetor;
    
    puts("\n--- Teste com Tipo: double ---");
    puts("Digite 5 números decimais:");
    
    for(int i = 0; i < TAM; i++){
        printf("Vetor[%d]: ", i);
        scanf("%lf", &vetor[i]);
    }

    puts("\nResultados (double):");
    for(int i = 0; i < TAM; i++){
        printf("Endereço: %p | Vetor[%d] = %.2f\n", (void *)(p + i), i, vetor[i]);
    }
}

int main() {
    testar_int();
    testar_char();
    testar_double();
    
    return 0;
}