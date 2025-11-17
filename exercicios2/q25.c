#include <stdio.h>
#include <math.h>
int main(){
    int n;
    puts("Digite a quantidade de termos:");
    scanf("%d", &n);
    double soma = 0;
    double termo;
    for(int i = 0; i < n; i++){
        termo = pow((-1), i) / (2 * i + 1);
        soma += termo;
    }

    printf("Valor de pi = %f", soma * 4);
    return 0;
}