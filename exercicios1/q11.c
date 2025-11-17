#include <stdio.h> 
int main(){

    int n1, n2;

    puts("Digite o primeiro número: ");
    scanf("%d", &n1);

    puts("Digite o segundo número: ");
    scanf("%d", &n2);

    printf("A soma desses números é: %d\n o produto é: %d\n a diferença é: %d\n o quociente é: %d\n o resto é: %d", n1 + n2, n1 * n2, n1 - n2, n1 / n2, n1 % n2);

    return 0;



}


