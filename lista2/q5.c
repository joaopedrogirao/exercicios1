#include <stdio.h>
int main(){
    int n, maior;

    puts("Digite um número");
    scanf("%d", &n);
    maior = n;

    while(n){ 
    maior = (n > maior) ? n : maior;
    printf("O maior número até agora é %d\n", maior);
    puts("Digite outro número");
    scanf("%d", &n);

    }
    printf("O maior número digitado foi %d\n", maior);
    return 0;
}